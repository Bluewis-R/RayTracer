#include "light.h"
#include <RayTracer/MCG_GFX_Lib.h>
#include "Macros.h"
#include "RayTracer.h"


Light::Light()
{
  m_position = glm::vec3(0.0f, 0.0f, 0.0f);
  m_rotation = glm::vec3(0.0f, 0.0f, 0.0f); 
  m_colour = glm::vec4(255.0f, 255.0f, 255.0f, 0.0f);
  m_scale = 1.0f;
}

Light::Light(glm::vec3 _position, glm::vec3 _rotation, glm::vec4 _colour, float _scale)
{
  m_position = _position;
  m_rotation = _rotation;
  m_colour = _colour;
  m_scale = _scale;
}

float Light::GetLightValue(shared<Sphere> _sphere, shared<Light> _light, shared<Ray> _ray, shared<RayIData> _rayData)
{
  //  lighting             
  float ambient = _sphere->GetAmbient();
  glm::vec3 lightVector = _sphere->GetPosition() - _light->GetPosition();
  glm::vec3 rayIncident = glm::normalize(lightVector);

  float DOT = glm::abs(glm::dot(_rayData->m_normal, rayIncident));
  
  // http://www.robots.ox.ac.uk/~att/index.html
  //  Ambient + Diffuse constant * (Normal dot Ray[unit]) + Specular constant * (Normal dot L) ^ specular exponant
  float endResult = ((0.8f*ambient)+(0.9f*(DOT)) + (0.4f*glm::pow(DOT, 100.0f)));
  endResult *= (7.0f/ glm::length(lightVector*lightVector));

  return glm::clamp(endResult, 0.0f, 1.0f);
}






