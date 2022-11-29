#include <stdio.h>

#include <oxml/Mathf.h>

#include "game_loop.h"


GameLoop& GameLoop::Instance() {
  static GameLoop inst;
  return inst;
}

GameLoop::GameLoop() : camera_((45.0f * oxml::Mathf::Deg2Rad), 0.1f, 100.0f) {
  renderer_ = nullptr;
  window_ = nullptr;
  camera_.position_.z = -30.0f;
}

GameLoop::~GameLoop() {}

void GameLoop::init(SDL_Renderer *rdr, SDL_Window *wnd) {
  renderer_ = rdr;
  window_ = wnd;
  rt_.init(renderer_, window_);
}

void GameLoop::run() {
  SDL_RenderClear(renderer_);

  rt_.draw(camera_);

  SDL_RenderPresent(renderer_);
}

void GameLoop::end() {
  rt_.end();
}
