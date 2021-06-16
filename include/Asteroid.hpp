#pragma once

class Asteroid
{
public:
  Asteroid();
  Asteroid(Asteroid *parent);

  int GetSize() { return size; }
  float GetPosX() { return posX; }
  float GetPosY() { return posY; }

private:
  int size;
  float dimX;
  float dimY;
  float posX;
  float posY;
};
