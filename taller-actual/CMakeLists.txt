cmake_minimum_required(VERSION 3.10)

project(TallerCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(twitter twitter.cpp)
add_executable(spreadsheet spreadsheet.cpp)
add_executable(robot robot.cpp)
add_executable(reinas reinas.cpp)
