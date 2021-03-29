
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "MathLib.hpp"

#include "include/Shape.hpp"
#include "include/Body.hpp"
#include "interfaces/AreaInterface.hpp"
#include "interfaces/AngleInterface.hpp"

class QuarterCircle : public virtual Shape, public virtual AreaInterface, public virtual Body<2>, public virtual AngleInterface<1>
{
public:
  QuarterCircle(const Number &radius = 0.0)
  {
    this->setShapeType("quarter-circle");
  }
  Number getArea() override
  {
    return (Math::PI * this->radius * this->radius) / 4;
  }
  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    auto result = Vector<2>(
        {(location[0] + 4 * this->radius / (3 * Math::PI)),
         (location[1] + 4 * this->radius / (3 * Math::PI))});

    result = Math::rotate2(result, this->angles[0]);

    return result;
  }

private:
  Number radius;
};
