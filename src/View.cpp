#include "Game.hpp"
// #include <emscripten/html5.h>
#include <stdio.h>
#include "View.hpp"

#define INIT_SDL_FLAGS SDL_INIT_VIDEO
#define TITLE "Asteroids"
#define WINDOW_DIM_X 800
#define WINDOW_DIM_Y 600
// #define INIT_WINDOW_FLAGS SDL_WINDOW_FULLSCREEN
// #define INIT_WINDOW_FLAGS SDL_WINDOW_MAXIMIZED
#define INIT_WINDOW_FLAGS SDL_WINDOW_RESIZABLE

View::View(Game *game)
    : game(game)
{
  printf("  View::View()\n");
}

void View::Finalize()
{
  printf("  View::Finalize()\n");
}

bool View::Initialize()
{
  printf("  View::Initialize()\n");

  if (SDL_Init(INIT_SDL_FLAGS) != 0)
  {
    SDL_Log("ERROR -- SDL_Init(): %s", SDL_GetError());
    return false;
  }

  if (SDL_CreateWindowAndRenderer(WINDOW_DIM_X, WINDOW_DIM_Y, INIT_WINDOW_FLAGS,
                                  &window, &renderer) != 0)
  {
    SDL_Log("ERROR -- SDL_CreateWindowAndRenderer(): %s", SDL_GetError());
    return true;
  }
  int w, h;
  SDL_GetWindowSize(window, &w, &h);
  printf("WINDOW SIZE IS %d, %d\n", w, h);
  return true;
}

void View::Resize(int width, int height)
{
  printf("-----------------------------------\n");
  printf("View::HTML says window is: %d, %d\n", width, height);

  // Destroy the window's rendering context / free associated textures
  SDL_DestroyRenderer(renderer);
  // Destroy the SDL window
  SDL_DestroyWindow(window);

  if (SDL_CreateWindowAndRenderer(width, height, INIT_WINDOW_FLAGS,
                                  &window, &renderer) != 0)
  {
    SDL_Log("ERROR -- SDL_CreateWindowAndRenderer(): %s", SDL_GetError());
  }

  game->model.background->Resize(renderer, width, height);

  int w, h;
  SDL_GetRendererOutputSize(renderer, &w, &h);
  printf("SDL says renderer is %d, %d\n", w, h);
  // SDL_SetWindowSize(window, width, height);
  // printf(" - - - -\n");
  // printf("After forcing resize, SDL says window is %d, %d\n", w, h);
  // SDL_SetWindowSize(window, width, height);
}

void View::Run()
{
  printf("Run\n");
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  game->model.background->Run();

  SDL_Rect rect1{20, 20, 280, 160};
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  SDL_RenderFillRect(renderer, &rect1);

  SDL_RenderPresent(renderer);
}
