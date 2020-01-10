#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_
#include "Object.h"
#include "Ray.h"

class Sphere : public Object
{
public:
  Sphere();
  Sphere::Sphere(glm::vec3 _position, glm::vec4 _colour, float _scale, float _ambient);
  glm::ivec3 Normal(Ray _ray, glm::vec3 _intersectionPoint);

  float GetScale() {  return m_scale; }
  void SetScale(float _scale) { m_scale = _scale; }
  
private:
  float m_scale;


};

#endif // !_SPHERE_H_