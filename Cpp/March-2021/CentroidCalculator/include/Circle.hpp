
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "include/Shape.hpp"
#include "properties/Body2DProperties.hpp"
#include "properties/AngleProperties.hpp"
#include "properties/CircleProperties.hpp"

class Circle : public virtual Shape, public virtual Body2DProperties, public virtual AngleProperties, public virtual CircleProperties
{
public:
  static const std::string ShapeType;
  Circle(const Number &radius = 0.0)
  {
    setShapeType(ShapeType);

    // getArea() behavior
    std::function<Number()> getArea = [&]() -> Number {
      auto radius = properties["radius"].get<Number &>();
      return Math::PI * radius * radius;
    };

    // getCentroid() behavior
    std::function<Vector<2>()> getCentroid = [&]() -> Vector<2> {
      auto x = properties["x"].get<Number &>();
      auto y = properties["y"].get<Number &>();
      auto radius = properties["radius"].get<Number &>();

      auto result = Vector<2>({x, y});

      return result;
    };

    // Add behavioural details to the shape
    properties["getArea"] = Property{.type = "shapeBehavior", .value = getArea};

    properties["getCentroid"] = Property{.type = "shapeBehavior", .value = getCentroid};
  }
};

const std::string Circle::ShapeType = "Circle";
