#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL/SDL.h>

class Texture {
 public:
  Texture();
  Texture(const Texture& other) = delete;

  ~Texture();

  Texture& operator=(const Texture& other) = delete;

  /**
   * \brief alloc a texture with a width and a height
   * 
   * \param width width of the texture
   * \param height height of the texture
   * \param rdr renderer 
   * \return true if the texture has been alocated correctly
   * \return false if the texture hasn't been alocated correctly
   */
  bool alloc(int width, int height, SDL_Renderer *rdr);
  /**
   * \brief alloc a texture with a width and a height
   * 
   * \param width width of the texture
   * \param height height of the texture
   * \param rdr renderer 
   * \param pixels pixel buffer
   * \return true if the texture has been alocated correctly
   * \return false if the texture hasn't been alocated correctly
   */
  bool alloc(int width, int height, SDL_Renderer *rdr, Uint32 *pixels);
  /**
   * \brief resize the texture
   * 
   * \param width the new width of the texture
   * \param height the height  of the texture
   * \return true if the texture has been resized correctly
   * \return false if the texture hasn't been resized correctly
   */
  bool resize(int width, int height);
  /**
   * \brief update the texture from a pixel buffer
   * 
   * \param pixels buffer pixel
   * \return true if the texture has updated correctly
   * \return false if the texture hasn't updated correctly
   */
  bool update(Uint32 *pixels);

  /**
   * \brief draw the texture
   * 
   */
  void draw();

  /**
   * \brief free the data of the texture
   * 
   */
  void free();

 protected:

  SDL_Renderer *renderer_;
  SDL_Texture *texture_;
  int width_;
  int height_;

};

#endif