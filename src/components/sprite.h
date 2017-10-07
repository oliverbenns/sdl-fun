#pragma once

#include <SDL2/SDL.h>
#include "texture.h"

struct Player; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Sprite {
  Sprite(SDL_Renderer* renderer, const char * texturePath);
  void update(Player& player);
  void render(Player& player, SDL_Renderer* renderer);

  SDL_Rect rect;
  SDL_Texture* texture;
};
