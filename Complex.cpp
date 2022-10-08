#include "Complex.h"
#include <cmath>

// ------------------------------------- CONSTRUCTORS ---------------------------------------

// default
Complex::Complex () {

  real = 0;
  img = 0;

}

// initialize
Complex::Complex (int r, int i) {

  real = r;
  img = i;

}

// ---------------------------------------- HELPERS ----------------------------------------

// return list of complex coordinates
double* Complex::get () {

  double* c = new double[2];
  c[0] = real;
  c[1] = img;
  return c;

}

// absolute value (length)
double Complex::modulus () {

  return sqrt(real * real + img * img);

}


// inverse
Complex Complex::inverse () {

  double length = this -> modulus();
  double realPart = real / (length * length);
  double imgPart = img / (length * length);
  Complex i(realPart,imgPart);
  return i;

}

// ---------------------------------------- OPERATORS ----------------------------------------

// add operator
Complex Complex::operator+ (Complex c) {

  double realPart = real + c.real;
  double imgPart = img + c.img;
  Complex m(realPart,imgPart);
  return m;

}

// subtraction operator
Complex Complex::operator- (Complex c) {

  double realPart = real - c.real;
  double imgPart = img - c.img;
  Complex m(realPart,imgPart);
  return m;

}

// multiplication operator
Complex Complex::operator* (Complex c) {

  double realPart = real * c.real - img * c.img;
  double imgPart = real * c.img + img * c.real;
  Complex m(realPart,imgPart);
  return m;

}

// division
Complex Complex::operator/ (Complex c) {

  Complex i = c.inverse();
  Complex d = *this * i;
  return d;

}