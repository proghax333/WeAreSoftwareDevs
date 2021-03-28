
#include <iostream>

namespace Math
{
  const long double PI = 3.1415926535;
}

using Number = long double;

using Vector2 = std::tuple<Number, Number>;
using Vector3 = std::tuple<Number, Number>;

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

class AreaInterface
{
public:
  virtual Number getArea() = 0;
};

class VolumeInterface
{
public:
  virtual Number getVolume() = 0;
};

class Square : public virtual Shape, AreaInterface
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
  Number getArea()
  {
    return this->sideLength * this->sideLength;
  }

private:
  Number sideLength = 0.0;
};

class Circle : public virtual Shape, AreaInterface
{
public:
  Circle()
  {
    this->setShapeType("circle");
  }
  Circle(const Number &radius) : radius(radius)
  {
    this->setShapeType("circle");
  }

  Number getArea()
  {
    return Math::PI * this->radius * this->radius;
  }

private:
  Number radius = 0.0;
};

int main()
{

  return 0;
}