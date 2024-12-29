#ifndef __erf__
#define __erf__

#include "Funkcja.h"

class IntGauss : public Funkcja {
 public:
  double Norm, x0, sigma;
  IntGauss (double, double, double, double, double); 
  
  void Status ();
  double f (double);
};

#endif
