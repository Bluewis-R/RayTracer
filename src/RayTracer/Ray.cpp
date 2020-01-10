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



void Ray::MultiplyByMatrix(glm::mat4 _matrix)
{
  glm::vec4 ori = glm::vec4(m_origin, 0.0f);
  glm::vec4 dir = glm::vec4(m_direction, 0.0f);

  glm::vec4 tempo = (_matrix) * ori;
  glm::vec4 tempd = (_matrix) * dir;

  m_origin = tempo;
  m_direction = tempd;
}
