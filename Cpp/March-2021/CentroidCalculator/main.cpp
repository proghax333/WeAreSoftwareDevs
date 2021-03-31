
#include <iostream>
#include <tuple>
#include <array>
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>

#include "Typedefs.hpp"
#include "MathLib.hpp"

#include "include/Square.hpp"
#include "include/Rectangle.hpp"
#include "include/RightTriangle.hpp"
#include "include/Circle.hpp"
#include "include/HalfCircle.hpp"
#include "include/QuarterCircle.hpp"

#include "utilities/Apply.hpp"
#include "utilities/StdioUtils.hpp"
#include "utilities/MemoryUtils.hpp"

using namespace Math;

using ShapeManager2D = std::vector<std::shared_ptr<Shape>>;
using MenuItem = std::pair<int, std::string>;

class Application
{
public:
  Application()
  {
    shapeList = {
        {1, {"Square", Square::ShapeType}},
        {2, {"Rectangle", Rectangle::ShapeType}},
        {3, {"Right Triangle", RightTriangle::ShapeType}},
        {4, {"Circle", Circle::ShapeType}},
        {5, {"Half Circle", HalfCircle::ShapeType}},
        {6, {"Quarter Circle", QuarterCircle::ShapeType}}};
  };

  int start()
  {
    Shape
        *square = new Square(),
        *rectangle = new Rectangle(),
        *rightTriangle = new RightTriangle(),
        *circle = new Circle(),
        *halfCircle = new HalfCircle(),
        *quarterCircle = new QuarterCircle();

    Utils::apply(
        Utils::shapePropertyDisplayer,
        square, rectangle, rightTriangle, circle, halfCircle, quarterCircle);

    Utils::apply(
        Utils::objectDeleter,
        square, rectangle, rightTriangle, circle, halfCircle, quarterCircle);

    // TODO: Design and Implement Console Input Output System
    return 0;
  }

private:
  // A collection of shape objects
  ShapeManager2D shapes;

  // List of shapes available to use.
  std::unordered_map<int, std::pair<std::string, std::string>> shapeList;
};

int main()
{
  Application app;
  return app.start();
}
