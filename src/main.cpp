/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
// #include "texture.h"
#include "window_context.h"
#include "game_object.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

WindowContext context;
// SDL_Texture* buttonTexture;
// SDL_Rect srcR;
// SDL_Rect destR;

GameObject button;



bool init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  } else {
    createWindowContext(&context, 800, 600);
  }

  return success;
}

bool loadMedia() {
  // Loading success flag
  bool success = true;

  createGameObject(&button, context.renderer, "button.bmp");

  //Load default surface
  // buttonTexture = loadTexture(context.renderer, "button.bmp");

  // if (buttonTexture == NULL) {
  //   printf( "Failed to load button image!\n" );
  //   success = false;
  // }

  return success;
}

void close() {
  destroyWindowContext(&context);
  SDL_Quit();
}

int main(int argc, char* args[]) {
  // Start up SDL and create window
  if(!init()) {
    printf( "Failed to initialize!\n" );
  } else {
    // Load media
    if(!loadMedia()) {
      printf( "Failed to load media!\n" );
    } else {
      // Main loop flag
      bool quit = false;

      // Event handler
      SDL_Event e;

      while(!quit) {
        // Handle events on queue
        while( SDL_PollEvent(&e) != 0 ) {
          //User requests quit
          if (e.type == SDL_QUIT) {
            quit = true;
          }
        }

        // int w;
        // int h;

        // SDL_QueryTexture(buttonTexture, NULL, NULL, &w, &h);

        // destR.h = h;
        // destR.w = w;

        //Clear screen
        SDL_RenderClear(context.renderer);


        renderGameObject(&button);

        //Render texture to screen
        // SDL_RenderCopy(context.renderer, buttonTexture, NULL, &destR);

        // SDL_RenderCopy(button.renderer, button.texture, NULL, &button.rect);

        //Update screen
        SDL_RenderPresent(context.renderer);
      }
    }
  }

  //Free resources and close SDL
  close();

  return 0;
}
