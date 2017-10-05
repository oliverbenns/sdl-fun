#ifndef BUTTON_H
#define BUTTON_H
#include <SDL2/SDL.h>
#include "../game_object.h"

struct Button {
  GameObject gameObject;
};

Button createButton(SDL_Renderer* renderer);

#endif
