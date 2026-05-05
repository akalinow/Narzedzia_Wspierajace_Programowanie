#include <iostream>

#include "cf_a.h"
#include "cf_b.h"

int main()
{
    std::cout << "Zmienne z pliku nagłówkowego cf_a.h: " << std::endl;
    std::cout << "   Wersja:     " << p9_version_A << std::endl;
    std::cout << "   var1:       " << var1 << std::endl;
    std::cout << "   source dir: " << project_source_dir << std::endl;
    std::cout << std::endl;

    std::cout << "Zmienne z pliku nagłówkowego cf_b.h: " << std::endl;
    std::cout << "   Wersja:     " << p9_version_B << std::endl;
    std::cout << "   var2:       " << var2 << std::endl;
    std::cout << "   binary dir: " << project_binary_dir << std::endl;
    return 0;
}