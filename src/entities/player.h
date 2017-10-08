#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "input.h"
#include "sprite.h"

struct Player : Entity {
  Player(SDL_Renderer* renderer);
  void update();
  void render(SDL_Renderer* renderer);

  Input input;
  Sprite sprite;
};
