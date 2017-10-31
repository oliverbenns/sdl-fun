#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h"
#include "delta_time.h"
#include "scene.h"
#include "level_1.h"

int main(int argc, char* args[]) {
  Game game;

  // Start up SDL and create window
  if(!game.init()) {
    printf( "Failed to initialize!\n" );
    return -1;
  }

  Scene* level1 = new Level1(game.window->renderer);

  game.sceneManager.add(level1);
  game.sceneManager.activate(2);

  DeltaTime deltaTime;

  while(game.running) {
    game.update();

    deltaTime.update();

    // printf("deltaTime %f\n", deltaTime.now);

    // Clear screen
    SDL_RenderClear(game.window->renderer);

    game.sceneManager.active->update(deltaTime.now);
    game.sceneManager.active->render(game.window->renderer);

    // Update screen
    SDL_RenderPresent(game.window->renderer);
  }

  game.quit();

  return 0;
}
