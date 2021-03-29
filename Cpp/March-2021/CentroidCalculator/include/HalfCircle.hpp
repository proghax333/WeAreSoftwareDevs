
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "MathLib.hpp"

#include "include/Shape.hpp"
#include "include/Body.hpp"
#include "interfaces/AreaInterface.hpp"
#include "interfaces/AngleInterface.hpp"

class HalfCircle : public virtual Shape, public virtual AreaInterface, public virtual Body<2>, public virtual AngleInterface<1>
{
public:
  HalfCircle(const Number &radius = 0.0) : radius(radius)
  {
    this->setShapeType("half-circle");
  }
  Number getArea() override
  {
    return (Math::PI * this->radius * this->radius) / 2;
  }
  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    auto result = Vector<2>(
        {location[0], location[1] + (4 * this->radius / (3 * Math::PI))});

    result = Math::rotate2(result, this->angles[0]);

    return result;
  }

private:
  Number radius = 0.0;
};
