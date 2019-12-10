#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <gl/glew.h>
#include <RayTracer/MCG_GFX_Lib.h>
#include "RayTracer/RayTracer.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600



int main(int argc, char *argv[])
{
  glm::ivec3 black(0, 0, 0);
  glm::ivec3 white(255, 255, 255);
  //rendering pixel
  MCG::Init(glm::ivec2(WINDOW_WIDTH, WINDOW_HEIGHT));
  MCG::SetBackground(black);


  std::shared_ptr<Camera> cam = makeSh<Camera>(glm::ivec2(WINDOW_WIDTH, WINDOW_HEIGHT));
  shared<Tracer> RayTracer = makeSh<Tracer>();


  std::vector<shared<std::vector<shared<Ray>>>> rays;
 
  std::vector<shared<Ray>> temp_rays;
  

  for (int i = 0; i < WINDOW_WIDTH; i++)
  { 
    shared<std::vector<shared<Ray>>> tempVec;
    for (int j = 0; j < WINDOW_HEIGHT; j++)
    {
      shared<Ray> tmpRay = cam->CreateRay(glm::ivec2(i, j));
      tempVec->push_back(tmpRay);
      MCG::DrawPixel(glm::ivec2(i, j), RayTracer->TraceRay(tmpRay));
      //  Smalle

    }
    rays.push_back(tempVec);


  }
  






  //MCG::DrawPixel(glm::ivec2(50, 50), white);
  //MCG::ProcessFrame();

 


  std::cin.get();
  MCG::Cleanup();
  return 0;
}

/*

#include "MCG_GFX_Lib.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Mandelbrot.h"
#include "LineDrawer.h"
#include "Curve.h"
#include "shapes.h"

*/