#include "player.h"

Player::Player(SDL_Renderer* renderer) : sprite(renderer, "player.bmp") {}

void Player::update() {
  sprite.update(*this);
  x++;
}

void Player::render(SDL_Renderer* renderer) {
  sprite.render(*this, renderer);
}
