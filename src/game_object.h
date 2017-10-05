#pragma once

struct GameObject {
  SDL_Texture* texture;
  SDL_Rect rect;
  SDL_Renderer* renderer;
};

GameObject createGameObject(SDL_Renderer* renderer, const char* texturePath);

// bool updateGameObject(GameObject gameObject);

bool renderGameObject(GameObject* gameObject);
