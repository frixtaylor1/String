#include "./src/String/String.hpp"

#include <iostream>

int main()
{
    using namespace frix;
    // Utiliza StringAllocator para la asignación de memoria

    {
        String str72 = "How are you?";
        std::cout << str72 << std::endl;
    }

    String str73 = "Hello, World!!!";
    std::cout << str73 << std::endl;

    return 0;
}