#include "entities.h"

struct Entity;

Entity* createPlayer(SDL_Renderer* renderer) {

  Entity* entity = new Entity(
    new Sprite(renderer, "player.bmp"),
    new Body(),
    new Input()
  );
  entity->sprite->entity = entity;
  entity->body->entity = entity;
  entity->input->entity = entity;

  return entity;
}

Entity* createFloor(SDL_Renderer* renderer) {
  Entity* entity = new Entity(
    new Sprite(renderer, "floor.bmp"),
    new Body(),
    nullptr
  );

  entity->sprite->entity = entity;
  entity->body->entity = entity;
  entity->body->gravity = false;
  entity->x = 0;
  entity->y = 400;

  return entity;
}
