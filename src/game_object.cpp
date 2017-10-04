#include <SDL2/SDL.h>
#include "texture.h"
#include "game_object.h"

bool createGameObject(GameObject* gameObject, SDL_Renderer* renderer, const char* texturePath) {
  gameObject->renderer = renderer;

  // @TODO: Error handle.
  gameObject->texture = loadTexture(gameObject->renderer, texturePath);

  SDL_Rect rect;

  gameObject->rect = rect;

  int w;
  int h;
  // Set rewidth and height to the same dimensions as the texture
  SDL_QueryTexture(gameObject->texture, NULL, NULL, &w, &h);

  gameObject->rect.h = h;
  gameObject->rect.w = w;

  return true;
}

// bool updateGameObject(GameObject gameObject);

bool renderGameObject(GameObject* gameObject) {

  SDL_RenderCopy(gameObject->renderer, gameObject->texture, NULL, NULL);
  // @TODO: Why can't I pass  in rect here successfully?
  // SDL_RenderCopy(gameObject->renderer, gameObject->texture, NULL, &gameObject->rect);

  return true;
};
