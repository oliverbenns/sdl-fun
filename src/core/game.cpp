#include "game.h"

Game::Game() {
  window = new Window(800, 600);
}

bool Game::init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // Initialize SDL_ttf
  if(TTF_Init() == -1) {
    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    return false;
  }

  // window = new Window(800, 600);
    if(window->init() == 0) {
    printf("Could not initialize window \n");
    return false;
  }

  return true;
}

void Game::update() {
SDL_Event event;
  while( SDL_PollEvent(&event) != 0 ) {
    //User requests quit
    if (event.type == SDL_QUIT) {
      running = false;
    }
  }
}

void Game::quit() {
  // Free resources and close SDL
  // delete window;
  SDL_Quit();
}
