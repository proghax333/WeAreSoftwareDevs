
#include <iostream>
#include <tuple>
#include <array>
#include <cmath>

namespace Math
{
  const long double PI = 3.1415926535;
}

using Number = long double;

template <size_t _Size>
using Vector = std::array<Number, _Size>;

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

template <size_t _Size>
class Body : public virtual Shape
{
public:
  virtual ~Body()
  {
  }
  virtual Vector<_Size> getLocation()
  {
    return location;
  }
  virtual void setLocation(const Vector<_Size> &location)
  {
    this->location = location;
  }

  virtual Vector<2> getCentroid() = 0;

protected:
  Vector<_Size> location = {0, 0};
};

class Square : public virtual Shape, public AreaInterface, public virtual Body<2>
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

  Number getArea() override
  {
    return this->sideLength * this->sideLength;
  }
  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    return Vector<2>({0, 0});
  }

private:
  Number sideLength = 0.0;
};

class Circle : public virtual Shape, public virtual AreaInterface, public virtual Body<2>
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

  Number getArea() override
  {
    return Math::PI * this->radius * this->radius;
  }

  Vector<2> getCentroid() override
  {
    auto location = this->getLocation();
    return Vector<2>({location[0], location[1]});
  }

private:
  Number radius = 0.0;
};

int main()
{
  Body<2> *circleBody = new Circle(2);
  circleBody->setLocation({10, 10});

  auto circleBodyCentroid = circleBody->getCentroid();

  std::cout << "Cx: " << circleBodyCentroid[0] << std::endl
            << "Cy: " << circleBodyCentroid[1] << std::endl;

  return 0;
}
