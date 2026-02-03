#include "replay_bin_snap.h"
#include <fstream>
#include <iostream>





void replay_bin_snap(std::unordered_map<int, Order>& orderbook, const std::string& filepath)
{
    std::ifstream in(filepath, std::ios::binary);
    if (!in) {
        std::cerr << "Failed to open binary file\n";
        return;
    }

    uint64_t count = 0;
    in.read(reinterpret_cast<char*>(&count), sizeof(count));

    for (uint64_t i = 0; i < count; ++i) {
        Order o;

        in.read(reinterpret_cast<char*>(&o.price), sizeof(o.price));
        in.read(reinterpret_cast<char*>(&o.orderid), sizeof(o.orderid));
        in.read(reinterpret_cast<char*>(&o.prob_basis_point), sizeof(o.prob_basis_point));
        in.read(reinterpret_cast<char*>(&o.trader_id), sizeof(o.trader_id));
        in.read(reinterpret_cast<char*>(&o.active), sizeof(o.active));
        in.read(reinterpret_cast<char*>(&o.side), sizeof(o.side));

        // read string
        uint64_t len = 0;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));

        o.title.resize(len);
        in.read(o.title.data(), len);
        if (!in) { std::cerr << "Failed to read title data\n"; break; }

        // insert into unordered_map
        orderbook.emplace(o.orderid, std::move(o));
    }

    in.close();
}

