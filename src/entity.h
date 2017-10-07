#pragma once

struct Entity {
  // @TODO: Do I need to define virtual deconstructor?

  unsigned int id;
  char tag; // @TODO: Allow multiple?
  bool active;
};
