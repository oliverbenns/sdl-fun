#pragma once

struct Entity {
  // @TODO: Do I need to define virtual deconstructor?

  // @TODO: Store position on entity or a position/transform component? Or on Sprite?
  int x;
  int y;

  unsigned int id;
  char tag; // @TODO: Allow multiple?
  bool active;
};
