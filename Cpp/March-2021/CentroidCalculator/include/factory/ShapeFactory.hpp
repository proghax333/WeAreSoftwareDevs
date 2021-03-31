
#pragma once

#include <string>
#include <memory>

#include "include/AllShapes2D.hpp"

class ShapeFactory
{
public:
  static std::shared_ptr<Shape> createShape2D(const std::string &shapeType)
  {
    return nullptr;
  }
};
