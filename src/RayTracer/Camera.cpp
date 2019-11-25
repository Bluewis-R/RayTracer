#include "Camera.h"
#include "Camera.h"

std::shared_ptr<Ray> Camera::Fucntion1(glm::ivec2 _a, glm::ivec2 _b)
{
  std::shared_ptr<Ray> rtn = std::make_shared<Ray>(glm::vec3(1.0, 1.0, 1.0), glm::vec3(2.0, 2.0, 2.0));
  return rtn;
}
