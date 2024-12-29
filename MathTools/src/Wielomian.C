#include "Wielomian.h"

#include <iostream>
#include <cmath>

using std::cout, std::cerr, std::endl;
using std::sqrt;

Wielomian::Wielomian (double _xmin, double _xmax, vector<double> v) 
          : Funkcja (_xmin, _xmax) , par (v) {
}

void Wielomian::Status () {
  cout << "Wielomian y(x) = ";
  for (int i = 0; i < par.size(); i++) {
    cout << par.at(i) << " * x^" << i ;
    if (i < par.size() - 1)
      cout << " + ";
  }
  cout << "\n\t\t na przedziale [" << xmin << " : " << xmax << "]\n";
}

double Wielomian::f (double x) {
  if (x < xmin || x > xmax) {
    cerr << "<Blad> x = " << x << " poza dziedzina\n"; 
    return NAN;
  }

  double suma = 0;
  for (double i = 0 ; i < par.size() ; i++) 
    suma += par.at(i) * pow (x, i);

  return suma;
}

