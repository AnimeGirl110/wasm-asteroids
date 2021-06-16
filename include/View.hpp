#pragma once
#include <SDL2/SDL.h>

class View
{
public:
  View(class Game *game);

  void Finalize();
  SDL_Renderer *GetRenderer() { return renderer; }
  bool Initialize();
  void Resize(int width, int height);
  void Run();

private:
  class Game *game;
  SDL_Window *window;
  SDL_Renderer *renderer;
};
