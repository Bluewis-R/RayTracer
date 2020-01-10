#include "Camera.h"
#include "Macros.h"

Camera::Camera(glm::ivec2 _windowSize, float _fov)
{
  m_windowSize = _windowSize;
  m_fov = _fov;
}

shared<Ray> Camera::CreateRay(glm::ivec2 _pixleCoord)
{
  shared<Ray> rtn = std::make_shared<Ray>(); //Ray(origin, direction)
   
 
  float xValue = _pixleCoord.x - (m_windowSize.x / 2);
  float yValue = _pixleCoord.y - (m_windowSize.y / 2);
 
  float dist = (m_windowSize.x) / (glm::tan(glm::radians(m_fov / 2.0f)));         //TODO: this doesn't need to be calcluated every time 
  
  glm::vec3 tempSecondPoint = glm::vec3(xValue, yValue, dist);
  glm::vec3 tempDirection = glm::normalize(tempSecondPoint - m_position);


  //  Filling out ray
  rtn->SetOrigin(m_position);
  rtn->SetDirection(tempDirection);
  return rtn;


  //  depreciated code (this is code for a more complicated method)
  /*
  shared<Ray> rtn = std::make_shared<Ray>(); //Ray(origin, direction)
  //  Normalised device coordinate 
  
  float xValue = ((2.0f*(float)_pixleCoord.x)/ (float)m_windowSize.x) - 1;
  float yValue = ((2.0f*(float)_pixleCoord.y) / (float)m_windowSize.y) - 1;

  glm::vec3 tempOrigin = glm::vec3(xValue, yValue, -1.0f);
  glm::vec3 tempSecondPoint = glm::vec3(xValue, yValue, 1.0f);
  
  //TODO:   remove mat fucntion
  //  To convert from device space to worldspace
  tempOrigin = V3xMat4(tempOrigin, m_inverseProjectionMatrix);
  tempSecondPoint = V3xMat4(tempSecondPoint, m_inverseProjectionMatrix);
  //  To convert from device space to worldspace

  //  To covert from worldspace to viewspace
  tempOrigin = V3xMat4(tempOrigin, m_inverseProjectionMatrix);
  tempSecondPoint = V3xMat4(tempSecondPoint, m_inverseProjectionMatrix);
  
  //  Setting Ray
  rtn->SetOrigin(tempOrigin);
  rtn->SetDirection(tempSecondPoint- tempOrigin);


  


  return rtn;
  */
}

glm::vec3 Camera ::V3xMat4(glm::vec3 _vec3, shared<glm::mat4> _mat4)
{
  glm::vec4 tempVec4 = glm::vec4(_vec3, 0.0f);
  tempVec4 = (*_mat4) * tempVec4;
  glm::vec3 tempVec3 = tempVec4;

  return tempVec3;
}

