#include <iostream>

int main()
{
    std::cout << "Hello, CMake!" << std::endl;

    #ifdef FLAG1
    std::cout << "Kompilacja z flagą FLAG1." << std::endl;
    #endif

    #ifdef FLAG2
    std::cout << "Kompilacja z flagą FLAG2." << std::endl;
    #endif

    #ifdef FLAG3
    std::cout << "Kompilacja z flagą FLAG3." << std::endl;
    #endif

    return 0;
}