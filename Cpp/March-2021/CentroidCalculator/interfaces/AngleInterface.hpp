
#pragma once

#include <array>

#include "Typedefs.hpp"

template <size_t _NumberOfAngles>
class AngleInterface
{
public:
  ~AngleInterface()
  {
  }

  std::array<Number, _NumberOfAngles> &getAngles()
  {
    return this->angles;
  }
  void setAngles(const std::array<Number, _NumberOfAngles> &angles)
  {
    this->angles = angles;
  }

public:
  std::array<Number, _NumberOfAngles> angles;
};