#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "input.h"
#include "sprite.h"

struct Entity;

Entity* createPlayer(SDL_Renderer* renderer);
