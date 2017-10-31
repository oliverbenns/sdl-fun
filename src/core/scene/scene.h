#pragma once

#include <SDL2/SDL.h>

#include "entity.h"

struct Scene {
  void addEntity(Entity* entity, int index);

  void update(double deltaTime);
  void render(SDL_Renderer* renderer);

  Entity* entities[3];
  int id;
};
