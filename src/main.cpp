/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include "game_object.h"
#include "window.h"
// #include "ui/button.h"

bool init();
bool loadMedia();
void close();

// @TODO Why do I have to make this a pointer?
GameObject* button;
Window* window;

bool init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  } else {
    window = new Window(800, 600);
  }

  return success;
}

bool loadMedia() {
  // Loading success flag
  bool success = true;

  button = new GameObject(window->renderer, "button.bmp");

  return success;
}

int main(int argc, char* args[]) {
  // Start up SDL and create window
  if(!init()) {
    printf( "Failed to initialize!\n" );
  } else {
    // Load media
    if(!loadMedia()) {
      printf( "Failed to load media!\n" );
    } else {
      // Main loop flag
      bool quit = false;

      // Event handler
      SDL_Event e;

      while(!quit) {
        // Handle events on queue
        while( SDL_PollEvent(&e) != 0 ) {
          //User requests quit
          if (e.type == SDL_QUIT) {
            quit = true;
          }
        }

        // Clear screen
        SDL_RenderClear(window->renderer);

        button->update();
        button->render();

        // Update screen
        SDL_RenderPresent(window->renderer);
      }
    }
  }


  // Free resources and close SDL
  delete window;
  SDL_Quit();

  return 0;
}
