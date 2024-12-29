#include "Funkcja.h"
#include <iostream>

using std::cout;

Funkcja::Funkcja (double a, double b) : xmin (a) , xmax (b) { 
}

void Funkcja::Status () {
  cout << "Funkcja na dziedzinie: [" << xmin << " : " << xmax << "]\n";
}

