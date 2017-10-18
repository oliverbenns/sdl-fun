#pragma once

#include <SDL2/SDL.h>
#include "body.h"
#include "input.h"
#include "sprite.h"
#include "vector.h"

struct Body;
struct Input;
struct Sprite;

struct Entity : Vector {
  Entity(Sprite* sprite, Body* body, Input* input);
  // @TODO: Do I need to define virtual deconstructor?

  // @TODO: Store position on entity or a position/transform component? Or on Sprite?
  void update(double deltaTime);
  void render(SDL_Renderer* renderer);

  unsigned int id;
  char tag; // @TODO: Allow multiple?
  bool active;

  Body* body;
  Input* input;
  Sprite* sprite;
};
