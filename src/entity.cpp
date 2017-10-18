#include "entity.h"

Entity::Entity(Sprite* sprite, Body* body, Input* input) : sprite(sprite), body(body), input(input) {

}

void Entity::update(double deltaTime) {
  body->update(*this);
  input->update(*this, deltaTime);
  // !! This should come after position changes.
  sprite->update(*this);
}

void Entity::render(SDL_Renderer* renderer) {
  sprite->render(*this, renderer);
}
