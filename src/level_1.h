#include "entity.h"
#include "entities.h"

#include "scene.h"

struct Level1 : Scene {
  Level1(SDL_Renderer* renderer) {
    Entity* player = new Player(renderer);
    Entity* floor = new Floor(renderer, 300, 200);
    Entity* floor2 = new Floor(renderer, 100, 500);

    this->addEntity(player);
    this->addEntity(floor);
    this->addEntity(floor2);

    player->body->addCollider(floor);
    player->body->addCollider(floor2);
  }
};
