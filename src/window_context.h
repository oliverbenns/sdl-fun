#pragma once

struct WindowContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
};

bool createWindowContext(WindowContext *context, int width, int height);

void destroyWindowContext(WindowContext *context);
