#pragma once

#include <SDL2/SDL.h>
#include "texture.h"
#include "component.h"

#include "entity.h"

struct Entity;

struct Sprite : Component {
  Sprite(SDL_Renderer* renderer, const char * texturePath);

  void update(double deltaTime);
  void render(SDL_Renderer* renderer);

  Entity* entity;

  SDL_Rect rect;
  SDL_Texture* texture;
};
