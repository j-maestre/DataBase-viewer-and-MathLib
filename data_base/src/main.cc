#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include "data_base_controller.h"



void RenderFPS(double current_time, double last_time) {
  static bool showfps = false;
  if(esat::IsSpecialKeyDown(esat::kSpecialKey_F1)){
    showfps = !showfps;
  }

  if(showfps){
    double fps = 1000.0 / (current_time - last_time);
    std::stringstream ss;
    ss << "FPS = " << std::setprecision(2) << std::fixed << fps;
    esat::DrawSetFillColor(0, 255, 255, 255);
    esat::DrawSetStrokeColor(0, 255, 255);
    esat::DrawSetTextSize(40);
    esat::DrawText(10, 30, ss.str().c_str());
    esat::DrawLine(50,50,100,100);
    //printf("%s\n",ss.str().c_str());
  } 
}


int esat::main(int argc, char **argv) {
  srand(NULL);
  unsigned int fps=400;
  double current_time,last_time;
  esat::WindowInit(1400, 810);
  esat::DrawSetTextFont("test.ttf");
  esat::DrawSetTextSize(25);
  esat::WindowSetMouseVisibility(true);

  DataBaseController& db_controller = DataBaseController::Instance();
  //db_controller.OpenDB("../data/chinook2.db");
  
  
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);


    db_controller.MainWindow();
    //ImGui::ShowDemoWindow();

    do{//Control fps
    		current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
    RenderFPS(current_time, last_time);
    esat::DrawEnd();
    esat::WindowFrame();
  }
  esat::WindowDestroy();
  return 0;
}
