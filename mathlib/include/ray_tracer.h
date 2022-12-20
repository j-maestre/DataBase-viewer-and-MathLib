/**
 * \file ray_tracer.h
 * \author Hector Ochando <ochandoca@esat-alumni.com>
 * 
 */

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

  /**
   * \brief init the ray tracer with the renderer and de windo of the app
   * 
   * \param renderer renderer of the window
   * \param window window of the app
   * \return true if the init has done his job
   * \return false if the init hasn't done his job
   */
  bool init(SDL_Renderer *renderer, SDL_Window *window);
  /**
   * \brief draw the pixels
   * 
   * \param camera point of view
   */
  void draw(Camera& camera);
  /**
   * \brief end the ray tracer
   * 
   */
  void end();

  void add_sphere(Sphere *sphere);

 protected:

  /**
   * \brief update the pixels of the ray tracer
   * 
   * \param camera 
   */
  void update(Camera& camera);

  /**
   * \brief resize the pixel buffer
   * 
   * \param camera point of view
   */
  void onResize(Camera& camera);

  /**
   * \brief calcule the color of the pixel
   * 
   * \param ray ray throughth the pixel
   * \param sphere sphere to calcule the intersection
   * \param colisioned id ray colisioned with the sphere
   * \return Uint32 pixel color
   */
  Uint32 traceRay(const Ray& ray,const Sphere& sphere, bool &colisioned);

  void clean_buffer();

  /**
   * \brief blend the color between two clolrs
   * 
   * \param color1 
   * \param color2 
   * \return oxml::Vec4 the resultant color
   */
  oxml::Vec4 RayTracer::BlendColors(oxml::Vec4 color1,oxml::Vec4 color2);

  //pixel buffer
  Uint32 *pixels_;
  //texture has been updated with the pixel buffer
  Texture texture_;  
  //pointer to the window
  SDL_Window *window_;
  //pointer to the renderer
  SDL_Renderer *renderer_;
  //width of the window
  int width_;
  //height of the window
  int height_;
  //buffer of spheres
  Sphere **spheres_;
  //lenght of spheres buffer
  unsigned int numer_spheres_;

};

#endif // !__RAY_TRACER_H__