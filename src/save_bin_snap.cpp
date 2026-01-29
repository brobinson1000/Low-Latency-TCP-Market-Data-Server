#include "save_bin_snap.h"
#include "log_f.h"
#include <fstream>
#include <iostream>



void save_bin_snap(const std::vector<Order>& orderbook, const std::string& filepath) {
    std::ofstream out(filepath, std::ios::binary | std::ios::trunc);

    if(!out) {
        std::cerr << "Saved file not found";
    };


    uint64_t count = orderbook.size();
    out.write(reinterpret_cast<const char*>(&count), sizeof(count));
    out.write(reinterpret_cast<const char*>(orderbook.data()), count * sizeof(Order));
    out.close();
    log_f("File closed and saved successfully");
}

