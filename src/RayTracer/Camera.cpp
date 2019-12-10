#include "Camera.h"
#include "Macros.h"

Camera::Camera(glm::ivec2 _windowSize)
{
  //windowHeight
  m_windowSize = _windowSize;
  //  Projection Matrix
  m_inverseProjectionMatrix = std::make_shared<glm::mat4>();
  glm::mat4 projectionMatrix = glm::perspective(   //  link to projection matrix code http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/#the-projection-matrix
    glm::radians(60.0f),  // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
    4.0f / 3.0f,          // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
    0.1f,                 // Near clipping plane. Keep as big as possible, or you'll get precision issues.
    100.0f);              // Far clipping plane. Keep as little as possible.
                        
  (*m_inverseProjectionMatrix) = projectionMatrix;
  //  View Matrix
  m_inverseViewMatrix = std::make_shared<glm::mat4>();
  //TODO:  look up how to do forward vector
  glm::mat4 viewMatrix = glm::lookAt(m_position, glm::vec3(0.0f, 0.0f, glm::radians(90.0f)), glm::vec3(0.0f, glm::radians(90.0f), 0.0f)); //(pos,forward vec of cam, up vec)
  (*m_inverseViewMatrix) = viewMatrix;
}

shared<Ray> Camera::CreateRay(glm::ivec2 _pixleCoord)
{
  shared<Ray> rtn = std::make_shared<Ray>(); //Ray(origin, direction)
  //  Normalised device coordinate 
  rtn->SetOrigin(glm::vec3(_pixleCoord.x/m_windowSize.x, _pixleCoord.y / m_windowSize.y, -1));
  rtn->SetDirection(glm::vec3(0.0f, 0.0f, 1.0f));
  
  //  To convert from device space to worldspace
  rtn = (*rtn)* m_inverseProjectionMatrix;
  // To convert from left hand to righthand TODO: aske leigh

  //  To covert from worldspace to viewspace
  rtn = (*rtn)* m_inverseViewMatrix;

  return rtn;
}
