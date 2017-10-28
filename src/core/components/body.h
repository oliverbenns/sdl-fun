#pragma once
#include <SDL2/SDL.h>
#include "component.h"
#include "vector.h"

#include "entity.h"

struct Entity;

struct Body : Component {
  Body();

  void update(double deltaTime);
  void render(SDL_Renderer* renderer);
  bool checkCollision();

  bool gravity = true;
  Vector velocity;
  Entity* entity;
  int width;
  int height;
  bool debug = true;
};
