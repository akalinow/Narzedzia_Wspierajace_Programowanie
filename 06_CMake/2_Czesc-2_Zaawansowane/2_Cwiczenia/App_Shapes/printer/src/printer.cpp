#include "printer.h"
#include <iostream>
#include <string>

using namespace Shapes;

void Printer::Print(std::string shape, double area)
{
    std::cout << shape << ": " << area << std::endl;
}