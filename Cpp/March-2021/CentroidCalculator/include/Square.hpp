
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "include/Shape.hpp"
#include "properties/Body2DProperties.hpp"
#include "properties/AngleProperties.hpp"

class Square : public virtual Shape, public virtual Body2DProperties, public virtual AngleProperties
{
public:
  static const std::string ShapeType;
  Square(const Number &sideLength = 0.0)
  {
    setShapeType(ShapeType);

    // Add sideLength property to the shape
    properties["sideLength"] = Property{.type = "shapeProperty", .value = sideLength};

    // getArea() behavior
    std::function<Number()>
        getArea = [&]() -> Number {
      auto sideLength = properties["sideLength"].get<Number &>();
      return sideLength * sideLength;
    };

    // getCentroid() behavior
    std::function<Vector<2>()> getCentroid = [&]() -> Vector<2> {
      auto x = properties["x"].get<Number &>();
      auto y = properties["y"].get<Number &>();
      auto sideLength = properties["sideLength"].get<Number &>();
      auto result = Vector<2>({x + sideLength / 2, y + sideLength / 2});

      return result;
    };

    // Add behavioural details to the shape
    properties["getArea"] = Property{.type = "shapeBehavior", .value = getArea};

    properties["getCentroid"] = Property{.type = "shapeBehavior", .value = getCentroid};
  }
};

const std::string Square::ShapeType = "Square";
