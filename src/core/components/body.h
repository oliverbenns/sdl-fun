#pragma once

#include "component.h"
#include "vector.h"

#include "entity.h"

struct Entity;

struct Body : Component {
  Body();

  void update(double deltaTime);
  bool checkCollision();

  bool gravity = true;
  Vector velocity;
  Entity* entity;
};
