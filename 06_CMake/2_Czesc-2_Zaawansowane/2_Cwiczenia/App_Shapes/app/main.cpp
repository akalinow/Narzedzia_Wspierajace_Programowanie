#include "circle.h"
#include "square.h"
#include "printer.h"

using namespace Shapes;

int main()
{
    Printer p;

    Circle c;
    p.Print("Koło", c.Area(1));

    Square s;
    p.Print("Kwadrat", s.Area(3));

    return 0;
}