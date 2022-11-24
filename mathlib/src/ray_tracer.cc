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
    texture_.onResize(width_, height_);
  }
}

void RayTracer::update() {
  if (pixels_ != nullptr) {
    onResize();
    //TODO: pixel treatment
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