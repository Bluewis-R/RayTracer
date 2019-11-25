#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <glm/glm.hpp>

class Object
{
public:
  void SetScale (glm::vec3 _scale);
  glm::vec3 GetScale();
  void SetRotation(glm::vec3 _rotation);
  glm::vec3 GetRotation();
  void SetPosition(glm::vec3 _position);
  glm::vec3 GetPosition();

private:
  glm::vec3 m_position;
  glm::vec3 m_rotation;
  glm::vec3 m_scale;


};

#endif // !_OBJECT_H_