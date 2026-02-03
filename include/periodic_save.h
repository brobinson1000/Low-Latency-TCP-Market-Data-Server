#pragma once

#include <unordered_map>
#include <string>
#include <thread>
#include "Order.h" 
#include "save_bin_snap.h"

void periodic_save(const std::unordered_map<int, Order>& orderbook, const std::string& filepath, int interval_minutes);

