
#pragma once

#include <string>

#include "Typedefs.hpp"

#include "include/Shape.hpp"
#include "include/Body.hpp"

#include "interfaces/AreaInterface.hpp"
#include "interfaces/AngleInterface.hpp"

class Square : public virtual Shape, public AreaInterface, public virtual Body<2>, public virtual AngleInterface<1>
{
public:
  Square()
  {
    this->setShapeType("square");
  }
  Square(const Number &sideLength) : sideLength(sideLength)
  {
    this->setShapeType("square");
  }

  Number getArea() override
  {
    return this->sideLength * this->sideLength;
  }
  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    auto result = Vector<2>({location[0] + this->sideLength / 2, this->location[0] + this->sideLength / 2});

    return result;
  }

private:
  Number sideLength = 0.0;
};
