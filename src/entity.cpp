#include "entity.h"

Entity::Entity(Sprite* sprite, Input* input) : sprite(sprite), input(input) {

}

void Entity::update(double deltaTime) {
  x = x + deltaTime * 0.1;

  input->update(*this, deltaTime);

  // !! This should come after position changes.
  sprite->update(*this);
}

void Entity::render(SDL_Renderer* renderer) {
  sprite->render(*this, renderer);
}
