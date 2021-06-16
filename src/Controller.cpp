#include "Controller.hpp"
#include "Game.hpp"
#include "Model.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "View.hpp"

#define KEY_STOP_GAME SDL_SCANCODE_ESCAPE

Controller::Controller(Game *game)
    : game(game)
{
  printf("  Controller::Controller()\n");
}

void Controller::Finalize()
{
  printf("  Controller::Finalize()\n");
}

void Controller::Initialize()
{
  printf("  Controller::Initialize()\n");
}

void Controller::Run()
{
  // Loop through events that have accumulated since last game cycle.
  // Note that these events can trigger various cases below multiple times
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      // Game-stopping events are handled by the game.
      game->StopGame();
      break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEMOTION:
    case SDL_MOUSEWHEEL:
      // Mouse events are passed to mouseAbles (multiple times per loop).
      // MouseAble::RunAll(&event);
      break;
    case SDL_WINDOWEVENT:
      if (event.window.event == SDL_WINDOWEVENT_RESIZED)
      {
        // Window resizing events are passed to the model and view.
        game->model.Resize(event.window.data1, event.window.data2);
        game->view.Resize(event.window.data1, event.window.data2);
      }
      break;
    // case SDL_WINDOWEVENT_SIZE_CHANGED:
    //   printf("Controller::Run() ... SDL_WINDOWEVENT_SIZE_CHANGED\n");
    //   // Window resizing events are passed to the model and view.
    //   game->model.Resize(event.window.data1, event.window.data2);
    //   game->view.Resize(event.window.data1, event.window.data2);
    //   break;
    default:
      // Note: There are numerous other events that can be handled, if needed.
      break;
    }
  }

  // Get the present state of the keyboard.
  Uint8 const *keyState = SDL_GetKeyboardState(NULL);
  if (keyState[KEY_STOP_GAME]) // STOP_GAME key is specified in the Config file.
  {
    // A game-stopping keyState is handled by the game.
    game->StopGame();
  }
  else
  {
    // The keyState is passed to keyAbles (just one time per loop).
    // KeyAble::RunAll(keyState);
  }
}
