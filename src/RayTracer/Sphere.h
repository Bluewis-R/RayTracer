#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_
#include "Object.h"
#include "Ray.h"

class Sphere : public Object
{
public:
  glm::ivec3 Normal(Ray _ray, glm::vec3 _intersectionPoint);
private:

};

#endif // !_SPHERE_H_