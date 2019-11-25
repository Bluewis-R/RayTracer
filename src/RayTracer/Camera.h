#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <memory>
#include <glm/glm.hpp>
#include "Ray.h"

class Camera
{
public:
  std::shared_ptr<Ray> Fucntion1(glm::ivec2 _a, glm::ivec2 _b);


private:


}; 




#endif // !_CAMERA_H_