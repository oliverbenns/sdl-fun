#ifndef WINDOW_CONTEXT_H
#define WINDOW_CONTEXT_H

struct WindowContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
};

bool createWindowContext(WindowContext *context, int width, int height);

void destroyWindowContext(WindowContext *context);

#endif
