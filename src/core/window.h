#pragma once

class Window {
  public:
    Window(int width, int height);
    bool init();
    virtual ~Window();
    void close();

    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
};
