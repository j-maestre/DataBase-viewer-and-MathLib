#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <esat/sprite.h>

class Texture {
 public:
  Texture();
  Texture(const Texture& other);
  ~Texture();

  void init(const char *filename);
  void init(int width, int height, unsigned char* pixels);

  int getWidth() const;
  int getHeight() const;

  esat::SpriteHandle getSubSprite(int x, int y, int width, int height) const;

 protected:
  esat::SpriteHandle handle_;

};

#endif