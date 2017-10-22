#pragma once

#include <SDL2/SDL.h>
#include "texture.h"
#include "component.h"

struct Sprite : Component {
  Sprite(SDL_Renderer* renderer, const char * texturePath);

  void update();
  void render(SDL_Renderer* renderer);

  SDL_Rect rect;
  SDL_Texture* texture;
};
