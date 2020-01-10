#pragma once
#ifndef _MULTITHREADING_H_
#define _MULTITHREADING_H_

#include "Macros.h"
#include "MCG_GFX_Lib.h"
#include <thread>
#include <mutex>

class Ray;
class Camera;
class Tracer;

class Multithreading
{
public:
  Multithreading(shared<Camera> _camera, shared<Tracer> _tracer);

  void RenderPixel(glm::ivec2 _PixelCoord);
  void ThreadFunction(int _totalThreads, int _thread);

  float ControlRayTrace();
  float TwoThreadRayTrace();


protected:
  shared<Camera> m_camera;
  shared<Tracer> m_tracer;


};

#endif // !_MULTITHREADING_H_