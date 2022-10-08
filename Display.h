// Used to handle graph box and zooming

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "MBZ.h"
#include "Heap.h"

class Display {

  // ---------------------------------------- VARIABLES --------------------------------------

  // dynamic graph box
  double displayLeft;
  double displayRight;
  double displayUp;
  double displayDown;

  // dynamic display dimensions
  int xMax;
  int xMin;
  int yMax;
  int yMin;

  // ---------------------------------------- FUNCTIONS --------------------------------------

  public:

    // constructor
    Display ();

    // array minima
    double arrayMin (double* A, int n);

    // set ratios for point
    void setRatios (int x, int y, Heap &h);

    // update graph box
    void updateGraphBox (int x, int y, double r);

    // update limits
    void updateLimits ();

    // zoom into the chosen point
    void zoomPoint (int x, int y);
    
    // graph abscissa
    double xCoordinate (int x);

    // graph ordinate
    double yCoordinate (int y);

};

#endif