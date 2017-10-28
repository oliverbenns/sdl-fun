#include <SDL2/SDL.h>

struct DeltaTime {
  DeltaTime();
  void update();

  Uint64 currentTime;
  Uint64 previousTime;

  // @TODO: Make this a float instead?
  double now;
};
