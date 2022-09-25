#include "OrderBook.h"

void OrderBook::boo(){
        std::cout << "boo\n"; 
    }

bool OrderBook::is_empty() const{
        return bids.empty() && asks.empty();
    }

void OrderBook::add_bid(int price, int amount){    
    add(price, amount, true);
}

void OrderBook::add_ask(int price, int amount){
    add(price, amount, false);
}

void OrderBook::add(int price, int amount, bool bid) {
    if (bid)
        bids[price] += amount;
    else
        asks[price] += amount;
}


std::ostream& operator<<(std::ostream& os, const OrderBook& book){
    if (book.is_empty())
    {
        os << "ORDER BOOK IS EMPTY";
        return os;
    }

    for (auto it = book.asks.rbegin(); it != book.asks.rend(); ++it)
    {
        os << it->first << "\t" << it->second << std::endl;
    }
    os << std::endl;
    for (auto it = book.bids.rbegin(); it != book.bids.rend(); ++it)
    {
        os << it->first << "\t" << it->second << std::endl;
    }
    return os;
    
}

OrderBook::BidAsk OrderBook::get_bid_ask() const {
    BidAsk result;
    
    auto best_bid = bids.rbegin();
    if (best_bid != bids.rend())
        result.bid = *best_bid;

    auto best_ask = asks.rbegin();
    if (best_ask != asks.rend())
        result.ask = *best_ask;

    return result;
}

