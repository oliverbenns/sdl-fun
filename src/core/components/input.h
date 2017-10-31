#pragma once

#include <SDL2/SDL.h>
#include "component.h"

struct Entity;

struct Input : Component {
  Input(Entity* entity);

  void update(double deltaTime);

  // Can we make these bools?
  const Uint8* up;
  const Uint8* down;
  const Uint8* left;
  const Uint8* right;

  private:
    const Uint8* state;
};
