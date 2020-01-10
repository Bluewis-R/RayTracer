#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <glm/glm.hpp>

class Object
{
public:
  glm::vec3 GetScale() { return m_scale; }
  void SetScale (glm::vec3 _scale) { m_scale = _scale; }

  glm::vec3 GetRotation() { return m_rotation; }
  void SetRotation(glm::vec3 _rotation) { m_rotation = _rotation; }
  
  glm::vec3 GetPosition() { return m_position; }
  virtual void SetPosition(glm::vec3 _position) { m_position = _position; }
    
  float GetAmbient() { return m_ambient; }
  void SetAmbient(float _ambient) { m_ambient = _ambient; }
    
  glm::vec4 GetColour() { return m_colour; }
  void SetColour(glm::vec4 _colour) { m_colour = _colour; }



protected:
  float m_ambient;
  glm::vec3 m_position;
  glm::vec3 m_rotation;
  glm::vec3 m_scale;
  glm::vec4 m_colour;


};

#endif // !_OBJECT_H_