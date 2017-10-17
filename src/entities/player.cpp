#include "player.h"

struct Entity;

Entity* createPlayer(SDL_Renderer* renderer) {
  return new Entity(
    new Sprite(renderer, "player.bmp"),
    new Input()
  );
}
