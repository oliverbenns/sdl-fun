#include "body.h"

Body::Body() {
  // Gravity!
  velocity.y = 1;
  width = 30;
  height = 30;
};

void Body::update(double deltaTime) {
  if (gravity) {
    entity->x += velocity.x;
    entity->y += velocity.y;
  }
};

void renderLine(SDL_Renderer* renderer, Vector* position, Vector* target) {
  SDL_RenderDrawLine(renderer, position->x, position->y, target->x, target->y);
}

void Body::render(SDL_Renderer* renderer) {
  if (!debug) {
    return;
  }

  SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );

  Vector topLeft(entity->x, entity->y);
  Vector topRight(entity->x + width, entity->y);
  Vector bottomRight(entity->x + width, entity->y + height);
  Vector bottomLeft(entity->x, entity->y + height);

  renderLine(renderer, &topLeft, &topRight);
  renderLine(renderer, &topRight, &bottomRight);
  renderLine(renderer, &bottomRight, &bottomLeft);
  renderLine(renderer, &bottomLeft, &topLeft);

  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

bool Body::checkCollision() {
  return true;
}
