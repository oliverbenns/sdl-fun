#include "scene.h"

void Scene::addEntity(Entity* entity, int index) {
  entities[index] = entity;
};

void Scene::update(double deltaTime) {
  // Size of array. Although it's a fixed array, it probably won't be in future so keeping this here. Probs make a util.
  int entityCount = sizeof(entities) / sizeof(entities[0]);

   for (unsigned int i = 0; i < entityCount; i++) {
      Entity* entity = entities[i];

      entity->preUpdate(deltaTime);
      entity->update(deltaTime);
    }
};

void Scene::render(SDL_Renderer* renderer) {
  int entityCount = sizeof(entities) / sizeof(entities[0]);

   for (unsigned int i = 0; i < entityCount; i++) {
      entities[i]->render(renderer);
    }
};
