cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(helloword LANGUAGES CXX)

add_library(message
    SHARED
        Message.hpp
        Message.cpp)
add_executable(helloworld hello-world.cpp)
target_link_libraries(helloworld message)