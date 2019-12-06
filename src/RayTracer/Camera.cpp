#include "Camera.h"

shared<Ray> Camera::Fucntion1(glm::ivec2 _pixleCoord)
{
  std::shared_ptr<Ray> rtn = std::make_shared<Ray>(glm::vec3(1.0, 1.0, 1.0), glm::vec3(2.0, 2.0, 2.0));
  return rtn;
}
