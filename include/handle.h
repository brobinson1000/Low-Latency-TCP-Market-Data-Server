#pragma once

#include <boost/asio.hpp>

namespace boost::asio {
    class io_context;
}

using boost::asio::ip::tcp;

void handle_client(tcp::socket socket);

