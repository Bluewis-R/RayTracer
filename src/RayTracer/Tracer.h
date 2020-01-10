#pragma once
#ifndef _TRACER_H_
#define _TRACER_H_
#include "Macros.h"
#include <vector>

#include "Ray.h"
#include "Sphere.h"
#include "Light.h"

struct RayIData
{
  RayIData(bool _isCollide) { m_isCollide = _isCollide; }
  RayIData(bool _isCollide, float _hit, glm::vec3 _normal)
  {
    m_isCollide = _isCollide;
    m_distance = _hit;
    m_normal = _normal;
  }
  bool m_isCollide;
  float m_distance;
  glm::vec3 m_normal;
};

class Tracer
{
public:
  Tracer();
  glm::vec4 TraceRay(shared<Ray> _ray);

  glm::vec3 ClosetPoint(shared<Ray> _ray, glm::vec3 _point);
  shared<RayIData> RaySphereIntersection(shared<Ray > _ray, shared<Sphere> _sphere);
  void NormalOfSphere(shared<Sphere> _sphere, glm::vec3 _point);

  void AddLight(shared<Light> _light);
  void AddObject(shared<Object> _object);
  
    



private:
  std::vector<std::shared_ptr<Ray>> m_rays;
  glm::vec3 m_camPos = glm::vec3(0.0, 0.0, 0.0);
  std::vector<shared<Object>> m_objects;
  std::vector<shared<Light>> m_lights;

  shared<Sphere> m_sphere;


};



#endif // !_TRACER_H_