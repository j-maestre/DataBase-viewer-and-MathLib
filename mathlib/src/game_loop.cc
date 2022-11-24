#include <stdio.h>
#include "game_loop.h"


GameLoop& GameLoop::Instance() {
  static GameLoop inst;
  return inst;
}

GameLoop::GameLoop() {
  renderer_ = nullptr;
  window_ = nullptr;
}

GameLoop::~GameLoop() {}

void GameLoop::init(SDL_Renderer *rdr, SDL_Window *wnd) {
  renderer_ = rdr;
  window_ = wnd;
}

void GameLoop::run() {
  SDL_RenderClear(renderer_);

  

  SDL_RenderPresent(renderer_);
}

void GameLoop::end() {
}
