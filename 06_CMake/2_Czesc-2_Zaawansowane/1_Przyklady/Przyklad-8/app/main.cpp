#include "lib1.h"
#include "lib2.h"
#include "lib3.h"

using namespace CMakeExample;

int main()
{
    Lib1 a;
    a.Print();

    Lib2 b;
    b.Print();

    Lib3 c;
    c.Print();

    return 0;
}