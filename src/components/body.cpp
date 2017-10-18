#include "body.h"

Body::Body() {
  // Gravity!
  velocity.y = 1;
};

void Body::update(Entity& entity) {
  entity.x += velocity.x;
  entity.y += velocity.y;
};