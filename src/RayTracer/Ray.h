#pragma once
#ifndef _RAY_H_
#define _RAY_H_

#include "Macros.h"
#include <glm/glm.hpp>

class Ray
{
public:
  Ray();
  Ray(glm::vec3 _origin, glm::vec3 _direction);

  glm::vec3 GetOrigin();
  glm::vec3 GetDirection();
  void SetOrigin(glm::vec3 _origin);
  void SetDirection(glm::vec3 _direction);

  shared<Ray> operator*(shared<glm::mat4> _mat);
  void MultiplyByMatrix(glm::mat4 _matrix);


private:
  glm::vec3 m_origin;
  glm::vec3 m_direction;





};

#endif // !_RAY_H_