#ifndef __Complex__
#define __Complex__

class Complex {
 public:
  double re, im;
  Complex (double, double);
  Complex Add (Complex& );
  void Print ();
};
#endif
