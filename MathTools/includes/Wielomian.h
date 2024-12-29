#ifndef __wielomian__
#define __wielomian__

#include "Funkcja.h"
#include <vector>

using std::vector;

class Wielomian : public Funkcja {
 public:
  vector<double> par;
  Wielomian (double , double , vector<double> );

  void Status ();
  double f (double);
};

#endif
