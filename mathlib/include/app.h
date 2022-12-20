/**
 * \file app.h
 * \author Hector Ochando <ochandoca@esat-alumni.com>
 * 
 */
#ifndef __APP_H__
#define __APP_H__ 1

#include <SDL/SDL.h>

#include "game_loop.h"

class App final {
 public:

  /**
   * \brief The unique instance of the class App
   * 
   * \return App& 
   */
  static App& Instance();

  ~App();

  /**
   * \brief Starts the app
   * 
   * \param window_title The title of thw window
   * \param width Width of the window
   * \param height Height of the window
   */
  void init(const char *window_title, int width, int height);

  /**
   * \brief Run the app
   * 
   */
  void run();

  /**
   * \brief End the app
   * 
   */
  void end();

  //Pointer to the window
  SDL_Window *window_;
  //Pointer to the renderer
  SDL_Renderer *renderer_;
  //Pointer to the game loop
  GameLoop *loop_;

 private:
  App();
  App(const App& other) = delete;

};

#endif