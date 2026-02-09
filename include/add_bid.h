#pragma once

#include "Order.h"
#include "get_next_orderid.h" 



void add_bid(double price, const char* title, uint16_t prob_basis_point, uint32_t trader_id, bool active,
unsigned char side);
