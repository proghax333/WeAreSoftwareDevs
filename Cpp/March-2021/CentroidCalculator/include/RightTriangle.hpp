
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "MathLib.hpp"

#include "include/Shape.hpp"
#include "include/Body.hpp"
#include "interfaces/AreaInterface.hpp"
#include "interfaces/AngleInterface.hpp"

class RightTriangle : public virtual Shape, public virtual AreaInterface, public virtual Body<2>, public virtual AngleInterface<1>
{
public:
  RightTriangle(const Number &width = 0.0, const Number &height = 0.0) : width(width), height(height)
  {
    this->setShapeType("right-triangle");
  }
  Number getArea() override
  {
    return (this->width * this->height) / 2;
  }
  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    auto result = Vector<2>(
        {location[0] + this->width / 3, location[1] + this->height / 3});

    result = Math::rotate2(result, this->angles[0]);

    return result;
  }

private:
  Number width = 0.0, height = 0.0;
};
