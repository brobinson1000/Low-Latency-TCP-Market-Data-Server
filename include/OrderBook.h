#pragma once

#include <string>
#include <unordered_map>
#include "Order.h"

extern std::unordered_map<int, Order> orderbook;

// Function declarations
void add_bid(double price, const char* title, uint16_t prob_basis_point, uint32_t trader_id, bool active, unsigned char side);
void resolve_bid(int id, bool win);
void print_orderbook(const std::unordered_map<int, Order>& orderbook);
void save_bin_snap(const std::unordered_map<int, Order>& orderbook, const std::string& filepath);
void replay_bin_snap(const std::unordered_map<int, Order>& orderbook, const std::string& filepath);
void periodic_save(const std::unordered_map<int, Order>& orderbook, const std::string& filepath, int interval_minutes);
void get_order(int orderid);
void delete_order(int orderid);
