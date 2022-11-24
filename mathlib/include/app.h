#ifndef __APP_H__
#define __APP_H__ 1

#include <SDL/SDL.h>

#include "game_loop.h"

class App final {
 public:

  static App& Instance();

  ~App();

  void init(const char *window_title, int width, int height);
  void run();
  void end();

  SDL_Window *window_;
  SDL_Renderer *renderer_;
  GameLoop *loop_;

 private:
  App();
  App(const App& other) = delete;

};

#endif