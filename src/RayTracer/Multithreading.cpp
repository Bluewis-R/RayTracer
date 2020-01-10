#include "Multithreading.h"
#include "Camera.h"
#include "Tracer.h"
#include <thread>
#include <mutex>
#include <chrono>

Multithreading::Multithreading(shared<Camera> _camera, shared<Tracer> _tracer)
{
  m_camera = _camera;
  m_tracer = _tracer;
}

void Multithreading::RenderPixel(glm::ivec2 _PixelCoord)
{
  shared<Ray> ray = m_camera->CreateRay(_PixelCoord);
  glm::vec4 rayColour = m_tracer->TraceRay(ray);


  m_drawPixleMutex.lock();
  MCG::DrawPixel(_PixelCoord, rayColour);
  m_drawPixleMutex.unlock();
}

double Multithreading::ControlRayTrace()
{
  //  This test is the control and measures the time it takes to render the the scene

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < m_camera->GetWindowSize().x; i++)
  {
    for (int j = 0; j < m_camera->GetWindowSize().y; j++)
    {
      RenderPixel(glm::ivec2(i, j));
    }
  }
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  return elapsed.count();
}

double Multithreading::TwoThreadRayTrace()
{
  //  Timing the duration
  auto start = std::chrono::high_resolution_clock::now();
  std::thread thread1([&]()
  {
    ThreadFunction(2, 0);
  });
  std::thread thread2([&]()
  {
    ThreadFunction(2, 1);
  });
  thread1.join();
  thread2.join();
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  return elapsed.count();
}
double Multithreading::FourThreadRayTrace()
{
  auto start = std::chrono::high_resolution_clock::now();
  std::thread thread1([&]()
  {
    ThreadFunction(4, 0);
  });
  std::thread thread2([&]()
  {
    ThreadFunction(4, 1);
  });
  std::thread thread3([&]()
  {
    ThreadFunction(4, 2);
  });
  std::thread thread4([&]()
  {
    ThreadFunction(4, 3);
  });
  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  return elapsed.count();
}
double Multithreading::SixThreadRayTrace()
{
  //  Timing the duration
  auto start = std::chrono::high_resolution_clock::now();
  std::thread thread1([&]()
  {
    ThreadFunction(6, 0);
  });
  std::thread thread2([&]()
  {
    ThreadFunction(6, 1);
  });
  std::thread thread3([&]()
  {
    ThreadFunction(6, 2);
  });
  std::thread thread4([&]()
  {
    ThreadFunction(6, 3);
  });
  std::thread thread5([&]()
  {
    ThreadFunction(6, 4);
  });
  std::thread thread6([&]()
  {
    ThreadFunction(6, 5);
  });
  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  thread6.join();
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  return elapsed.count();
}
//  This has a strange effect
double Multithreading::EightThreadRayTrace()
{
  //  Timing the duration
  auto start = std::chrono::high_resolution_clock::now();
  std::thread thread1([&]()
  {
    ThreadFunction(8, 0);
  });
  std::thread thread2([&]()
  {
    ThreadFunction(8, 1);
  });
  std::thread thread3([&]()
  {
    ThreadFunction(8, 2);
  });
  std::thread thread4([&]()
  {
    ThreadFunction(8, 3);
  });
  std::thread thread5([&]()
  {
    ThreadFunction(8, 4);
  });
  std::thread thread6([&]()
  {
    ThreadFunction(8, 5);
  });
  std::thread thread7([&]()
  {
    ThreadFunction(8, 6);
  });
  std::thread thread8([&]()
  {
    ThreadFunction(8, 7);
  });
  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  thread6.join();
  thread7.join();
  thread8.join();
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  return elapsed.count();
}


//This function takes ing the number of threads in total and then only does the mod of the thread number
void Multithreading::ThreadFunction(int _totalThreads, int _thread)
{
  for (int i = 0; i < m_camera->GetWindowSize().x; i++)
  {
    if (i% _totalThreads == _thread)
    {
      for (int j = 0; j < m_camera->GetWindowSize().y; j++)
      {
        //if ((i*m_camera->GetWindowSize().x + j) % _totalThreads == _thread)
        //{
          RenderPixel(glm::ivec2(i, j));
        //}
      }
    }
  }


}