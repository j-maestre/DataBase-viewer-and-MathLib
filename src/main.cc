#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>




int esat::main(int argc, char **argv) {
  unsigned char fps=60;
  double current_time,last_time;
  esat::WindowInit(1400, 810);
  esat::WindowSetMouseVisibility(true);

 

  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    

    esat::DrawEnd();
    do{//Control fps
    		current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    esat::WindowFrame();
  }
  esat::WindowDestroy();
  return 0;
}
