#pragma once

class GameObject {
  public:
    GameObject(SDL_Renderer* renderer, const char * textureSheet);
    // ~GameObject;

    void update();
    void render();

  private:
    int x;
    int y;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Renderer* renderer;
};
