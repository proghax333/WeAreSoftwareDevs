
#pragma once

namespace Utils
{

  auto objectDeleter = [](auto object) {
    delete object;
  };

}
