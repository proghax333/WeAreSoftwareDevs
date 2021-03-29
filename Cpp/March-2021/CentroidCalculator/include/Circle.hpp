
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "MathLib.hpp"

#include "include/Shape.hpp"
#include "include/Body.hpp"
#include "interfaces/AreaInterface.hpp"
#include "interfaces/AngleInterface.hpp"

class Circle : public virtual Shape, public virtual AreaInterface, public virtual Body<2>, public virtual AngleInterface<1>
{
public:
  Circle(const Number &radius = 0.0) : radius(radius)
  {
    this->setShapeType("circle");
  }

  Number getArea() override
  {
    return Math::PI * this->radius * this->radius;
  }

  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    auto result = Vector<2>({location[0], location[1]});

    return result;
  }

private:
  Number radius = 0.0;
};
