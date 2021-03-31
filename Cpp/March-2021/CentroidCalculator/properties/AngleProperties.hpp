
#pragma once

#include <functional>
#include "Typedefs.hpp"
#include "include/Shape.hpp"

class AngleProperties : public virtual Shape
{
public:
  AngleProperties()
  {
    // Add angle property to the shape
    properties["angle"] = Property{.type = "shapeProperty", .value = Number(0.0)};
  }
  ~AngleProperties()
  {
  }
};
