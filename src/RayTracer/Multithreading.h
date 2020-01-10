#pragma once
#ifndef _MULTITHREADING_H_
#define _MULTITHREADING_H_

#include "Macros.h"
#include "MCG_GFX_Lib.h"
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

  double ControlRayTrace();
  double TwoThreadRayTrace();
  double FourThreadRayTrace();
  double SixThreadRayTrace();
  double EightThreadRayTrace();


protected:
  shared<Camera> m_camera;
  shared<Tracer> m_tracer;
  std::mutex m_drawPixleMutex;


};

#endif // !_MULTITHREADING_H_