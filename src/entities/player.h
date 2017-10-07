#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "input.h"
#include "sprite.h"

struct Player {
  Player(SDL_Renderer* renderer);
  void update();
  void render(SDL_Renderer* renderer);

  // @TODO: Store position on entity or a position/transform component? Or on Sprite?
  int x;
  int y;

  Input input;
  Sprite sprite;
};
