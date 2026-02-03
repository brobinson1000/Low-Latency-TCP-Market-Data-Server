#pragma once

#include <string>
#include <unordered_map>
#include "Order.h"

void save_bin_snap(const std::unordered_map<int, Order>& orderbook, const std::string& filepath);


