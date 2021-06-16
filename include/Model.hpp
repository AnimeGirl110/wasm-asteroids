#pragma once
#include "Background.hpp"
#include <vector>

class Model
{
public:
  Model(class Game *game);

  void Finalize();
  void Initialize();
  void Resize(int width, int height);
  void Run();

  Background *background;

private:
  class Game *game;
  std::vector<class Asteroid *> asteroids;
};
