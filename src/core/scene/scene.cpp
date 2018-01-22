#include "scene.h"

Scene::Scene() : entityCount(0), entities(nullptr) {

};

Scene::Scene(int length) : entityCount(length) {
  entities = new Entity[length];
};

void Scene::addEntity(Entity* entity) {
  Entity* newEntities = new Entity[entityCount + 1];

  // Fill the new array with our current elements.
  for (int i = 0; i < entityCount; i++)
    newEntities[i] = entities[i];


  // Add the new entity
  newEntities[entityCount + 1] = entity;

  // Delete the old array.
  delete[] entities;
  // Assign the new array
  entities = newEntities;

  entityCount++;
};

void Scene::removeEntity(Entity* entity) {
  // unsigned int index = -1;

  // for (unsigned int i = 0; i < entityCount; i++) {
  //   if (entities[i] == entity) {
  //     index = i;
  //     break;
  //   }
  // }

  // if (index < 0) {
  //   return;
  // }

  // Entity* data[entityCount - 1];

  // // Copy all pointers before the removed one
  // for (int before = 0; before < index; before++)
  //   data[before] = entities[before];

  // // Copy all pointers after the removed one
  // for (int after = index + 1; after < entityCount; after++)
  //   data[after - 1] = entities[after];

  // entityCount--;
  // entities = data;
};

void Scene::update(double deltaTime) {
  // Size of array. Although it's a fixed array, it probably won't be in future so keeping this here. Probs make a util.
  int entityCount = sizeof(entities) / sizeof(entities[0]);

//   for (unsigned int i = 0; i < entityCount; i++) {
//      Entity* entity = entities[i];
//
//      entity->preUpdate(deltaTime);
//      entity->update(deltaTime);
//    }
};

void Scene::render(SDL_Renderer* renderer) {
  int entityCount = sizeof(entities) / sizeof(entities[0]);

   for (unsigned int i = 0; i < entityCount; i++) {
       entities[i].render(renderer);
    }
};
