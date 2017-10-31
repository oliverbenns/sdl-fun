	#pragma once

struct Entity;

struct Component {
  Component(Entity* entity) : entity(entity) {};

  unsigned int id;
  bool active;
  Entity* entity;

  virtual void preUpdate(double deltaTime) {};
  virtual void update(double deltaTime) {};
};
