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

#include "data_base_controller.h"




int esat::main(int argc, char **argv) {
  unsigned char fps=60;
  double current_time,last_time;
  esat::WindowInit(1400, 810);
  esat::WindowSetMouseVisibility(true);

  DataBaseController& db_controller = DataBaseController::Instance();
  db_controller.OpenDB("../data/chinook.db");
  
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);


    db_controller.ShowWindow();


    esat::DrawEnd();
    do{//Control fps
    		current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    esat::WindowFrame();
  }
  esat::WindowDestroy();
  return 0;
}
