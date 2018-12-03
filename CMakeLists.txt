cmake_minimum_required(VERSION 3.10)
project(Mownit2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIR})

add_executable(Mownit2          Lab6/main.cpp

                                Lab6/NumericIntegrator.cpp)

target_link_libraries(Mownit2 ${GSL_LIBRARIES})