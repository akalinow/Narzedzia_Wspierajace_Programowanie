#ifndef __MathTools__
#define __MathTools__

#include "Funkcja.h"

class MathTools { 
 public:
  static void   MinXY     (Funkcja& , double, double, double&, double& );
  static double Integral  (Funkcja& , double, double );
  static double Root      (Funkcja& , double, double );

  static double dx;
};

#endif
