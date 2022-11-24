#ifndef __RAY_TRACER_H__ 
#define __RAY_TRACER_H__ 1

#include <SDL/SDL.h>

#include "texture.h"

class RayTracer {
 public:
  RayTracer();
  RayTracer(const RayTracer& other) = delete;

  ~RayTracer();

  RayTracer& operator=(const RayTracer& other) = delete;

  bool init(SDL_Renderer *renderer, SDL_Window *window);
  void update();
  void draw();
  void end();

 protected:

  void onResize();

  Uint32 *pixels_;
  Texture texture_;  
  SDL_Window *window_;
  SDL_Renderer *renderer_;
  int width_;
  int height_;

};

#endif // !__RAY_TRACER_H__