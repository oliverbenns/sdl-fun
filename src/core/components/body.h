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
  void addCollider(Entity* entity);

  bool gravity = true;
  Vector velocity;
  Entity* entity;
  Entity* collider = nullptr;
  int width;
  int height;
  bool debug = true;
};
