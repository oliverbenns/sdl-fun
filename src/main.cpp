/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include "window_context.h"
#include "game_object.h"

bool init();
bool loadMedia();
void close();

WindowContext context;
GameObject button;

bool init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  } else {
    createWindowContext(&context, 800, 600);
  }

  return success;
}

bool loadMedia() {
  // Loading success flag
  bool success = true;

  createGameObject(&button, context.renderer, "button.bmp");

  return success;
}

void close() {
  destroyWindowContext(&context);
  SDL_Quit();
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

        //Clear screen
        SDL_RenderClear(context.renderer);

        renderGameObject(&button);

        //Update screen
        SDL_RenderPresent(context.renderer);
      }
    }
  }

  //Free resources and close SDL
  close();

  return 0;
}
