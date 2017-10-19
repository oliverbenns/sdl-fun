#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "body.h"
#include "input.h"
#include "sprite.h"

struct Entity;

Entity* createPlayer(SDL_Renderer* renderer);

Entity* createFloor(SDL_Renderer* renderer);
