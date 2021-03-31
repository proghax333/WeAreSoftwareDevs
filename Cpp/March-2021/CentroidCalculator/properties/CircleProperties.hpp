
#pragma once

#include <functional>
#include "Typedefs.hpp"
#include "include/Shape.hpp"

class CircleProperties : public virtual Shape
{
public:
  CircleProperties()
  {
    // Add radius property to the shape
    properties["radius"] = Property{.type = "shapeProperty", .value = Number(0.0)};
  }
  ~CircleProperties()
  {
  }
};
