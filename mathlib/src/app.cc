#include "app.h"

App::App() {
  window_ = nullptr;
  renderer_ = nullptr;
  loop_ = nullptr;
}

App::~App() {}

App& App::Instance() {
  static App instance;
  return instance;
}

void App::init(const char *window_title, int width, int height) {
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER);
  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  window_ = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);;
  loop_ = &GameLoop::Instance();
  //ImgGi::
}

void App::run() {
  static bool runing = true;
  if (window_ != nullptr) {
    loop_->init(renderer_, window_);
    while (runing) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
          runing = false;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window_))
          runing = false;
      }
      loop_->run();
    }
    loop_->end();
  }
}

void App::end() {
  if (renderer_ != nullptr) {
    SDL_DestroyRenderer(renderer_);
  }
  if (window_ != nullptr) {
    SDL_DestroyWindow(window_);
  }
  SDL_Quit();
}