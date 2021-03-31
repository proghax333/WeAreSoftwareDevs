
#pragma once

#include <functional>

namespace Utils
{

  template <typename... Types>
  void apply(auto operation, Types &&...objs)
  {
    (..., operation(objs));
  }

}
