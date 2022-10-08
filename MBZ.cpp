// CS293 PROJECT
// MANDELBROT ZOOM

/*
Name: Sarthak Mittal
Roll no. 200050129
C++ code for a infinite Mandelbrot fractal renderer
Using SDL2 library for rendering the zoom motion
*/

#include <SDL2/SDL.h> // SDL2 library
#include "Display.h"
#include "Colour.h"
#include "Complex.h"
#include "Graph.h"
#include "BST.h"

int iterations = MAX_ITER;

int main (int argc, char* argv[]) {

  // ---------------------------------------- SETUP -----------------------------------------

  // initialise everything
  SDL_Init(SDL_INIT_EVERYTHING);

  // create window
  SDL_Window* MBZwindow;

  // create renderer
  SDL_Renderer* MBZrender;

  // recording events
  SDL_Event MBZevent;

  // initialise
  SDL_CreateWindowAndRenderer(WINDOW_X,WINDOW_Y,0,&MBZwindow,&MBZrender);
  SDL_RenderSetLogicalSize(MBZrender,WIDTH,HEIGHT);

  // class objects
  Display d;
  Colour c;
  Graph g(WIDTH * HEIGHT, WIDTH * HEIGHT);
  BST b;

  // global mouse position recorder
  int mouseX;
  int mouseY;

  // ------------------------------------ MAIN LOOP -------------------------------------

  while (true) {

    // set renderer
    SDL_RenderPresent(MBZrender);

    // pixel by pixel

    // loop for x
    for (long long int pixel_x = 0; pixel_x < WIDTH; pixel_x++) {

      // ---------------------------------------- EVENT HANDLER --------------------------------

      // exit window
      if (SDL_PollEvent(&MBZevent) && MBZevent.type == SDL_QUIT) {
        return 0;
      }

      // keyboard key
      const Uint8 *state = SDL_GetKeyboardState(NULL);

      // q to quit
      if (state[SDL_SCANCODE_Q]) {
        return 0;
      }

      // zooming
      if (SDL_PollEvent(&MBZevent)) {

        // z to select the zooming point
        if (state[SDL_SCANCODE_Z]) {

          // get coordinates
          SDL_GetMouseState(&mouseX,&mouseY);

          // update graph box
          d.zoomPoint(mouseX,mouseY);

          // reset stored data
          Graph newG(WIDTH * HEIGHT, WIDTH * HEIGHT);
          BST newB;
          g = newG;
          b = newB;

        }
        
      }

      // -------------------------------------- DRAWING --------------------------------------

      // loop for y
      for (long long int pixel_y = 0; pixel_y < HEIGHT; pixel_y++) {

        // initial coordinates in range
        double x_init = d.xCoordinate(pixel_x);
        double y_init = d.yCoordinate(pixel_y);
        Complex init(x_init,y_init);

        // final coordinates
        double x_fin = x_init;
        double y_fin = y_init;
        Complex fin(x_fin,y_fin);

        // deciding colour
        int colour;
        for (colour = 0; colour < iterations; colour++) {

          // square of previous complex value
          // Complex temp = fin * fin;
          double x_temp = x_fin * x_fin - y_fin * y_fin;
          double y_temp = 2 * x_fin * y_fin;
          Complex temp(x_temp,y_temp);

          // adding for current iteration
          // fin = temp + init;
          x_fin = x_temp + x_init;
          y_fin = y_temp + y_init;
          Complex fin2(x_fin,y_fin);
          fin = fin2;

          // check the point
          if (fin2.modulus() > 2) {
            break;
          }

        }

        // --------------------------------------- COLOURING --------------------------------------

        // setting brightness
        double brightness = colour * COLOR_MAX / iterations;
        if (colour == iterations || brightness < 20) {
          brightness = 0.0;
        }

        // store the intensity
        c.setIntensity(brightness);

        // store colour to point mapping
        b.insert(colour,fin,b.root);

        // store pixel to colour mapping
        g.addEdge(pixel_x * 1000 + pixel_y,colour);

        // render the point
        SDL_SetRenderDrawColor(MBZrender,c.red(),c.green(),c.blue(),COLOR_MAX);
        SDL_RenderDrawPoint(MBZrender,pixel_x,pixel_y);

      }

    }

  }

  return 0;

}