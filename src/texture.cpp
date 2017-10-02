#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include "texture.h"

SDL_Texture* loadTexture(SDL_Renderer * renderer, std::string path) {
  //The final texture
  SDL_Texture* newTexture = NULL;
  //Load image at specified path
  SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

  if (loadedSurface == NULL) {
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError() );
  } else {
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
      printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  return newTexture;
}
