#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "scene_manager.h"
#include "window.h"

struct Game {
  Game();
  bool init();
  void quit();
  void update();

  bool running = true;
  SceneManager sceneManager;
  Window* window;
};
