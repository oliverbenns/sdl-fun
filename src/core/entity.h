#pragma once

#include <SDL2/SDL.h>
#include "vector.h"

struct Body;
struct Input;
struct Sprite;

struct Entity : Vector {
  Entity();
  // @TODO: Do I need to define virtual deconstructor?

  // @TODO: Store position on entity or a position/transform component? Or on Sprite?
  void preUpdate(double deltaTime);
  void update(double deltaTime);
  void render(SDL_Renderer* renderer);

  // @TODO: Use template rather than overloading.
  void addComponent(Body* body);
  void addComponent(Input* input);
  void addComponent(Sprite* sprite);

  unsigned int id;
  char tag; // @TODO: Allow multiple?
  bool active;

  // Could we make this a rect like SDL_RECT?
  // int width;
  // int height;

  Body* body = nullptr;
  Input* input = nullptr;
  Sprite* sprite = nullptr;
};
