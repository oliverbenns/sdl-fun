#include "body.h"

Body::Body() {
  // Gravity!
  velocity.y = 1;
  width = 50;
  height = 50;

};

void Body::update(double deltaTime) {
  if (gravity) {
    entity->x += velocity.x;
    entity->y += velocity.y;
  }

  if (collider == nullptr) {
    return;
  }

  Vector topLeft(entity->x, entity->y);
  Vector bottomRight(entity->x + width, entity->y + height);

  Vector topLeftB(collider->x, collider->y);

  Vector bottomRightB(collider->x + collider->body->width, collider->y + collider->body->height);
  // AABB
  if (bottomRight.x < topLeftB.x || topLeft.x > bottomRightB.x || topLeft.y > bottomRightB.y || bottomRight.y < topLeftB.y) {
    printf("Not Colliding\n");
  } else {
    printf("COLLIDING!!\nwd");

  }

};

void Body::addCollider(Entity* entity) {
  // printf("testing...");

  collider = entity;

}

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

  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0x00, 0xFF );
}
