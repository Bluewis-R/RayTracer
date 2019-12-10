#include "Tracer.h"
#include "LewisMaths.h"

glm::vec3 Tracer::TraceRay(shared<Ray> _ray)
{
  //returns colour
  return glm::vec3(1.0f,0.0f,0.0f);
}

glm::vec3 Tracer::ClosetPoint(shared<Ray> _ray, glm::vec3 _point)
{
  glm::vec3 a = _ray->GetOrigin()- m_camPos;
  glm::vec3 n = glm::normalize(_ray->GetDirection());
  glm::vec3 P = _point;

  glm::vec3 closestPoint = _ray->GetOrigin() + (glm::dot((_point - a),n)*n);
  
  //  X = a + ((P-a)DOT n)*n 
  //  a => ray origin
  //  p => position of sphere
  //  n => is the ray direction
  
  return closestPoint;
}

shared<RayIData> Tracer::RaySphereIntersection(shared<Ray> _ray, shared<Sphere> _sphere)
{
  // imgur link to diagram https://imgur.com/a/16hW8w7
  
  glm::vec3 spherePosition = _sphere->GetPosition();
  float sphereSize = _sphere->GetScale();
  glm::vec3 closestPoint = ClosetPoint(_ray, spherePosition);

  //Check if the ray's origin is inside of the sphere
  if (glm::distance(_ray->GetOrigin(), _sphere->GetPosition())<= _sphere->GetScale())
  {
    return std::make_shared<RayIData>(false);
  }
  
  //find the closet point to the sphere
  float distance = glm::distance(spherePosition, closestPoint);
  
  // check if the closest point is behind the sphere
  //float dis = LMaths::FindDiscriminant(a,b,c);

  if (distance > sphereSize)
  {
    //  Ray dosn't hit the sphere
    return std::make_shared<RayIData>(false);
  }
  else if (distance <= sphereSize)
  {
    // Collides with sphere
    //d = || P - a - ((P-a)DOT n)*n ||
    glm::vec3 a = _ray->GetOrigin() - m_camPos;
    glm::vec3 n = glm::normalize(_ray->GetDirection());
    glm::vec3 P = _sphere->GetPosition();

    glm::vec3 dVec = P - a -(glm::dot((P - a), n)*n);

    float d = abs(glm::length(dVec));
    // x = sqrt(r^2 - d^2)
    float x = sqrt((sphereSize*sphereSize) - (d*d));
    
    // hits = closestPoint -n*x
    glm::vec3 hit = closestPoint - (n*x);

    float rayToPoint = glm::distance(_ray->GetOrigin(), hit);


    return std::make_shared<RayIData>(true, rayToPoint);
  }
  else
  {
    
  }
  
  

}