#include "complex.h"
#include <iostream>
using std::cout;

Complex::Complex (double _re, double _im) {
  re = _re;
  im = _im;
}

Complex Complex::Add (Complex& Z2) {
  Complex New (re + Z2.re , im + Z2.im) ;
  return New;  
}

void Complex::Print () {
  cout << "[Re : Im] = [" << re << " : " << im << "]\n";
}
