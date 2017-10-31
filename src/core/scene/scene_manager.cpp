#include "scene_manager.h"

void SceneManager::add(Scene* scene) {
  scenes[0] = scene;
};

void SceneManager::activate(int id) {
//  Scene* scene
  active = scenes[0];
};
