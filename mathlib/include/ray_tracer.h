#ifndef __RAY_TRACER_H__ 
#define __RAY_TRACER_H__ 1

#include <SDL/SDL.h>

#include <oxml/Vec2.h>
#include <oxml/Vec4.h>

#include "sphere.h"
#include "texture.h"
#include "camera.h"
#include "ray.h"

class RayTracer {
 public:
  RayTracer();
  RayTracer(const RayTracer& other) = delete;

  ~RayTracer();

  RayTracer& operator=(const RayTracer& other) = delete;

  bool init(SDL_Renderer *renderer, SDL_Window *window);
  void draw(Camera& camera);
  void end();

 protected:

  void update(Camera& camera);
  void onResize(Camera& camera);
  Uint32 traceRay(const Ray& ray,const Sphere& sphere, bool &colisioned);
  oxml::Vec4 RayTracer::BlendColors(oxml::Vec4 color1,oxml::Vec4 color2);

  Uint32 *pixels_;
  Texture texture_;  
  SDL_Window *window_;
  SDL_Renderer *renderer_;
  int width_;
  int height_;

};

#endif // !__RAY_TRACER_H__