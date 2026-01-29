#include "resolve_bid.h"
#include "log_f.h"
#include "OrderBook.h"

void resolve_bid(int id, bool win) {
    for (auto& bet : orderbook) {
        if (bet.orderid == id) {
            bet.active = false;
            log_f("Bid Resolved Successfully");
        }
    }
}

