// Used for storing points on plot

#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include "MBZ.h"

class Complex {

  // ---------------------------------------- VARIABLES --------------------------------------

  double real;
  double img;

  // ---------------------------------------- FUNCTIONS --------------------------------------

  public:

    // default constructor
    Complex ();

    // initialize
    Complex (int r, int i);

    // get complex number as a list
    double* get();

    // modulus of complex number
    double modulus ();

    // inverse of complex number
    Complex inverse ();

    // add complex numbers
    Complex operator+ (Complex c);

    // subtract complex numbers
    Complex operator- (Complex c);

    // multiply complex numbers
    Complex operator* (Complex c);

    // divide complex numbers
    Complex operator/ (Complex c);
};

#endif