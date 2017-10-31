#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "body.h"
#include "input.h"
#include "sprite.h"

struct Entity;

struct Player : Entity {
  Player(SDL_Renderer* renderer) {
    this->addComponent(new Body(this));
    this->addComponent(new Input(this));
    this->addComponent(new Sprite(this, renderer, "player.bmp"));
  }
};

struct Floor : Entity {
  Floor(SDL_Renderer* renderer) {
    this->addComponent(new Body(this));
    this->addComponent(new Sprite(this, renderer, "floor.bmp"));

    this->body->gravity = false;
    this->x = 300;
    this->y = 200;
  }
};
