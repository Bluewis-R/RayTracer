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
  Camera(glm::ivec2 _windowSize);

 shared<Ray> CreateRay(glm::ivec2 _pixleCoord);
 

private:
  glm::ivec2 m_windowSize;

  shared<glm::mat4> m_inverseViewMatrix;
  shared<glm::mat4> m_inverseProjectionMatrix;
  glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
  
}; 




#endif // !_CAMERA_H_