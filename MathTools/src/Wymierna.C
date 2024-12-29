#include "Wymierna.h"
#include <iostream>
#include <cmath>

using std::cout, std::cerr;
using std::sqrt, std::exp, std::pow;

Wymierna::Wymierna (double _xmin, double _xmax, double _a, double _b, double _c, double _d) 
         : Funkcja (_xmin, _xmax) , a (_a) , b (_b) , c (_c) , d (_d) {
}

void Wymierna::Status () {
  cout << "Funkcja Wymierna y = (a+bx)/(c+dx) : a = " 
       << a << " , b = " << b << " , c = " << c << " , d = " << d ;
  cout << "\n\t\t na przedziale [" << xmin << " : " << xmax << "]\n";
}

double Wymierna::f (double x) {
  if (x < xmin || x > xmax) {
    cerr << "<Blad> x = " << x << " poza dziedzina\n"; 
    return NAN;
  }
  if (c + d*x == 0) {
    cerr << "<Blad> x = " << x << " poza dziedzina (asymptota pionowa)\n";
    return NAN;
  }

  return ( (a + b*x) / (c + d*x) ) ;
}

