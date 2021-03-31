
#pragma once

#include <string>

#include "Typedefs.hpp"
#include "include/Shape.hpp"
#include "properties/Body2DProperties.hpp"
#include "properties/AngleProperties.hpp"

class Rectangle : public virtual Shape, public virtual Body2DProperties, public virtual AngleProperties
{
public:
  static const std::string ShapeType;
  Rectangle(const Number &width = 0.0, const Number &height = 0.0)
  {
    setShapeType(ShapeType);

    // Add width property to the shape
    properties["width"] = Property{.type = "shapeProperty", .value = width};

    // Add height property to the shape
    properties["height"] = Property{.type = "shapeProperty", .value = height};

    // getArea() behavior
    std::function<Number()> getArea = [&]() -> Number {
      auto width = properties["width"].get<Number &>();
      auto height = properties["height"].get<Number &>();

      return width * height;
    };

    // getCentroid() behavior
    std::function<Vector<2>()> getCentroid = [&]() -> Vector<2> {
      auto x = properties["x"].get<Number &>();
      auto y = properties["y"].get<Number &>();
      auto width = properties["width"].get<Number &>();
      auto height = properties["height"].get<Number &>();

      auto result = Vector<2>({x + width / 2, y + height / 2});

      return result;
    };

    // Add behavioural details to the shape
    properties["getArea"] = Property{.type = "shapeBehavior", .value = getArea};

    properties["getCentroid"] = Property{.type = "shapeBehavior", .value = getCentroid};
  }
};

const std::string Rectangle::ShapeType = "Rectangle";
