#include "delete_order.h"
#include "log_f.h"
#include "OrderBook.h"
#include <unordered_map>

void delete_order(int orderid) {
    auto it = orderbook.find(orderid);
    if (it != orderbook.end()) {
            orderbook.erase(it);
            log_f("Order deleted");
        } else {
            log_f("Order Not Found");
        }
};
