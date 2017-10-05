#include <SDL2/SDL.h>
#include "texture.h"
#include "game_object.h"

GameObject::GameObject(SDL_Renderer* ren, const char * texturePath) {
  renderer = ren;
  texture = loadTexture(ren, texturePath);

  // Set rewidth and height to the same dimensions as the texture
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

  // This seems safer as sometimes it appears we get random vals
  rect.x = 0;
  rect.y = 0;
}

void GameObject::update() {
  rect.x++;
}

void GameObject::render() {
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}
