#pragma once
#include <SDL2/SDL.h>
#include "game_object.h"

class Button : public GameObject {
  public:
    Button(SDL_Renderer *renderer, const char* label);
    void update();

  private:
    const char* label;
};
