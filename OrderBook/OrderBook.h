#pragma once
#include <map>
#include <iostream>
#include <boost/optional.hpp>


class OrderBook
{
    std::map<int, int> bids, asks; 
    void add(int price, int amount, bool bid);
public:
    void boo();

    struct BidAsk {
        typedef boost::optional<std::pair<int,int>> Entry;
        Entry bid, ask;
        boost::optional<int> spread() const;
    };
    
    bool is_empty() const;
    void add_bid(int price, int amount);
    void add_ask(int price, int amount);

    BidAsk get_bid_ask() const;

    friend std::ostream& operator<<(std::ostream& os, const OrderBook& book);
};