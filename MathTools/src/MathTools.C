// g++ -std=c++17 mathtools.C

#include "MathTools.h"
#include <cmath>
#include <iostream>

using std::fabs, std::min;

double MathTools::dx = 0.01;

void MathTools::MinXY   (Funkcja& F, double xmin, double xmax, double& MinX, double& MinY) {
  MinX = xmin ;
  MinY = F.f (xmin);
  for (double x = xmin; x <= xmax; x += dx ) {
    if (F.f(x) < MinY) {
      MinX = x;
      MinY = F.f(x);
    }
  }
}

double MathTools::Integral (Funkcja& F, double xmin, double xmax) {
  double result = ( F.f(xmin) + F.f(xmax) ) / 2. ;
  for (double x = xmin + dx; x < xmax; x += dx)
    result += F.f(x);
	
  return result * dx;
}

double MathTools::Root (Funkcja& F, double x1 , double x2) {
  double y1 = F.f ( x1 );

  while ( fabs (x2 - x1) > dx )
  {
    double x = (x1 + x2) / 2.;
    double y = F.f (x);
    if ( y*y1 > 0 ) {
      x1 = x;
      y1 = y;
    }
    else
      x2 = x;
  }
  return (x1 + x2) / 2.;
}

