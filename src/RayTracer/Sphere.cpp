#include "Sphere.h"

Sphere::Sphere()
{
  m_position = glm::vec3(0.0f, 0.0f, 4.0f);
  m_scale = 1.0f;
  m_ambient = 0.01;
}

Sphere::Sphere(glm::vec3 _position, glm::vec4 _colour, float _scale, float _ambient )
{
  m_colour = _colour;
  m_position = _position;
  m_scale = _scale;
  m_ambient = _ambient;
}

glm::ivec3 Sphere::Normal(Ray _ray, glm::vec3 _intersectionPoint)
{
  return glm::ivec3(255, 0, 0);
}

