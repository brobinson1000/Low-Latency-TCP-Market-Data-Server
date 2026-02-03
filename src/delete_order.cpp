#include "delete_order.h"
#include "log_f.h"
#include "OrderBook.h"
#include <unordered_map>

void delete_order(int orderid) {
    auto it = orderbook.find(orderid);
    if ( it != orderbook.end()) {
        orderbook.erase(orderid);
    } else {
        log_f("Order not found");
    }
};

