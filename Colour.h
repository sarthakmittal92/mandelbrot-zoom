// Used for colouring the plot

#ifndef __COLOUR_H__
#define __COLOUR_H__

#include "MBZ.h"

class Colour {

  // ---------------------------------------- VARIABLES --------------------------------------

  // rgb in 0 to COLOR_MAX
  int brightness;

  // ---------------------------------------- FUNCTIONS --------------------------------------

  public:

    // constructor
    Colour ();

    // set brightness
    void setIntensity (int bright);

    // rgb encoding
    double red ();
    double green ();
    double blue ();

};

#endif