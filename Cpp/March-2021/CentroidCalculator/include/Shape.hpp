
#pragma once

#include <string>

#include "MathLib.hpp"
#include "Typedefs.hpp"

class Shape
{
public:
  virtual ~Shape()
  {
    // Virtual destructor
  }

  std::string getType()
  {
    return this->shapeType;
  }

protected:
  std::string shapeType;

  void setShapeType(const std::string &shapeType)
  {
    this->shapeType = shapeType;
  }
};