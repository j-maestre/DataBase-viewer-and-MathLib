#include <stdio.h>
#include <stdlib.h>

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
  spheres[0].sphereOrigin_ = oxml::Vec3(-0.5f,0.0f,-0.5f);
  spheres[0].tag_ = 0;
  spheres[1].sphereOrigin_ = oxml::Vec3(0.0f,0.0f,0.0f);
  spheres[1].tag_ = 1;
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
  char buff[20];
  itoa(spheres[0].tag_,buff,10);
  spheres[0].sphereSettings(buff);
  itoa(spheres[1].tag_,buff,10);
  spheres[1].sphereSettings(buff);
  orderSpheres();


  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
  SDL_RenderPresent(renderer_);
}

void GameLoop::end() {
  rt_.end();
}

void GameLoop::orderSpheres(){
 
// A function to implement bubble sort

    int i, j;
    for (i = 0; i < sphere_size_ - 1; i++){
        // Last i elements are already in place
        for (j = 0; j < sphere_size_ - i - 1; j++){
          if (spheres[j].sphereOrigin_.z > spheres[j + 1].sphereOrigin_.z){
            Sphere temp = spheres[j];
            spheres[j] = spheres[j + 1];
            spheres[j + 1] = temp;
            
          }
        }
    }
}
