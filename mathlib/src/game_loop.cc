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
  rt_.init(renderer_, window_);
}

void GameLoop::run() {
  SDL_RenderClear(renderer_);

  rt_.update();
  rt_.draw();

  SDL_RenderPresent(renderer_);
}

void GameLoop::end() {
  rt_.end();
}
