#include "Tracer.h"
#include "LewisMaths.h"
#include "Sphere.h"
#include "Object.h"
#include "Light.h"

Tracer::Tracer()
{
  m_sphere = makeSh<Sphere>();
}

glm::vec4 Tracer::TraceRay(shared<Ray> _ray)
{
  shared<Sphere> closestSphere;
  shared<RayIData> closestRData;
  bool oneIntersect = false;

  for (int i = 0; i < m_objects.size(); i++)
  {
    shared<Sphere> tempSphere = std::dynamic_pointer_cast<Sphere>(m_objects.at(i));
    shared<RayIData> tempRData = RaySphereIntersection(_ray, tempSphere);

    //  checking for collision
    if (tempRData->m_isCollide)
    {
      if (oneIntersect)
      {
        if (tempRData->m_distance < closestRData->m_distance)
        {
          closestSphere = tempSphere;
          closestRData = tempRData;
        }
      }
      else
      {
        oneIntersect = true;
        closestSphere = tempSphere;
        closestRData = tempRData;
      }
    }
  }
 
  if (closestSphere)
  {
    float lightValue = Light::GetLightValue(closestSphere, m_lights.at(0), _ray, closestRData);
    return closestSphere->GetColour()*lightValue;

  }
  else
  {
    float k = 0;
  }


  return glm::vec4(0.0f, 0.0f, 255.0f, 0.0f);
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
  
  //TODO:
  // check if the closest point is behind the sphere
  //float delta = glm::pow(b, 2.0f;)-4*c;

  
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

    //  normal
    glm::vec3 normal = glm::normalize(hit - spherePosition);

    return std::make_shared<RayIData>(true, rayToPoint, normal);
  }
  else
  {
   //*float l = 0;
  }
}

void Tracer::AddLight(shared<Light> _light)
{
  m_lights.push_back(_light);
}

void Tracer::AddObject(shared<Object> _object)
{
  m_objects.push_back(_object);
}