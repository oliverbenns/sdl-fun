#include "player.h"
#include "input.h"

// @TODO: This is obviously specific right now. How can I make this more general? If possible?
void Input::update(Player& player) {
  // @TODO: This is going by deltaTime! This is bad as we could miss inputs or it's not seamless. To fix this do we need to run as seperate process/thread with SDL_PollEvent.
  while(SDL_PollEvent( &e ) != 0) {
    // User presses a key
    if(e.type == SDL_KEYDOWN) {
      //Select surfaces based on key press
      switch(e.key.keysym.sym) {
        case SDLK_UP:
          player.y--;
        break;

        case SDLK_DOWN:
          player.y++;
        break;

        case SDLK_LEFT:
          player.x--;
        break;

        case SDLK_RIGHT:
          player.x++;
        break;

        default:

        break;
      }
    }
  }
};

