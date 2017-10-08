#include "player.h"

Player::Player(SDL_Renderer* renderer) : sprite(renderer, "player.bmp") {}

void Player::update(double deltaTime) {
  x = x + deltaTime;

  // !! This should come after position changes.
  sprite.update(*this);
}

void Player::render(SDL_Renderer* renderer) {
  sprite.render(*this, renderer);
}
