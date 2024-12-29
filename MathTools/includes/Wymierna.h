#ifndef __Wymierna__
#define __Wymierna__

#include "Funkcja.h"

class Wymierna : public Funkcja {
 public:
  double a, b, c, d;
  Wymierna (double, double, double, double, double, double);

  void Status ();
  double f (double);
};

#endif
