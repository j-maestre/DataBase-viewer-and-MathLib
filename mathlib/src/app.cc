#include <stdio.h>

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_sdl.h>
#include <ImGui/imgui_impl_sdlrenderer.h>

#include "app.h"
#include "timer.h"
#include "camera.h"

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
  ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(window_, renderer_);
  ImGui_ImplSDLRenderer_Init(renderer_);
}

void App::run() {
  static bool runing = true;
  if (window_ != nullptr) {
    loop_->init(renderer_, window_);
    SDL_Event event;
    while (runing) {
      Time::last_time_ = (float) SDL_GetTicks64();
      while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
          runing = false;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && 
            event.window.windowID == SDL_GetWindowID(window_))
          runing = false;

          if(event.type == SDL_MOUSEBUTTONDOWN){
            //printf("Click\n");
            Camera::mouse_clicked = true;
          }
          if(event.type == SDL_MOUSEBUTTONUP){
            Camera::mouse_clicked = false;
          }
      }
      loop_->run();
      Time::current_time_ = (float) SDL_GetTicks64();
      Time::delta_time_ = (Time::current_time_ - Time::last_time_) / 1000.0f;
      Time::fps_ = (1.0f / Time::delta_time_);
    }
    loop_->end();
  }
}

void App::end() {
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
  if (renderer_ != nullptr) {
    SDL_DestroyRenderer(renderer_);
  }
  if (window_ != nullptr) {
    SDL_DestroyWindow(window_);
  }
  SDL_Quit();
}