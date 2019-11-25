#pragma once
#ifndef _TRACER_H_
#define _TRACER_H_
#include "Macros.h"
#include <vector>

#include "Ray.h"
#include "Sphere.h"


class Tracer
{
public:
  shared<glm::vec3> TraceRay(Ray _ray);

  glm::vec3 ClosetPoint(shared<Ray> _ray);
  void RaySphereIntersection(shared<Ray > _ray, shared<Sphere> _sphere);
  void NormalOfSphere(shared<Sphere> _sphere, glm::vec3 _point);


private:
  std::vector<std::shared_ptr<Ray>> m_rays;



};



#endif // !_TRACER_H_