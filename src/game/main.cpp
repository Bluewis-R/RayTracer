#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <gl/glew.h>
#include <RayTracer/MCG_GFX_Lib.h>
#include "RayTracer/RayTracer.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

int main(int argc, char *argv[])
{
  glm::ivec3 black(0, 0, 0);
  glm::ivec3 white(255, 255, 255);
  //rendering pixel
  MCG::Init(glm::ivec2(WINDOW_WIDTH, WINDOW_HEIGHT));
  MCG::SetBackground(black);

  //  
  std::shared_ptr<Camera> cam = makeSh<Camera>(glm::ivec2(WINDOW_WIDTH, WINDOW_HEIGHT), 90.0f);
  shared<Tracer> rayTracer = makeSh<Tracer>();
  Multithreading threadingProgram(cam, rayTracer);


  //  Objects in the raytracer scene
  shared<Light> light1 = makeSh<Light>(
    glm::vec3(1.0f, 0.0f, -2.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), 2.0f);
  shared<Light> light2 = makeSh<Light>(
    glm::vec3(-1.0f, 0.0f, -3.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec4(255.0f, 255.0f, 255.0f, 255.0f), 2.0f);

  shared<Sphere> sphere1 = makeSh<Sphere>(
    glm::vec3(-0.5f, 0.0f, 3.0f),
    glm::vec4(0.0f, 0.0f, 255.0f, 255.0f), .8f, 0.01f);
  shared<Sphere> sphere2 = makeSh<Sphere>(
    glm::vec3(0.4f, 0.2f, 2.5f),
    glm::vec4(255.0f, 0.0f, 0.0f, 255.0f), 0.3f, 0.01f);
  shared<Sphere> sphere3 = makeSh<Sphere>(
    glm::vec3(0.3f, 0.3f, 2.0f),
    glm::vec4(255.0f, 255.0f, 0.0f, 255.0f), 0.2f, 0.01f);
  shared<Sphere> sphere4 = makeSh<Sphere>(
    glm::vec3(0.15f, 0.3f, 1.5f),
    glm::vec4(0.0f, 255.0f, 255.0f, 255.0f), 0.15f, 0.01f);
  shared<Sphere> sphere5 = makeSh<Sphere>(
    glm::vec3(0.0f, 0.0f, 14.0f),
    glm::vec4(0.0f, 255.0f, 255.0f, 255.0f), 1.0f, 0.01f);

  rayTracer->AddLight(light1); 
  rayTracer->AddLight(light2);
  rayTracer->AddObject(sphere1);
  rayTracer->AddObject(sphere2); 
  rayTracer->AddObject(sphere3);
  rayTracer->AddObject(sphere4);
  rayTracer->AddObject(sphere5);

  
  //  Multithreading  and analaysis
  std::cout << "Control : " << threadingProgram.ControlRayTrace() << std::endl;
  MCG::ProcessFrame();
  std::cout << "Two Threads : " << threadingProgram.TwoThreadRayTrace() << std::endl;
  MCG::ProcessFrame();
  std::cout << "Four Threads : " << threadingProgram.FourThreadRayTrace() << std::endl;
  MCG::ProcessFrame();
  std::cout << "Eight Threads : " << threadingProgram.EightThreadRayTrace() << std::endl;
  MCG::ProcessFrame();
   

  std::cin.get();
  MCG::Cleanup();
  return 0;
}
