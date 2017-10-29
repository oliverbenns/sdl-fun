#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h"
#include "delta_time.h"
#include "entity.h"
#include "entities.h"

int main(int argc, char* args[]) {
  Game game;

  // Start up SDL and create window
  if(!game.init()) {
    printf( "Failed to initialize!\n" );
    return -1;
  }

  Entity* entities[2];
  entities[0] = new Player(game.window->renderer);
  entities[1] = new Floor(game.window->renderer);

  entities[0]->body->addCollider(entities[1]);

  DeltaTime deltaTime;

  while(game.running) {
    game.update();

    deltaTime.update();

    // printf("deltaTime %f\n", deltaTime.now);

    // Clear screen
    SDL_RenderClear(game.window->renderer);

    // Size of array. Although it's a fixed array, it probably won't be in future so keeping this here. Probs make a util.
    int entityCount = sizeof(entities) / sizeof(entities[0]);

    for (unsigned int i = 0; i < entityCount; i++) {
      Entity* entity = entities[i];

      entity->preUpdate(deltaTime.now);
      entity->update();
      entity->render(game.window->renderer);
    }

    // Update screen
    SDL_RenderPresent(game.window->renderer);
  }

  game.quit();

  return 0;
}
