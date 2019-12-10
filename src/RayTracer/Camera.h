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

 shared<Ray> Fucntion1(glm::ivec2 _pixleCoord); 
 

private:
  glm::ivec2 m_windowSize;

  shared<glm::mat4> m_viewMatrix;
  shared<glm::mat4> m_inverseProjectionMatrix;
  shared<glm::vec3> m_position;
  
}; 




#endif // !_CAMERA_H_