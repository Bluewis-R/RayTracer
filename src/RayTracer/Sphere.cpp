#include "Sphere.h"

glm::ivec3 Sphere::Normal(Ray _ray, glm::vec3 _intersectionPoint)
{
  return glm::ivec3(255, 0, 0);
}

void Sphere::SetScale(float _scale)
{
  m_scale = _scale;
}
float Sphere::GetScale()
{
  return m_scale;
}