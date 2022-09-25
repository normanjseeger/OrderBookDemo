find_package(Boost 1.80.0)
# message(${Boost_INCLUDE_DIRS})
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()


add_library(OrderBook STATIC OrderBook.cpp)
target_include_directories(OrderBook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS}) # adding folder with include files
