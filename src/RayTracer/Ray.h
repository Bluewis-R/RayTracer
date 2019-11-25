#pragma once
#ifndef _RAY_H_
#define _RAY_H_

#include <glm/glm.hpp>

class Ray
{
public:
  Ray(glm::vec3 _origin, glm::vec3 _direction);
  glm::vec3 GetOrigin();
  glm::vec3 GetDirection();


private:
  glm::vec3 m_origin;
  glm::vec3 m_direction;

};

#endif // !_RAY_H_