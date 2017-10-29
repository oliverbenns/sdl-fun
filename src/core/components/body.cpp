#include "body.h"

enum Vertices {
  TOP_LEFT,
  TOP_RIGHT,
  BOTTOM_RIGHT,
  BOTTOM_LEFT,
  TOTAL_VERTICES,
};

Body::Body() {
  // Gravity!
  velocity.y = 1;
  width = 50;
  height = 50;
};

void Body::update(double deltaTime) {
  // @TODO: Figure out a way to create these at creation time and prevent reassignment on each frame.
  // Currently the entity hasn't been constructed yet from the constructor here and is assigned later.
  vertices[0] = Vector(entity->x, entity->y);
  vertices[1] = Vector(entity->x + width, entity->y);
  vertices[2] = Vector(entity->x + width, entity->y + height);
  vertices[3] = Vector(entity->x, entity->y + height);

  if (gravity) {
    entity->x += velocity.x;
    entity->y += velocity.y;
  }

  if (collider == nullptr) {
    return;
  }

  if (isCollidingWith(collider)) {
    printf("COLLIDING!!\n");
  } else {
    printf("Not Colliding\n");
  }
};

// AABB
bool Body::isCollidingWith(Entity* entity) {
  Vector topLeftB(entity->x, entity->y);
  Vector bottomRightB(entity->x + entity->body->width, entity->y + entity->body->height);

  return !(
    vertices[BOTTOM_RIGHT].x < topLeftB.x ||
    vertices[TOP_LEFT].x > bottomRightB.x ||
    vertices[TOP_LEFT].y > bottomRightB.y ||
    vertices[BOTTOM_RIGHT].y < topLeftB.y
  );
};

void Body::addCollider(Entity* entity) {
  collider = entity;
}

void Body::render(SDL_Renderer* renderer) {
  if (!debug) {
    return;
  }

  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

  for (unsigned int i = 0; i < TOTAL_VERTICES - 1; i++) {
    SDL_RenderDrawLine(renderer, vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y);
  }
  // Join last line manually
  SDL_RenderDrawLine(renderer, vertices[TOTAL_VERTICES - 1].x, vertices[TOTAL_VERTICES - 1].y, vertices[0].x, vertices[0].y);

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
}
