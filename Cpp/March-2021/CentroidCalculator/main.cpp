
#include <iostream>
#include <tuple>
#include <array>
#include <cmath>
#include <string>

#include "MathLib.hpp"

#include "include/Body.hpp"
#include "include/Square.hpp"
#include "include/Circle.hpp"
#include "include/HalfCircle.hpp"

using namespace Math;

int main()
{
    /*
    Body<2> *circleBody = new Circle(2);
    circleBody->setLocation({10, 10});

    auto circleBodyCentroid = circleBody->getCentroid();

    std::cout << "Cx: " << circleBodyCentroid[0] << std::endl
              << "Cy: " << circleBodyCentroid[1] << std::endl;
    */
    std::cout << 180.0_deg << std::endl;
    return 0;
}
