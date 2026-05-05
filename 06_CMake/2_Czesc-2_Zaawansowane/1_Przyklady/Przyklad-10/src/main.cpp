#include <iostream>

#include "config.h"

int main()
{
    #ifdef ENABLE_FEATURE_X
        std::cout << "Funkcjonalność X aktywna!" << std::endl;
    #else
        std::cout << "Funkcjonalność X nieaktywna!" << std::endl;
    #endif

    #ifdef ENABLE_FEATURE_Y
        std::cout << "Funkcjonalność Y aktywna!" << std::endl;
    #else
        std::cout << "Funkcjonalność Y nieaktywna!" << std::endl;
    #endif

    std::cout << "VAR_1 = " << VAR_1 << std::endl;
    std::cout << "VAR_2 = " << VAR_2 << std::endl;

    return 0;
}