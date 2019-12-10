#include "Ray.h"

#include "Macros.h"

Ray::Ray()
{
}

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
  m_origin = _origin;
  m_direction = m_direction;
}

glm::vec3 Ray::GetOrigin()
{
  return m_origin;
}

glm::vec3 Ray::GetDirection()
{
  return m_direction;
}

void Ray::SetOrigin(glm::vec3 _origin)
{
  m_origin = _origin;
}

void Ray::SetDirection(glm::vec3 _direction)
{
  m_direction = _direction;
}


shared<Ray> Ray::operator*(shared<glm::mat4> _mat)
{
  //  TODO: not sure if this efficient
  //  Make a referance to the mat 
  glm::mat4 testMat = *_mat;
  shared<Ray> ray = std::make_shared<Ray>();
  
  //  Convert vec3 to vec4
  glm::vec4 ori = glm::vec4(this->m_origin, 0.0f);
  glm::vec4 dir = glm::vec4(this->m_direction, 0.0f);
  
  ori = ori * testMat;
  dir = dir * testMat;

  //  Convert vec4 back to vec3
  ray->m_origin = ori;
  ray->m_direction = dir;
    
  return ray;
}