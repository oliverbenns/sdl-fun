#pragma once

#include "scene.h";

struct SceneManager {

  void add(Scene* scene);
  void activate(int id);
  void remove();
  // void update();

  Scene* scenes[3];
  Scene* active;
};
