#include "Game.hpp"
#include <stdio.h>

Game game;

extern "C"
{
  void resize(int width, int height)
  {
    game.view.Resize(width, height);
  }
}

void run()
{
  game.Run();
}

int main() {}
