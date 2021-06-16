#include <emscripten.h>
#include "Game.hpp"
#include <stdio.h>

extern void run();

Game::Game()
    : controller(this),
      model(this),
      view(this)
{
  printf("Game::Game()\n");
  if (Initialize())
  {
    emscripten_set_main_loop(run, 0, 0);
    printf("\nGame::Run() ...\n");
  }
}

void Game::Finalize()
{
  printf("\nGame::Finalize()\n");
  emscripten_cancel_main_loop();
  controller.Finalize();
  model.Finalize();
  view.Finalize();
}

bool Game::Initialize()
{
  printf("\nGame::Initialize()\n");
  if (view.Initialize())
  {
    controller.Initialize();
    model.Initialize();
    return true;
  }
  return false;
}

void Game::Run()
{
  if (isRunning)
  {
    controller.Run();
    model.Run();
    view.Run();
  }
  else
  {
    Finalize();
  }
}

void Game::StopGame()
{
  printf("\nGame::StopGame()\n");
  isRunning = false;
}
