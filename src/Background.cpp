#include "Background.hpp"
#include <SDL2/SDL_image.h>
#include <stdio.h>

// #define BACKGROUND_IMG "images/background.jpg"

Background::Background(SDL_Renderer *renderer)
    : renderer(renderer)
{
  printf("    Background::Background()\n");
  SDL_Surface *surface = IMG_Load("images/background.jpg");
  if (!surface)
  {
    SDL_Log("ERROR -- IMG_Load(%s)", "images/background.jpg");
    texture = nullptr;
    return;
  }
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  if (!texture)
  {
    SDL_Log("ERROR -- SDL_CreateTextureFromSurface(%s)",
            "images/background.jpg");
    texture = nullptr;
    return;
  }
}

void Background::Resize(SDL_Renderer *renderer, int width, int height)
{
  this->width = width;
  this->height = height;
  this->renderer = renderer;

  SDL_DestroyTexture(texture);

  SDL_Surface *surface = IMG_Load("images/background.jpg");
  if (!surface)
  {
    SDL_Log("ERROR -- IMG_Load(%s)", "images/background.jpg");
    texture = nullptr;
    return;
  }
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  if (!texture)
  {
    SDL_Log("ERROR -- SDL_CreateTextureFromSurface(%s)",
            "images/background.jpg");
    texture = nullptr;
    return;
  }
}

void Background::Run()
{
  SDL_Rect rect{0, 0, width, height};
  SDL_RenderCopyEx(renderer, texture, nullptr, &rect, 0, nullptr,
                   SDL_FLIP_NONE);
}