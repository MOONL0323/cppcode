cmake_minimum_required(VERSION 3.23)
project(template)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(template
        stacklist_notclass.cpp)
