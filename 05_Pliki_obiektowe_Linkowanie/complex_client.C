#include "complex.h"
using namespace std;

int main () {
  Complex A (1, 2), B (3, 4);
  Complex C = A.Add( B );
  C.Print();
  return 0;
}

