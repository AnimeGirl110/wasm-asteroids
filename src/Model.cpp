#include "Asteroid.hpp"
#include "Game.hpp"
#include "Model.hpp"
#include <stdio.h>

#define NUM_ASTEROIDS 10

Model::Model(Game *game)
    : game(game)
{
  printf("  Model::Model()\n");
}

void Model::Finalize()
{
  printf("  Model::Finalize()\n");
  // TODO: Delete all remaining asteroids
}

void Model::Initialize()
{
  printf("  Model::Initialize()\n");
  background = new Background(game->view.GetRenderer());
  for (int i = 0; i < NUM_ASTEROIDS; ++i)
  {
    asteroids.emplace_back(new Asteroid());
  }
}

void Model::Resize(int width, int height)
{
  printf("Model::Resize(%d, %d)", width, height);
}

void Model::Run() {}
