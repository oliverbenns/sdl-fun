#pragma once

#include <SDL2/SDL.h>

#include "entity.h"

struct Scene {
  Scene();
  Scene(int length);
  void addEntity(Entity* entity);
  void removeEntity(Entity* entity);

  void update(double deltaTime);
  void render(SDL_Renderer* renderer);

  Entity *entities;
  unsigned int entityCount;
};
