#include <stdio.h>

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_sdl.h>
#include <ImGui/imgui_impl_sdlrenderer.h>

#include <oxml/Mathf.h>

#include "sphere.h"
#include "game_loop.h"


GameLoop& GameLoop::Instance() {
  static GameLoop inst;
  return inst;
}

GameLoop::GameLoop() : camera_((45.0f * oxml::Mathf::Deg2Rad), 0.1f, 100.0f) {
  renderer_ = nullptr;
  window_ = nullptr;
  camera_.position_.z = -2.0f;
}

GameLoop::~GameLoop() {}

void GameLoop::init(SDL_Renderer *rdr, SDL_Window *wnd) {
  renderer_ = rdr;
  window_ = wnd;
  sphere_size_ = 2;
  rt_.init(renderer_, window_);
  //spheres = (Sphere*) malloc(sizeof(Sphere)*sphere_size_);
  spheres = new Sphere[sphere_size_];
  spheres[0].sphereOrigin_ = oxml::Vec3(-0.5f,0.0f,0.0f);
  spheres[1].sphereOrigin_ = oxml::Vec3(0.0f,0.0f,0.0f);
  //spheres[0] = new Sphere();
}

void GameLoop::run() {
  SDL_RenderClear(renderer_);
  ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(window_);
  ImGui::NewFrame();

  pw_.draw();
  rt_.draw(camera_);
  camera_.cameraSettings();


  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
  SDL_RenderPresent(renderer_);
}

void GameLoop::end() {
  rt_.end();
}
