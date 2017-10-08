#pragma once

#include "vector.h"

struct Entity : Vector {
  // @TODO: Do I need to define virtual deconstructor?

  // @TODO: Store position on entity or a position/transform component? Or on Sprite?

  unsigned int id;
  char tag; // @TODO: Allow multiple?
  bool active;
};
