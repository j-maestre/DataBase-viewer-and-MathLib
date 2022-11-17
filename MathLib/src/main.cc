#include <stdio.h>
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <xemath/path.h>



int esat::main(int argc, char **argv) {
  srand(NULL);
  unsigned int fps=400;
  double current_time,last_time;
  esat::WindowInit(1400, 810);
  esat::WindowSetMouseVisibility(true);

  float *points = (float*) malloc(sizeof(float)*8);
  points[0] = 100.0f;
  points[1] = 100.0f;
  points[2] = 150.0f;
  points[3] = 100.0f;   
  points[4] = 150.0f;
  points[5] = 150.0f;   
  points[6] = 100.0f;
  points[7] = 150.0f;   
  Path path(points,4);
  path.solid_ = true;

  float *points2 = (float*) malloc(sizeof(float)*4);
  points2[0] = 0.0f;
  points2[1] = 0.0f;
  points2[2] = 150.0f;
  points2[3] = 100.0f;
  Path path2(points2,4);
  path2.solid_ = false;


  
  
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    path.draw();
    path2.draw();



    do{//Control fps
    		current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    

    esat::DrawEnd();
    esat::WindowFrame();
  }
  esat::WindowDestroy();
  return 0;
}