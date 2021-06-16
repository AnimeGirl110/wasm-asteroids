#include "Asteroid.hpp"
#include <stdio.h>

#define NUM_SIZES 4
#define SIZE_FACTOR 40

Asteroid::Asteroid()
    : size(NUM_SIZES),
      dimX(size * SIZE_FACTOR),
      dimY(dimX),
      posX(0),
      posY(0)
{
  printf("    Asteroid::Asteroid()\n");
}

Asteroid::Asteroid(Asteroid *parent)
    : size(parent->GetSize() - 1),
      dimX(size * SIZE_FACTOR),
      dimY(dimX),
      posX(GetPosX()),
      posY(GetPosY())
{
  printf("    Asteroid::Asteroid(Asteroid *)\n");
}
