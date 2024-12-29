#ifndef __Gauss__
#define __Gauss__

#include "Funkcja.h"

class Gauss : public Funkcja {
 public:
  double x0, sigma;
  Gauss (double, double, double, double);

  void Status ();
  double f (double);
};

#endif
