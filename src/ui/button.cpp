#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "button.h"
#include "texture.h"

Button::Button(SDL_Renderer* renderer, const char* label) : GameObject(renderer, "button.bmp") {
  TTF_Font* gFont = TTF_OpenFont("sign_painter_house_script.ttf", 24);
  SDL_Color textColor = { 0, 0, 0 };
  this->label = createText(renderer, label, textColor, gFont);
}

void Button::update() {
  rect.y++;
}

void Button::render() {
  GameObject::render();
  SDL_RenderCopy(renderer, label, NULL, &rect);
}
