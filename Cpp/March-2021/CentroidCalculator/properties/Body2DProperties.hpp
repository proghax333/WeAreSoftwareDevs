
#pragma once

#include <functional>
#include "Typedefs.hpp"
#include "include/Shape.hpp"

class Body2DProperties : public virtual Shape
{
public:
  Body2DProperties()
  {
    // Add x coordinate property to the shape
    properties["x"] = Property{.type = "shapeProperty", .value = Number(0.0)};

    // Add y coordinate property to the shape
    properties["y"] = Property{.type = "shapeProperty", .value = Number(0.0)};
  }
  ~Body2DProperties()
  {
  }
};
