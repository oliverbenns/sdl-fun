#include <SDL2/SDL.h>
#include <stdio.h>
#include "window.h"

Window::Window(int width, int height) : width(width), height(height) {}

bool Window::init() {
  int result = SDL_CreateWindowAndRenderer(width, height, NULL, &window, &renderer);

  if (result < 0) {
    printf("WindowContext could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // @TODO: Error handle this.
  SDL_SetRenderDrawColor(renderer, 255, 96, 248, 255);

  return true;
}

Window::~Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // @TODO: Is this necessary?
  renderer = NULL;
  window = NULL;
}
