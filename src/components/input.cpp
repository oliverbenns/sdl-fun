#include <stdio.h>
#include "player.h"
#include "input.h"

Input::Input() {
  state = SDL_GetKeyboardState(NULL);

  up = &state[SDL_SCANCODE_UP];
  down = &state[SDL_SCANCODE_DOWN];
  left = &state[SDL_SCANCODE_LEFT];
  right = &state[SDL_SCANCODE_RIGHT];
}
// @TODO: This is obviously specific right now. How can I make this more general? If possible?
void Input::update(Player& player, double deltaTime) {
  // printf("\n| up: %u", *up);
  // printf("| down: %u", *down);
  // printf("| left: %u", *left);
  // printf("| right: %u\n", *right);
  // @TODO: This is going by deltaTime! This is bad as we could miss inputs or it's not seamless. To fix this do we need to run as seperate process/thread with SDL_PollEvent.
};

