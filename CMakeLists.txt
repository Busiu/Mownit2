cmake_minimum_required(VERSION 3.10)
project(Mownit2)

##set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIR})

add_executable(Mownit2  Lab2/CubicInterpolation.cpp
                        Lab2/Enumerator.cpp
                        Lab2/IInterpolation.cpp
                        Lab2/LagrangeInterpolation.cpp
                        Lab2/LinearRegressor.cpp
                        Lab2/Templates.cpp
                        Lab2/main.cpp)

target_link_libraries(Mownit2 ${GSL_LIBRARIES})