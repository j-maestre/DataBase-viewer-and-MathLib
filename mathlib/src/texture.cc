#include <stdio.h>

#include "texture.h"

Texture::Texture() {
  texture_ = nullptr;
  renderer_ = nullptr;
}

Texture::~Texture() {}

bool Texture::alloc(int width, int height, SDL_Renderer *rdr) {
  if (width > 0 && height > 0) {
    if (texture_ == nullptr && rdr != nullptr) {
      texture_ = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
      width_ = width;
      height_ = height;
      renderer_ = rdr;
      return true;
    }
  }
  return false;
}

bool Texture::alloc(int width, int height, SDL_Renderer *rdr, Uint32 *pixels) {
  if (pixels != nullptr && alloc(width, height, rdr)) {
    SDL_UpdateTexture(texture_, NULL, pixels, 4 * width_);
    return true;
  }
  return false;
}

bool Texture::onResize(int width, int height) {
  if (width > 0 && height > 0) {
    if (texture_ != nullptr) {
      if (width_ != width || height_ != height) {
        SDL_DestroyTexture(texture_);
        texture_ = nullptr;
        alloc(width, height, renderer_);
        return true;
      }
    }
  }
  return false;
}

bool Texture::update(Uint32 *pixels) {
  if (texture_ != nullptr && pixels != nullptr) {
    return SDL_UpdateTexture(texture_, NULL, pixels, 4 * width_) == 0;
  }
  return false;
}

void Texture::draw() {
  if (renderer_ != nullptr && texture_ != nullptr) {
    SDL_RenderCopy(renderer_, texture_, NULL, NULL);
  }
}

void Texture::free() {
  if (texture_ != nullptr) {
    SDL_DestroyTexture(texture_);
  }
  texture_ = nullptr;
  renderer_ = nullptr;
}