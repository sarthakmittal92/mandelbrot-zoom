// All editable constants

#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

// dimensions for display window
#define WINDOW_X 1000
#define WINDOW_Y 900

// dimensions for plot
#define WIDTH 800
#define HEIGHT 800

// offsets
#define LOFF ((WINDOW_X - WIDTH) / 2)
#define ROFF ((WINDOW_X + WIDTH) / 2)
#define UOFF ((WINDOW_Y - HEIGHT) / 2)
#define DOFF ((WINDOW_Y + HEIGHT) / 2)

// dimensions for graph
#define X_MAX 1.0
#define Y_MAX 0.89
#define X_MIN -2.0
#define Y_MIN -2.11

// color constants
#define MAX_ITER 200
#define COLOR_MAX 255

// zooming constants
#define ZOOM_ITER 10
#define ZOOM_RATIO 0.9374
#define ZOOM 0.1
#define ITER_RATIO 1.02

#endif