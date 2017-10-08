#include "delta_time.h"

DeltaTime::DeltaTime() {
  currentTime = SDL_GetPerformanceCounter();
  previousTime = 0;
  now = 0;
}

void DeltaTime::update() {
  previousTime = currentTime;
  currentTime = SDL_GetPerformanceCounter();
  now = (double)((currentTime - previousTime) * 1000 / SDL_GetPerformanceFrequency());
}
