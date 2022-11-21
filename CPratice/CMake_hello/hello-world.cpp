#include "Message.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
    Message say_hello("Hello, CMake World!");
    std::cout << say_hello <<std::endl;

    Message say_goodhello("Goodbye, CMake world!");
    std::cout << say_goodhello <<std::endl;
}