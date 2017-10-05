#include <SDL2/SDL.h>
#include "game_object.h"
#include "button.h"

Button::Button(SDL_Renderer *renderer, const char* label) : GameObject(renderer, "button.bmp") {
  this->label = label;
}

void Button::update() {
  rect.y++;
}
