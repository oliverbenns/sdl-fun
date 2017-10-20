#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "texture.h"
#include "component.h"

struct Entity; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Input : Component {
  Input();
  void update(double deltaTime);

  // Can we make these bools?
  const Uint8* up;
  const Uint8* down;
  const Uint8* left;
  const Uint8* right;
  Entity* entity;

  private:
    const Uint8* state;
};
