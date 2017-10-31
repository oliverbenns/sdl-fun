#include "entity.h"
#include "body.h"
#include "input.h"
#include "sprite.h"

Entity::Entity() : Vector(0, 0) {
  // height = sprite->rect.h;
  // width = sprite->rect.w;
}

void Entity::preUpdate(double deltaTime) {
  body->preUpdate(deltaTime);
}

void Entity::update(double deltaTime) {
  body->update(deltaTime);

  if (input) {
    input->update(deltaTime);
  }

  // !! This should come after position changes.
  sprite->update(deltaTime);
}

void Entity::addComponent(Body* body) {
  this->body = body;
};

void Entity::addComponent(Input* input) {
  this->input = input;
};

void Entity::addComponent(Sprite* sprite) {
  this->sprite = sprite;
};

void Entity::render(SDL_Renderer* renderer) {
  sprite->render(renderer);
  body->render(renderer);
}
