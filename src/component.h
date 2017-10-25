#pragma once

#include <stdio.h>

// #include "entity.h" // We need this becuase the components need a complete type for updating body.cpp etc.

// struct Entity; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Component {
  unsigned int id;
  bool active;
  // Entity* entity;

  virtual void update(double deltaTime) {};
};
