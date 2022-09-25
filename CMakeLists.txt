cmake_minimum_required(VERSION 3.24.1)
project(OrderBookDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(OrderBook)
add_subdirectory(OrderBook)
add_subdirectory(OrderBookTests)

find_package(Boost 1.80.0)
# message(${Boost_INCLUDE_DIRS})
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(OrderBookDemo main.cpp)
target_link_libraries(OrderBookDemo PUBLIC OrderBook) # linking libary to exec to make function definitions available