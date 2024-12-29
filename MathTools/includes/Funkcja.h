#ifndef __funkcja__
#define __funkcja__

class Funkcja {
 public:
  double xmin, xmax;
  Funkcja (double, double) ;

  virtual void Status () ;
  virtual double f (double) = 0;
};

#endif
