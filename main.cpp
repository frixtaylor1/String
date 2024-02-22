#include "./src/String/String.hpp"

#include <iostream>

int main() {
    using namespace frix;
    // Utiliza StringAllocator para la asignación de memoria

    String str = "Hello, World!";
    String hello = "How are you?";
    std::cout << str << std::endl;
    std::cout << hello << std::endl;

    std::cout << &hello.m_str << std::endl;

    return 0;
}