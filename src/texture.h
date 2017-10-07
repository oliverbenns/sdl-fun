#pragma once
#include <SDL2_ttf/SDL_ttf.h>

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
SDL_Texture* createText(SDL_Renderer* renderer, const char* textureText, SDL_Color textColor, TTF_Font* gFont);
