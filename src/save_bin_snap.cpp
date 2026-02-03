#include "save_bin_snap.h"
#include "log_f.h"
#include <fstream>
#include <iostream>


void save_bin_snap(const std::unordered_map<int, Order>& orderbook,
                   const std::string& filepath)
{
    std::ofstream out(filepath, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "Failed to open snapshot file\n";
        return;
    }

    uint64_t count = orderbook.size();
    out.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (const auto& [id, o] : orderbook) {
        
        // write for every piece had to fix for unordered_map
        out.write(reinterpret_cast<const char*>(&o.price), sizeof(o.price));
        out.write(reinterpret_cast<const char*>(&o.orderid), sizeof(o.orderid));
        out.write(reinterpret_cast<const char*>(&o.prob_basis_point), sizeof(o.prob_basis_point));
        out.write(reinterpret_cast<const char*>(&o.trader_id), sizeof(o.trader_id));
        out.write(reinterpret_cast<const char*>(&o.active), sizeof(o.active));
        out.write(reinterpret_cast<const char*>(&o.side), sizeof(o.side));

        // write string
        uint64_t len = o.title.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(o.title.data(), len);
    }

    log_f("File closed and saved successfully");
}
