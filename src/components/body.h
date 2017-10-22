#pragma once

#include "component.h"
#include "vector.h"

struct Body : Component {
  Body();

  void update();
  bool checkCollision();

  bool gravity = true;
  Vector velocity;
};
