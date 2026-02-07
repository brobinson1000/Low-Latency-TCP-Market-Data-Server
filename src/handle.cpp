#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <mutex>
#include <add_bid.h>
#include <get_order.h>
#include <delete_order.h>
#include <resolve_bid.h>
#include <print_orderbook.h>
#include <OrderBook.h>
#include <handle.h>


using boost::asio::ip::tcp;


// orderbook_mutex obj to avoid data race on orderbook unordered_map
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

                
                // test
                std::cout << "Price: " << price << std::endl;
                std::cout << "Title: " << title << std::endl;
                std::cout << "Order ID: " << orderid << std::endl;
                std::cout << "Probability Basis Point: " << prob_basis_point << std::endl;
                std::cout << "Trader ID: " << trader_id << std::endl;
                std::cout << "Active: " << active << std::endl;
                std::cout << "Side: " << side << std::endl;
                
        
                {
                    std::lock_guard<std::mutex> lock(orderbook_mutex);
                    add_bid(price, title.c_str(), orderid, prob_basis_point, trader_id, active, static_cast<unsigned char>
                    (side));
                }
            }
    
            // TEST
            if (cmd == "PRINT") {
                std::lock_guard<std::mutex> lock(orderbook_mutex);
                print_orderbook(orderbook);
            }
            if (cmd == "GET_ORDER") {
                int orderid;

                iss >> orderid;
                get_order(orderid);
            }
            if (cmd == "DELETE_ORDER") {
                int orderid;
                iss >> orderid;
                {
                    std::lock_guard<std::mutex> lock(orderbook_mutex);
                    delete_order(orderid);
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
