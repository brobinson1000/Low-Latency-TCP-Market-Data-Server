#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include "periodic_save.h"
#include "log_f.h"

void periodic_save(const std::unordered_map<int, Order>& orderbook, const std::string &filepath, int interval_minutes) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::minutes(interval_minutes));
        save_bin_snap(orderbook, filepath);
        log_f("Orderbook snapshot saved");
    }
};
