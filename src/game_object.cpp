#include <SDL2/SDL.h>
#include "texture.h"
#include "game_object.h"

bool createGameObject(GameObject* gameObject, SDL_Renderer* renderer, const char* texturePath) {
  gameObject->renderer = renderer;

  // @TODO: Error handle.
  gameObject->texture = loadTexture(gameObject->renderer, texturePath);

  // Set rewidth and height to the same dimensions as the texture
  SDL_QueryTexture(gameObject->texture, NULL, NULL, &gameObject->rect.w, &gameObject->rect.h);

  // This seems safer as sometimes it appears we get random vals
  gameObject->rect.x = 0;
  gameObject->rect.y = 0;

  return true;
}

// bool updateGameObject(GameObject gameObject);

bool renderGameObject(GameObject* gameObject) {
  SDL_RenderCopy(gameObject->renderer, gameObject->texture, NULL, &gameObject->rect);

  return true;
};
