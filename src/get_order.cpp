#include <iostream>

#include "get_order.h"
#include "log_f.h"
#include "OrderBook.h"

void get_order(int orderid) {
    auto it = orderbook.find(orderid);
    if (it != orderbook.end()) {
        const Order& o = it->second;
        std::cout << "OrderID: " << o.orderid
                  << " TraderID: " << o.trader_id
                  << " Price: " << o.price
                  << " Prob: " << o.prob_basis_point
                  << " Active: " << std::boolalpha << o.active
                  << " Side: " << static_cast<int>(o.side)
                  << " Title: " << o.title
                  << '\n';
        } else {
            log_f("Order Not Found");
        }
};

