#include "Object.h"


void Object::SetScale(glm::vec3 _scale)
{
  m_scale = _scale;
}
glm::vec3 Object::GetScale()
{
  return m_scale;
}

void Object::SetRotation(glm::vec3 _rotation)
{
  m_rotation = _rotation;
}
glm::vec3 Object::GetRotation()
{
  return m_rotation;
}

void Object::SetPosition(glm::vec3 _position)
{
  m_position = _position;
}
glm::vec3 Object::GetPosition()
{
  return m_position;
}
