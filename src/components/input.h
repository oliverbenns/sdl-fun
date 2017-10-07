#pragma once

#include <SDL2/SDL.h>
#include "texture.h"

struct Player; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Input {
  void update(Player& player);

  SDL_Event e;
};
