
#ifndef __OXMLSPRITE_H__ 
#define __OXMLSPRITE_H__ 1


#include "entity.h"
#include "texture.h"

class Sprite : public Entity{
  public:
    Sprite();
    Sprite(const Sprite& o);
    ~Sprite();

    void init(const Texture& tex, int x, int y, int width, int height);

    int getWidth() const;
    int getHeight() const;

    void getPixel(int x, int y, unsigned char rgba_out[4]);
    void draw() override;
  
  protected:

  public:

};

#endif