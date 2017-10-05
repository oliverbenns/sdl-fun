#pragma once

class GameObject {
  public:
    GameObject(SDL_Renderer* renderer, const char * textureSheet);
    // ~GameObject;

    void update();
    void render();

  protected:
    SDL_Rect rect;

  private:
    int x;
    int y;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};
