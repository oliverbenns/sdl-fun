#pragma once

#include "entity.h"
#include "vector.h"

struct Entity; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Body {
  Body();
  // void update(Entity& entity);
  void update();
  bool checkCollision();

  bool gravity = true;
  Vector velocity;
  Entity* entity;
};
