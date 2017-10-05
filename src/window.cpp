#include <SDL2/SDL.h>
#include <stdio.h>
#include "window.h"

Window::Window(int width, int height) {
  int result = SDL_CreateWindowAndRenderer(width, height, NULL, &this->window, &this->renderer);

  if (result < 0) {
    printf("WindowContext could not be created! SDL_Error: %s\n", SDL_GetError());
  }

  this->width = width;
  this->height = height;

  // @TODO: Error handle this.
  SDL_SetRenderDrawColor(this->renderer, 255, 96, 248, 255);
}

// Can this be a destructor?
void Window::close() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // @TODO: Is this necessary?
  renderer = NULL;
  window = NULL;
}
