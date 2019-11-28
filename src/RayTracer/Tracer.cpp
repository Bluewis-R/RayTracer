#include "Tracer.h"

shared<glm::vec3> Tracer::TraceRay(Ray _ray)
{
  return shared<glm::vec3>();
}

glm::vec3 Tracer::ClosetPoint(shared<Ray> _ray, glm::vec3 _point)
{
  glm::vec3 a = _ray->GetOrigin()- m_camPos;
  glm::vec3 n = glm::normalize(_ray->GetDirection());

  glm::vec3 closestPoint = (glm::dot((_point - a),n)*n);
  
  //  X = a + ((P-a)DOT n)*n 
  //  a => ray origin
  //  p => position of sphere
  //  n => is the ray direction
  
  return closestPoint;
}

void Tracer::RaySphereIntersection(shared<Ray> _ray, shared<Sphere> _sphere)
{
  glm::vec3 spherePosition = _sphere->GetPosition();
  glm::vec3 closestPoint = ClosetPoint(_ray, spherePosition);

  float distance = glm::distance(spherePosition, closestPoint);
  if (distance <= _sphere->GetScale())
  {
    //  Ray dosn't hit the sphere

  }
  else if (distance > _sphere->GetScale())
  {
    // Collides with sphere

  }
  
  
  
  
  
  




}


