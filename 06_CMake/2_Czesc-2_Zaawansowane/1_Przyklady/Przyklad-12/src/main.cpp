#include <iostream>
#include "config.h"

int main()
{
    std::cout << "Wersja Git: " << GIT_VERSION << std::endl;
    std::cout << "Wersja Python: " << PYTHON_VERSION << std::endl;

    return 0;
}