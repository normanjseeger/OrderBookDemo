#include <gtest/gtest.h>
#include <OrderBook.h>


TEST(OrderBookTests, OrderBookEmptyByDefault){
    OrderBook book;
    EXPECT_TRUE(book.is_empty());
}


TEST(OrderBookTests, OrderAdditionWorks){
    OrderBook book;
    book.add_bid(123, 456);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456, bid.second);

}