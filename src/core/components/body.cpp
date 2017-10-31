#include "body.h"
#include "entity.h"

enum Vertices {
  TOP_LEFT,
  TOP_RIGHT,
  BOTTOM_RIGHT,
  BOTTOM_LEFT,
  TOTAL_VERTICES,
};

Body::Body(Entity* entity) : Component(entity) {
  // Gravity!
  velocity.y = 1;
  width = 50;
  height = 50;
};

void Body::preUpdate(double deltaTime) {
  vertices[TOP_LEFT] = Vector(entity->x, entity->y);
  vertices[TOP_RIGHT] = Vector(entity->x + width, entity->y);
  vertices[BOTTOM_RIGHT] = Vector(entity->x + width, entity->y + height);
  vertices[BOTTOM_LEFT] = Vector(entity->x, entity->y + height);
}

void Body::update(double deltaTime) {
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
bool Body::isCollidingWith(Entity* collider) {
  return !(
    vertices[BOTTOM_RIGHT].x < collider->body->vertices[TOP_LEFT].x ||
    vertices[TOP_LEFT].x > collider->body->vertices[BOTTOM_RIGHT].x ||
    vertices[TOP_LEFT].y > collider->body->vertices[BOTTOM_RIGHT].y ||
    vertices[BOTTOM_RIGHT].y < collider->body->vertices[TOP_LEFT].y
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
