#include "Display.h"
#include <cmath>

// constructor
Display::Display () {

  // graph limits
  displayLeft = X_MIN;
  displayRight = X_MAX;
  displayUp = Y_MIN;
  displayDown = Y_MAX;

  // offsets
  xMax = ROFF;
  xMin = LOFF;
  yMax = DOFF;
  yMin = UOFF;

}

// ---------------------------------------- HELPERS --------------------------------------

// check ratio as per closest boundary
void Display::setRatios (int x, int y, Heap &h) {

  // along x
  h.insert((x - LOFF + 0.0) / WIDTH);
  h.insert((ROFF - x + 0.0) / WIDTH);

  // along y
  h.insert((y - UOFF + 0.0) / HEIGHT);
  h.insert((DOFF - y + 0.0) / HEIGHT);

}

// using smallest ratio to change limits
void Display::updateGraphBox (int x, int y, double r) {

  // modifying pixel range for x
  xMin = x - r * WIDTH;
  xMax = x + r * WIDTH;

  // modifying pixel range for y
  yMin = y - r * HEIGHT;
  yMax = y + r * HEIGHT;

}

// modify the graph plot limits
void Display::updateLimits () {

  // modifying range of values for x
  displayLeft += (displayRight - displayLeft) * ((0.0 + xMin - LOFF) / WIDTH);
  displayRight -= (displayRight - displayLeft) * ((ROFF - xMax + 0.0) / WIDTH);

  // modifying range of values for y
  displayUp += (displayDown - displayUp) * ((0.0 + yMin - UOFF) / HEIGHT);
  displayDown -= (displayDown - displayUp) * ((DOFF - yMax + 0.0) / HEIGHT);

}

// abscissa
double Display::xCoordinate (int x) {

  // return scaled x coordinate on graph
  return x * (displayRight - displayLeft) / WIDTH + displayLeft;

}

// ordinate
double Display::yCoordinate (int y) {

  // return scaled y coordinate on graph
  return y * (displayDown - displayUp) / HEIGHT + displayUp;

}

// ---------------------------------------- ZOOMING --------------------------------------

// function to do all necessary steps for zooming

/*
Depending on the point chosen, first find closest boundary (left, right, up or down).
Then calculate ratio of difference between boundary and the span along that axis.
Accordingly scale the other boundaries so as to maintain a square.
The chosen point would be kept at the centre of the final square.
*/

void Display::zoomPoint (int x, int y) {

  // out of required box
  if (x < LOFF || x > ROFF || y < UOFF || y > DOFF) {
    return;
  }

  // heap for ratios with respect to boundaries
  Heap h(4);

  // calculation for ratios
  setRatios(x,y,h);

  // finding smallest ratio
  double selected = h.min();
  h.deleteMin();

  // update graph
  updateGraphBox(x,y,selected); 

  // update graph limits
  updateLimits();

}