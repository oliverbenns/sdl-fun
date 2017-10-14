#include "player.h"

Player::Player(SDL_Renderer* renderer) : sprite(renderer, "player.bmp") {}

void Player::update(double deltaTime) {
  x = x + deltaTime * 0.1;

  input.update(*this, deltaTime);

  if (*input.up) {
    this->y -= deltaTime;
  }
  if (*input.down) {
    this->y += deltaTime;
  }
  if (*input.left) {
    this->x -= deltaTime;
  }
  if (*input.right) {
    this->x += deltaTime;
  }


  // !! This should come after position changes.
  sprite.update(*this);
}

void Player::render(SDL_Renderer* renderer) {
  sprite.render(*this, renderer);
}
