
#pragma once

#include <functional>

namespace Utils
{

  auto shapePropertyDisplayer = [](auto shape) {
    auto props = shape->getAllProperties();

    std::cout << "[Shape Properties]\n"
                 "  Shape Name = "
              << shape->getShapeType() << std::endl;

    for (auto [propertyName, property] : props)
    {
      if (property.type == "shapeProperty")
      {
        std::cout << " - " << propertyName << std::endl;
      }
    }

    std::cout << "\n\n";
  };

}