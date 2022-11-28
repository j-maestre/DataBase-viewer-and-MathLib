#include <math.h>

#include <oxml/Vec3.h>
#include <oxml/Vec4.h>

#include "ray_tracer.h"

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

void RayTracer::onResize() {
  int w, h;
  SDL_GetWindowSize(window_, &w, &h);
  if (width_ != w || height_ != h) {
    width_ = w;
    height_ = h;
    delete[] pixels_;
    pixels_ = new Uint32[width_ * height_];
    texture_.resize(width_, height_);
  }
}

Uint32 RayTracer::perPixel(const oxml::Vec2& coord) {
  oxml::Vec3 ray_origin(0.0f, 0.0f, -2.0f);
  oxml::Vec3 ray_direction(coord, -1.0f);

  oxml::Vec3 lightDir(-1.0f, -1.0f, -1.0f);
  lightDir.Normalize();

  oxml::Vec4 sphereColor(1.0f, 0.0f, 1.0f, 1.0f);
  oxml::Vec3 sphereOrigin(oxml::Vec3::zero);
  float radius = 0.5f;

  float a = ray_direction.SqrMagnitude();
  float b = 2.0f * oxml::Vec3::Dot(ray_origin, ray_direction);
  float c = ray_origin.SqrMagnitude() - (radius * radius);

  float discriminant = b * b - 4.0f * a * c;

  if (discriminant >= 0) {
    float t0 = (-b - sqrtf(discriminant)) / (2.0f * a);
    //float t1 = (-b + sqrtf(discriminant)) / (2.0f * a);
    oxml::Vec3 hit_point = ray_origin + ray_direction * t0;
    oxml::Vec3 normal = hit_point - sphereOrigin;
    normal.Normalize();
    float light = fmaxf(oxml::Vec3::Dot(normal, -lightDir), 0.0f);
    sphereColor *= light;
    sphereColor.w = 1.0f;
    return sphereColor.ToRGBA();
  }
  return 0xff000000;
}

void RayTracer::update() {
  if (pixels_ != nullptr) {
    onResize();
    //TODO: pixel treatment
    for (int y = 0; y < height_; y++) {
      for (int x = 0; x < width_; x++) {
        oxml::Vec2 coord(x / (float)width_, y / (float)height_);
        coord = (coord * 2.0f) - 1.0f;
        pixels_[((width_-1) - x) + y * width_] = perPixel(coord);
      }
    }
    texture_.update(pixels_);
  }
}

void RayTracer::draw() {
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