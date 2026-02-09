
cmake_minimum_required(VERSION 3.10)


project(TCP_KALSHI_OB_SERVER)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    /home/bdookie/Boost/boost_1_90_0
)



add_executable(main
    src/main.cpp
    src/add_bid.cpp
    src/print_orderbook.cpp
    src/resolve_bid.cpp
    src/save_bin_snap.cpp
    src/replay_bin_snap.cpp
    src/periodic_save.cpp
    src/log_f.cpp
    src/handle.cpp
    src/get_order.cpp
    src/delete_order.cpp
    src/get_next_orderid.cpp
)

target_link_libraries(main pthread)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

