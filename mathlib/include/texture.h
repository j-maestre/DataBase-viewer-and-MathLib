#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL/SDL.h>

class Texture {
 public:
  Texture();
  Texture(const Texture& other) = delete;

  ~Texture();

  Texture& operator=(const Texture& other) = delete;

  bool alloc(int width, int height, SDL_Renderer *rdr);
  bool alloc(int width, int height, SDL_Renderer *rdr, Uint32 *pixels);
  bool onResize(int width, int height);
  bool update(Uint32 *pixels);
  void draw();
  void free();

 protected:

  SDL_Renderer *renderer_;
  SDL_Texture *texture_;
  int width_;
  int height_;

};

#endif