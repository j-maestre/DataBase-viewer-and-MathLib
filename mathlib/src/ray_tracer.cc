#include <math.h>
#include <stdio.h>

#include <oxml/Vec3.h>
#include <oxml/Vec4.h>
#include <oxml/Mathf.h>

#include "game_loop.h"
#include "ray_tracer.h"
#include "timer.h"

RayTracer::RayTracer() {
  pixels_ = nullptr;
  window_ = nullptr;
  renderer_ = nullptr;

}

RayTracer::~RayTracer() {}

bool RayTracer::init(SDL_Renderer *renderer, SDL_Window *window) {
  if (pixels_ == nullptr && window_ == nullptr && renderer_ == nullptr) {
    if(renderer != nullptr && window != nullptr) {
      renderer_ = renderer;
      window_ = window;
      SDL_GetWindowSize(window, &width_, &height_);
      if (!texture_.alloc(width_, height_, renderer)) {
        return false;
      }
      pixels_ = new Uint32[width_ * height_];
      return true;
    }
  }
  return false;
}

void RayTracer::onResize(Camera& camera) {
  int w, h;
  SDL_GetWindowSize(window_, &w, &h);
  if (width_ != w || height_ != h) {
    width_ = w;
    height_ = h;
    delete[] pixels_;
    pixels_ = new Uint32[width_ * height_];
    texture_.resize(width_, height_);
  }
  camera.resize(w, h);
}

oxml::Vec4 RayTracer::BlendColors(oxml::Vec4 base,oxml::Vec4 color2){
 
  oxml::Vec4 newColor;

  // Blending Multiply algoritms
  /*base.Normalize();
  color2.Normalize();
  newColor.x = (base.x * color2.x);
  newColor.y = (base.y * color2.y);
  newColor.z = (base.z * color2.z);
  newColor.w = (base.w * color2.w);
  newColor.Normalize();
  newColor *= 255.0f;*/

  // Blending Add algoritm 
  newColor.w = 1 - (1 - color2.w) * (1 - base.w);
  newColor.x = color2.x + base.x;
  newColor.y = color2.y + base.y;
  newColor.z = color2.z + base.z;

  return newColor;
}

Uint32 RayTracer::traceRay(const Ray& ray, const Sphere& sphere, bool &colisioned) {

  oxml::Vec3 lightDir = GameLoop::Instance().globalLigt_.light_direction_;
  lightDir.Normalize();

  //oxml::Vec4 sphereColor(sphere.sphereColor_);
  oxml::Vec4 sphereColor = BlendColors(sphere.sphereColor_,GameLoop::Instance().globalLigt_.color_);
  oxml::Vec3 origin = ray.origin - sphere.sphereOrigin_;
  //oxml::Vec3 sphereOrigin(oxml::Vec3::zero);
  //float radius = 0.5f;
  //printf("Color-> %f %f %f\n",sphere.sphereColor_.x);
  

  float a = ray.direction.SqrMagnitude();
  float b = 2.0f * oxml::Vec3::Dot(origin, ray.direction);
  float c = origin.SqrMagnitude() - (sphere.radius_ * sphere.radius_);

  float discriminant = b * b - 4.0f * a * c;

  if (discriminant >= 0) {
    float t0 = (-b - sqrtf(discriminant)) / (2.0f * a);
    if (t0 < 0.0f) {
      colisioned = false;
      return 0xff808080;
    }
    //float t1 = (-b + sqrtf(discriminant)) / (2.0f * a);
    oxml::Vec3 hit_point = origin + ray.direction * t0;
    oxml::Vec3 normal = hit_point - sphere.sphereOrigin_;
    normal.Normalize();
    float light = fmaxf(oxml::Vec3::Dot(normal, -lightDir), 0.0f);
    sphereColor *= light;
    sphereColor.w = 1.0f;
    colisioned = true;
    return sphereColor.ToRGBA();
  }
  colisioned = false;
  return 0xff808080;
}

void RayTracer::update(Camera& camera){
  if (pixels_ != nullptr) {
    camera.update();
    onResize(camera);
    Ray ray;
    ray.origin = camera.position_;
    const oxml::Vec3 *ray_directions = camera.ray_directions();
    //GameLoop::Instance().spheres[0].sphereOrigin_ = oxml::Vec3(-0.5f,0.0f,0.0f);
    //printf("%ffps:%fms\n", Time::fps_, Time::delta_time_);
    

      for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            ray.direction = ray_directions[x + y * width_];
            bool colisioned = false;
            for(int i = 0; i<GameLoop::Instance().sphere_size_ && !colisioned; i++){
              pixels_[x + ((height_ - 1) - y) * width_] = traceRay(ray, GameLoop::Instance().spheres[i], colisioned);
            }

        }
      }

    
    //Recorrer todas las texturas
    texture_.update(pixels_);
  }
}

void RayTracer::draw(Camera& camera) {
  update(camera);
  texture_.draw();
}

void RayTracer::end() {
  if (pixels_ != nullptr) {
    delete[] pixels_;
    pixels_ = nullptr;
  }
  window_ = nullptr;
  renderer_ = nullptr;
  texture_.free();
}