#include "Colour.h"
#include <cmath>

// constructor
Colour::Colour () {}

// ---------------------------------------- HELPERS --------------------------------------

void Colour::setIntensity (int bright) {

  // set brightness
  brightness = bright;

}

double Colour::red () {

  // intensity for red colour
  return sqrt(brightness * COLOR_MAX);

}

double Colour::green () {

  // intensity for green colour
  return brightness * brightness / COLOR_MAX;

}

double Colour::blue () {

  // intensity for blue colour
  return brightness;

}