#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include "texture.h"

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path) {
  //The final texture
  SDL_Texture* newTexture = NULL;
  //Load image at specified path
  SDL_Surface* loadedSurface = SDL_LoadBMP(path);

  if (loadedSurface == NULL) {
    printf( "Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError() );
  } else {
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
      printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  return newTexture;
}
