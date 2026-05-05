#include <iostream>
#include "lib.h"

using namespace CMakeExample;

int main()
{
    Lib lib;

    std::cout << lib.f1() << std::endl;
    std::cout << lib.f2() << std::endl;
    std::cout << lib.f3() << std::endl;
    std::cout << lib.f4() << std::endl;
    std::cout << lib.f5() << std::endl;

    std::cout << lib.g1() << std::endl;
    std::cout << lib.g2() << std::endl;
    std::cout << lib.g3() << std::endl;
    std::cout << lib.g4() << std::endl;
    std::cout << lib.g5() << std::endl;

    return 0;
}