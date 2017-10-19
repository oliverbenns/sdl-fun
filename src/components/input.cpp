#include <stdio.h>
#include "entity.h"
#include "input.h"

Input::Input() {
  state = SDL_GetKeyboardState(NULL);

  up = &state[SDL_SCANCODE_W];
  down = &state[SDL_SCANCODE_S];
  left = &state[SDL_SCANCODE_A];
  right = &state[SDL_SCANCODE_D];
}

// @TODO: This is obviously specific right now. How can I make this more general? If possible?
void Input::update(Entity& entity, double deltaTime) {
  if (*up) {
    entity.y -= deltaTime;
  }

  if (*down) {
    entity.y += deltaTime;
  }

  if (*left) {
    entity.x -= deltaTime;
  }

  if (*right) {
    entity.x += deltaTime;
  }
};

