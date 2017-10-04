#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

struct GameObject {
  SDL_Texture* texture;
  SDL_Rect rect;
  SDL_Renderer* renderer;
};

bool createGameObject(GameObject* gameObject, SDL_Renderer* renderer, const char* texturePath);

// bool updateGameObject(GameObject gameObject);

bool renderGameObject(GameObject* gameObject);

#endif
