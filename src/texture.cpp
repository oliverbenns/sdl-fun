#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
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


SDL_Texture* createText(SDL_Renderer* renderer, const char* textureText, SDL_Color textColor, TTF_Font* gFont) {
  SDL_Texture* texture;
  //Get rid of preexisting texture
  // free();

  //Render text surface
  SDL_Surface* surface = TTF_RenderText_Solid( gFont, textureText, textColor );
  if(surface == NULL) {
    printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
  }
  else {
    //Create texture from surface pixels
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
      printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
    } else {
      //Get image dimensions
      // mWidth = surface->w;
      // mHeight = surface->h;
    }

    //Get rid of old surface
    SDL_FreeSurface(surface);
  }

  return texture;

  //Return success
  // return mTexture != NULL;
}
