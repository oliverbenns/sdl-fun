/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include "window.h"
#include "entities/player.h"

Window* window;

bool init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  }

  // Initialize SDL_ttf
  if(TTF_Init() == -1) {
    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    success = false;
  }

  if (success) {
    window = new Window(800, 600);
  }

  return success;
}

int main(int argc, char* args[]) {
  // Start up SDL and create window
  if(!init()) {
    printf( "Failed to initialize!\n" );
    return -1;
  }

  Player* player = new Player(window->renderer);

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

    player->update();
    player->render(window->renderer);

    // Update screen
    SDL_RenderPresent(window->renderer);
  }

  // Free resources and close SDL
  delete window;
  SDL_Quit();

  return 0;
}
