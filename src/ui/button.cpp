#include <SDL2/SDL.h>
#include "game_object.h"
#include "button.h"

Button createButton(SDL_Renderer* renderer) {
  Button button;
  button.gameObject = createGameObject(renderer, "button.bmp");
  // button.label = label;
  return button;
};
