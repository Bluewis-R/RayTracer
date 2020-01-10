#pragma once
#ifndef _LIGHT_
#define _LIGHT_
#include "Object.h";
#include "Macros.h"

class Sphere;
class Light;
class Ray;
class RayIData;

class Light : public Object
{
public:  
  Light();  
  Light(glm::vec3 _position, glm::vec3 _rotation, glm::vec4 _colour, float _scale);

  float GetScale() { return m_scale; }
  void SetScale(float _scale) { m_scale = _scale; }
  
  static float GetLightValue(shared<Sphere> _sphere, shared<Light> _light, shared<Ray> _ray, shared<RayIData> _rayData);

protected:
  float m_scale;



};

#endif // !_LIGHT_