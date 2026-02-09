#include "get_next_orderid.h"

static int orderid_counter = 0;

int get_next_orderid() {
    return orderid_counter++;  // Return current orderid, then increment
}

