
#pragma once

#include "Typedefs.hpp"
#include "Shape.hpp"

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