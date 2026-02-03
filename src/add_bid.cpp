#include "add_bid.h"
#include "OrderBook.h"
#include "log_f.h"
#include <string>

void add_bid(double price, const char* title, int orderid, uint16_t prob_basis_point,
             uint32_t trader_id, bool active, unsigned char side) 
{
    Order new_order;
    new_order.orderid = orderid;
    new_order.title = title;        
    new_order.price = price;
    new_order.prob_basis_point = prob_basis_point;
    new_order.trader_id = trader_id;
    new_order.active = active;
    new_order.side = side;

    // Insert into unordered_map using orderid as key
    auto result = orderbook.emplace(orderid, std::move(new_order));

    if (result.second) {
        log_f("New Order successfully added");
    } else {
        log_f("Order ID already exists, not added");
    }
}

