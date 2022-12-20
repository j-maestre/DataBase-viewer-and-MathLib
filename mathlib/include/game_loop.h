/**
 * \file game_loop.h
 * \author Hector Ochando <ochandoca@esat-alumni.com>
 * 
 */

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

  /**
   * \brief init the game loop
   * 
   * \param rdr pointer to the renderer of the app
   * \param wnd pointer to the window of the app
   */
  void init(SDL_Renderer *rdr, SDL_Window *wnd);

  /**
   * \brief runs the game loop
   * 
   */
  void run();

  /**
   * \brief end the game loop
   * 
   */
  void end();

  /**
   * \brief short the spheres from closer to furder
   * 
   */
  void orderSpheres();

  /**
   * \brief realoc the spheres pointer to the new size
   * 
   * \param new_size the new number of the spheres
   */
  void ReallocSpheres(int new_size);

  //size of the spheres pointer
  int sphere_size_;
  //pointer to the all spheres
  Sphere *spheres_;
  //the direcional light of the scene
  DirectionalLight globalLigt_;

 private:

  GameLoop();
  GameLoop(const GameLoop& other) = delete;

  GameLoop& operator =(const GameLoop& other) = delete;

  //pointer to the renderer of the window
  SDL_Renderer *renderer_;
  //pointer to the window
  SDL_Window *window_;
  
  //the raytracer of the app
  RayTracer rt_;
  //the camera of the app
  Camera camera_;
  //the performance window
  PerformanceWindow pw_;

};

#endif // !__GAME_LOOP_H__