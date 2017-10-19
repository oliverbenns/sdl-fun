#include "entity.h"

Entity::Entity(Sprite* sprite, Body* body, Input* input) : sprite(sprite), body(body), input(input) {
  height = sprite->rect.h;
  width = sprite->rect.w;
}

void Entity::update(double deltaTime) {
  body->update();

  if (input) {
    input->update(deltaTime);
  }

  // !! This should come after position changes.
  sprite->update();
}

void Entity::render(SDL_Renderer* renderer) {
  sprite->render(renderer);
}
