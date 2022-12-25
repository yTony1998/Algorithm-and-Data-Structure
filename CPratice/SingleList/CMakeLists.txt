cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(SingleLists LANGUAGES CXX)

add_library(intSLList
    SHARED
        intSLList.hpp
        intSLList.cpp)

add_executable(SingleLists main.cpp)
target_link_libraries(SingleLists intSLList)