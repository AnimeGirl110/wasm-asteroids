#pragma once
#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"

class Game
{
public:
  Game();

  void Run();
  void StopGame();

  Controller controller;
  Model model;
  View view;

private:
  void Finalize();
  bool Initialize();

  bool isRunning = true;
};
