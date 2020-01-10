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

  //
  std::shared_ptr<Camera> cam = makeSh<Camera>(glm::ivec2(WINDOW_WIDTH, WINDOW_HEIGHT), 80.0f);
  shared<Tracer> rayTracer = makeSh<Tracer>();
  Multithreading threadingProgram = Multithreading(cam, rayTracer);



  //  stuff in the "scene"
  shared<Light> light1 = makeSh<Light>(
    glm::vec3(1.0f, 1.0f, -2.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), 1.0f);
  shared<Sphere> sphere1 = makeSh<Sphere>(
    glm::vec3(0.0f, 1.0f, 5.0f),
    glm::vec4(255.0f, 255.0f, 0.0f, 255.0f), 1.0f, 0.01f);
  shared<Sphere> sphere2 = makeSh<Sphere>(
    glm::vec3(0.0f, 0.0f, 4.0f),
    glm::vec4(255.0f, 0.0f, 0.0f, 255.0f), 1.0f, 0.01f);
  rayTracer->AddLight(light1);
  rayTracer->AddObject(sphere1);
  rayTracer->AddObject(sphere2);


  //  Multithreading Starts Here
  threadingProgram.ControlRayTrace();
  MCG::ProcessFrame();

  //  Notes:
  //  Multithreading
  //    1)  Have the program do it with out any mutlithreading
  //    2)  Have the program do multi threading with 2 threads (sequenctialy)
  //    3)  Have the program work woth 4, 8, 12 threads
  //    4)  have the threads render rows & coloums
  //    5)  Have the threads run in Quadrednts
  //    6)  Have the threads render on program at a time



  //return MCG::ShowAndHold();



  //MCG::DrawPixel(glm::ivec2(50, 50), white);
  //MCG::ProcessFrame();

 


  std::cin.get();
  MCG::Cleanup();
  return 0;
}
