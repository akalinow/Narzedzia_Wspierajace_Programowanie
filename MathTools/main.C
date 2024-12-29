// g++  main.C *.o -L/usr/lib/x86_64-linux-gnu -lgsl -lgslcblas -lm

#include "Wymierna.h"
#include "Wielomian.h"
#include "Gauss.h"
#include "IntGauss.h"
#include "MathTools.h"
#include <iostream>
#include <vector>
#include <gsl/gsl_sf_erf.h>
using namespace std;

int main () 
{
  /******* Testujemy Wymierna *******/
  
  Wymierna Wym (-10., 10., -5., 4., 3., 2.);
  Wym.Status();

  cout << "Wym(0) = " << Wym.f(0) << " , Wym(1.25) = " << Wym.f(1.25) << "\n\n";

  /******* Testujemy wielomian *******/

  vector<double> wpar = {1., -4., 1.};
  Wielomian W (-10., 10., wpar);
  W.Status ();

  cout << "W(0) = " << W.f(0) << " , W(1) = " << W.f(1) << "\n\n";


  /******* Testujemy funkcje Gaussa *******/

  Gauss G (-10., 10., 1., 1.);
  G.Status ();

  cout << "G(0) = " << G.f(0.) << " , G(1) = " << G.f(1.) << "\n\n";

  /******* Testujemy IntGauss *******/
  
  IntGauss IG (-10., 10., 1. , 0. , 1.);
  IG.Status();
  
  cout << "Dla x0 = 0, sigma = 1, IG(0.) = " << IG.f (0.) << endl;
  cout << "IG(1) - IG(-1) = " << IG.f (1.) - IG.f (-1.) << endl;
  IG.x0 = 5. ;
  cout << "Dla x0 = 5, sigma = 1, IG(5.) = " << IG.f (5.) << endl;
  IG.x0 = 0. ;
  IG.sigma = 2. ;
  cout << "Dla x0 = 0, sigma = 2, IG(2) - IG(-2) = " << IG.f(2.) - IG.f ( -2. ) << "\n\n";

  /******* Testujemy MathTools *******/
   
  MathTools::dx = 1e-5;

  cout << "M_zerowe   Wym. [ 0:5 ] = " << MathTools::Root     (Wym,  0. , 5.) << endl;
  cout << "Calka      Gauss[-9:1 ] = " << MathTools::Integral ( G , -9. , 1.) << endl;

  double MinX, MinY;
  MathTools::MinXY (W, 0. , 4. , MinX, MinY);
  cout << "(X,Y)_Ymin Wiel.[ 0:5 ] = (" << MinX << " : " << MinY << " )\n";

  return 0;
}
