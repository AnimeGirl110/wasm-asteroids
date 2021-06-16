#pragma once

class Controller
{
public:
  Controller(class Game *game);

  void Finalize();
  void Initialize();
  void Run();

private:
  class Game *game;
};
