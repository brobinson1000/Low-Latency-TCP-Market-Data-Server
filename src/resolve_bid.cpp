#include "resolve_bid.h"
#include "log_f.h"
#include "OrderBook.h"
#include <unordered_map>

void resolve_bid(int id, bool win) {
    auto it = orderbook.find(id);
    if (it != orderbook.end()) {
        it->second.active = false;
        log_f("Bid Resolved Successfully");
    } else {
        log_f("Bid ID not found");
    }
}

