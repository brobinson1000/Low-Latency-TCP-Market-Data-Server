#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <mutex>
#include <add_bid.h>
#include <resolve_bid.h>
#include <handle.h>

using boost::asio::ip::tcp;


// orderbook_mutex obj to avoid data race on orderbook vector
extern std::mutex orderbook_mutex;

void handle_client(tcp::socket socket) {
    try {
        boost::asio::streambuf buffer;

        while (true) {
            boost::asio::read_until(socket, buffer, '\n');

            std::istream is(&buffer);
            std::string line;
            std::getline(is, line);

            std::cout << "rECIEVED " << line << '\n';

            std::istringstream iss(line);
            std::string cmd;
            iss >> cmd;


            // Commands for server

            if (cmd == "ADD") {
                double price;
                std::string title;
                int orderid;
                uint16_t prob_basis_point;
                uint32_t trader_id;
                bool active;
                int side;

                iss >> price >> title >> orderid >> prob_basis_point >> trader_id >> active >> side;

                {
                    std::lock_guard<std::mutex> lock(orderbook_mutex);
                    add_bid(price, title.c_str(), orderid, prob_basis_point, trader_id, active, static_cast<unsigned char>
                    (side));
                }
            }

            else if (cmd  == "RESOLVE") {
                int orderid;
                bool success;

                iss >> orderid >> success;
    
                {
                    std::lock_guard<std::mutex> lock(orderbook_mutex);
                    resolve_bid(orderid, success);
                }
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << "Client disconnected: " << e.what() << '\n';
    }
}
