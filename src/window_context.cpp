#include <SDL2/SDL.h>
#include <stdio.h>
#include "window_context.h"

bool createWindowContext(WindowContext *context, int width, int height) {

  // @TODO: Add these flags.
  // // gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  // //   ctx.renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
  int result = SDL_CreateWindowAndRenderer(width, height, NULL, &context->window, &context->renderer);

  if (result < 0) {
    printf("WindowContext could not be created! SDL_Error: %s\n", SDL_GetError());
  }

  // @TODO: Error handle this.
  SDL_SetRenderDrawColor(context->renderer, 255, 96, 248, 255);

  return result;
}

void destroyWindowContext(WindowContext *context) {
  SDL_DestroyRenderer(context->renderer);
  SDL_DestroyWindow(context->window);

  // @TODO: Is this necessary?
  context->renderer = NULL;
  context->window = NULL;
}
