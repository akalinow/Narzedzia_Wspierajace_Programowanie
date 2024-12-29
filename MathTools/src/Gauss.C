#include "Gauss.h"
#include <iostream>
#include <cmath>

using std::cout, std::cerr;
using std::sqrt, std::exp, std::pow;

Gauss::Gauss (double a, double b, double _x0, double _s) 
            : Funkcja (a, b) , x0 (_x0) , sigma (_s) {
}

void Gauss::Status () {
  cout << "Funkcja Gaussa o parametrach: x0 = " << x0 << " , sigma = " << sigma;
  cout << "\n\t\t na przedziale [" << xmin << " : " << xmax << "]\n";
}

double Gauss::f (double x) {
  if (x < xmin || x > xmax) {
    cerr << "<Blad> x = " << x << " poza dziedzina\n"; 
    return NAN;
  }

  return 1. / sqrt( 2.*M_PI ) / sigma * exp(-0.5 * pow( (x-x0)/sigma , 2.) ) ;
}
