#include <thread>
#include <iostream>
#include <version>
#include "OrderBook.h"
#include "log_f.h"
#include "handle.h"

#if !defined(__cpp_lib_jthread)
# error "This program requires C++20. Please enable C++20 support in compiler."
#endif

using boost::asio::ip::tcp;



std::vector<Order> orderbook;
std::mutex orderbook_mutex;

int main() {

    boost::asio::io_context io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8000));

    log_f("TCP Server running on port 8000\n");

    // Must fix this two while(true) thread bugs
   /* std::jthread save_thread(periodic_save, std::ref(orderbook), "ob.txt", 2);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    */


    while (true) {
        tcp::socket socket(io);
        acceptor.accept(socket);

        log_f("New client connected");

        std::thread(handle_client, std::move(socket)).detach();

    }

    return 0;
}

