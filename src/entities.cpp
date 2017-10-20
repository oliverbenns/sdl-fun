#include "entities.h"

struct Entity;

Entity* createPlayer(SDL_Renderer* renderer) {
  Entity* entity = new Entity();

  entity->addComponent(new Body());
  entity->addComponent(new Input());
  entity->addComponent(new Sprite(renderer, "player.bmp"));

  return entity;
}

Entity* createFloor(SDL_Renderer* renderer) {
  Entity* entity = new Entity();

  entity->addComponent(new Body());
  entity->addComponent(new Sprite(renderer, "floor.bmp"));

  entity->body->gravity = false;
  entity->x = 0;
  entity->y = 400;

  return entity;
}
