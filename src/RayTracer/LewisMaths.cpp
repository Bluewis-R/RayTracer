#include "LewisMaths.h"

float LMaths::FindDiscriminant(float _a, float _b, float _c)
{
  //b^2 - 4*a*c
  return (_b*_b) - 4 * _a*_c;
}
