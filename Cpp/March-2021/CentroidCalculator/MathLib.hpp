
#pragma once

#include <cmath>
#include "Typedefs.hpp"

namespace Math
{
  constexpr const Number PI = 3.1415926535;

  inline constexpr Number degToRad(Number deg)
  {
    return deg / 180 * PI;
  }
  inline Number radToDeg(Number rad)
  {
    return rad / PI * 180;
  }
  inline Number operator"" _deg(Number deg)
  {
    return degToRad(deg);
  }
  inline Number operator"" _rad(Number rad)
  {
    return radToDeg(rad);
  }
  inline Number getAngle2(const Vector<2> &location)
  {
    Number angle = atan2l(location[1], location[0]);
    return angle;
  }

  inline Vector<2> rotate2(const Vector<2> &location, Number angle)
  {
    auto result = Vector<2>();
    auto offset = getAngle2(location);

    result[0] = location[0] * cos(offset + angle);
    result[1] = location[1] * sin(offset + angle);

    return result;
  }
}
