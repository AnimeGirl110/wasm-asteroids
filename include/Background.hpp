#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

class Background
{
public:
  Background(SDL_Renderer *renderer);

  void Resize(SDL_Renderer *renderer, int width, int height);
  void Run();

private:
  static std::unordered_map<std::string, SDL_Texture *> textures;

  SDL_Renderer *renderer;
  SDL_Texture *texture;
  int width = 1;
  int height = 1;
};
