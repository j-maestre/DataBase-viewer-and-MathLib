/**
 * \file oxmlsprite.h
 * \author Jose Maria Maestre Quiles <maestrequi@esat-alumni.com>
 * 
 */

#ifndef __OXMLSPRITE_H__ 
#define __OXMLSPRITE_H__ 1


#include "entity.h"
#include "texture.h"

class Sprite : public Entity{
  public:
    Sprite();
    Sprite(const Sprite& o);
    ~Sprite();

    /**
     * \brief init a sprite form a texture
     * 
     * \param tex texture
     * \param x pos x of the sprite in the texture
     * \param y pos y of the sprite in the texture
     * \param width width of the sprite
     * \param height height of the texture
     */
    void init(const Texture& tex, int x, int y, int width, int height);

    /**
     * \brief Get the Width of the sprite
     * 
     * \return int width of the sprite
     */
    int getWidth() const;

    /**
     * \brief Get the Height of the sprite
     * 
     * \return int height of the sprite
     */
    int getHeight() const;

    /**
     * \brief Get the pisel of the sprite
     * 
     * \param x pos x of the pixel
     * \param y pos y of the pixel
     * \param rgba_out rgba pf the pixel
     */
    void getPixel(int x, int y, unsigned char rgba_out[4]);
    /**
     * \brief draw the sprite
     * 
     */
    void draw() override;
  
  protected:

  public:

};

#endif