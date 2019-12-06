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
 shared<Ray> Fucntion1(glm::ivec2 _pixleCoord); 
 shared<glm::vec3> m_position;

private:
  glm::mat4 viewMatrix;

  /*
  glm::mat4 m_projectionMatrix = glm::perspective(
    glm::radians(60.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
    4.0f / 3.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
    0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
    100.0f);             // Far clipping plane. Keep as little as possible.
    */
}; 




#endif // !_CAMERA_H_