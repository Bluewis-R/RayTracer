#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Macros.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Ray.h"

class Camera
{
public:
  Camera(glm::ivec2 _windowSize, float _fov);

 shared<Ray> CreateRay(glm::ivec2 _pixleCoord);
 
 glm::ivec2 GetWindowSize() { return m_windowSize; }
 void SetWindowSize(glm::ivec2 _windowSize) { m_windowSize = _windowSize;  }

private:
  glm::ivec2 m_windowSize;
  float m_fov;
  glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);


  glm::vec3 V3xMat4(glm::vec3 _vec3, shared<glm::mat4> _mat4);
  
}; 




#endif // !_CAMERA_H_