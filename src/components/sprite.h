#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "texture.h"

struct Entity; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Sprite {
  Sprite(SDL_Renderer* renderer, const char * texturePath);
  void update();
  void render(SDL_Renderer* renderer);

  Entity* entity;
  SDL_Rect rect;
  SDL_Texture* texture;
};
