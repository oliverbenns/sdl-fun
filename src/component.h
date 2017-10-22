#pragma once

#include "entity.h" // We need this becuase the components need a complete type

struct Entity; // Forward declaration due to circular dependency issue. We can remove this when it becomes a generic Entity.

struct Component {
  unsigned int id;
  char tag; // @TODO: Allow multiple?
  bool active;
  // const char * id;
  Entity* entity;
};
