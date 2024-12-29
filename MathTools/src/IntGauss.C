// g++ -std=c++17 -I/usr/include -c IntGauss.C

#include "IntGauss.h"
#include <gsl/gsl_sf_erf.h>
#include <iostream>
#include <cmath>

using std::cout, std::cerr;
using std::sqrt, std::exp, std::pow;

IntGauss::IntGauss (double a, double b, double _Norm, double _x0, double _s) 
         : Funkcja (a, b) , Norm (_Norm) , x0 (_x0) , sigma (_s) {
}

void IntGauss::Status () {
  cout << "Calka z funkcji Gaussa o parametrach: "
          "Norm = " << Norm << " , x0 = " << x0 << " , sigma = " << sigma;
  cout << "\n\t\t na przedziale [" << xmin << " : " << xmax << "]\n";
}

double IntGauss::f (double x) {
  if (x < xmin || x > xmax) {
    cerr << "<Blad> x = " << x << " poza dziedzina\n"; 
    return NAN;
  }
  double t = (x - x0) / sigma ;
  return Norm * (1. - gsl_sf_erf_Q (t)) ;
}
