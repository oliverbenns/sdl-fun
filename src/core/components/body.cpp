#include "body.h"

Body::Body() {
  // Gravity!
  velocity.y = 1;
};

void Body::update(double deltaTime) {
  if (gravity) {
    entity->x += velocity.x;
    entity->y += velocity.y;
  }

  // bool isCollidingWithFloor =
};

bool Body::checkCollision() {
  return true;
}
