#ifndef __GAME_LOOP_H__
#define __GAME_LOOP_H__ 1

#include <SDL/SDL.h>

#include "ray_tracer.h"
#include "sphere.h"
#include "directional_light.h"
#include "performance_window.h"

class GameLoop final {
 public:
  
  static GameLoop& Instance();

  ~GameLoop();

  void init(SDL_Renderer *rdr, SDL_Window *wnd);
  void run();
  void end();
  void orderSpheres();
  int sphere_size_;
  Sphere *spheres;
  DirectionalLight globalLigt_;

 private:

  GameLoop();
  GameLoop(const GameLoop& other) = delete;

  GameLoop& operator =(const GameLoop& other) = delete;

  SDL_Renderer *renderer_;
  SDL_Window *window_;
  
  RayTracer rt_;
  Camera camera_;
  PerformanceWindow pw_;

};

#endif // !__GAME_LOOP_H__