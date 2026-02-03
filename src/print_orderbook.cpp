#include "print_orderbook.h"
#include <iostream>
#include <unordered_map>

void print_orderbook(const std::unordered_map<int, Order>& orderbook) {

    const char* green = "\033[32m";
    const char* red = "\033[31m";
    const char* reset = "\033[0m";

    for (const auto& [id, order] : orderbook) {
        const char* color = order.active ? green : red;

        std::cout << reset << " | " << color << order.orderid << reset
                  << "\t | " << color << order.trader_id << reset
                  << "\t | " << color << order.price << reset
                  << "\t | " << color << order.prob_basis_point << reset
                  << "\t | " << color << static_cast<int>(order.side) << reset
                  << "\t | " << color << std::boolalpha << order.active << reset
                  << "\n";
    }
}

