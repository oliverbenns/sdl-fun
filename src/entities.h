#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "body.h"
#include "input.h"
#include "sprite.h"

struct Entity;

struct Player : Entity {
  Player(SDL_Renderer* renderer) : a(5) {
    this->addComponentTest(new Body());
    this->addComponent(new Input());
    this->addComponent(new Sprite(renderer, "player.bmp"));
      
      
  }
  int a = 3;
};

struct Floor : Entity {
  Floor(SDL_Renderer* renderer) {
    this->addComponentTest(new Body());
    this->addComponent(new Sprite(renderer, "floor.bmp"));

    this->body->gravity = false;
    this->x = 0;
    this->y = 400;
  }
};
