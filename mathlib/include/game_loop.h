#ifndef __GAME_LOOP_H__
#define __GAME_LOOP_H__ 1

#include <SDL/SDL.h>

#include "texture.h"

class GameLoop final {
 public:
  
  static GameLoop& Instance();

  ~GameLoop();

  void init(SDL_Renderer *rdr, SDL_Window *wnd);
  void run();
  void end();

 private:

  SDL_Renderer *renderer_;
  SDL_Window *window_;


  GameLoop();
  GameLoop(const GameLoop& other) = delete;

  GameLoop& operator =(const GameLoop& other) = delete;

};

#endif // !__GAME_LOOP_H__