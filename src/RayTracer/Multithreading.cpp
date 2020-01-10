#include "Multithreading.h"
#include "Camera.h"
#include "Tracer.h"

Multithreading::Multithreading(shared<Camera> _camera, shared<Tracer> _tracer)
{
  m_camera = _camera;
  m_tracer = _tracer;
}

void Multithreading::RenderPixel(glm::ivec2 _PixelCoord)
{
  shared<Ray> ray = m_camera->CreateRay(_PixelCoord);
  glm::vec4 rayColour = m_tracer->TraceRay(ray);
  MCG::DrawPixel(_PixelCoord, rayColour);
}

float Multithreading::ControlRayTrace()
{
  //  This test is the control and measures the time it takes to render the the scene

  for (int i = 0; i < m_camera->GetWindowSize().x; i++)
  {
    for (int j = 0; j < m_camera->GetWindowSize().y; j++)
    {
      RenderPixel(glm::ivec2(i, j));
    }
  }



  return 1.0f;
}

float Multithreading::TwoThreadRayTrace()
{
  std::thread thread1(ThreadFunction, 2, 0);
  std::thread thread2(ThreadFunction, 2, 1);




}
//This function takes ing the number of threads in total and then only does the mod of the thread number
void Multithreading::ThreadFunction(int _totalThreads, int _thread)
{
  for (int i = 0; i < m_camera->GetWindowSize().x; i++)
  {
    for (int j = 0; j < m_camera->GetWindowSize().y; j++)
    {
      if ((i*m_camera->GetWindowSize().x + j) % _totalThreads == _thread)
      {
        RenderPixel(glm::ivec2(i, j));
      }
    }
  }


}