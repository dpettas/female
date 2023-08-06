#include <iostream>
#include "DenseMatrix.hpp"
#include "Vector.hpp"
#include "Point3.hpp"
#include "Vec3.hpp"
#include "MathematicalOperations.hpp"
#include "Mesh1D.hpp"
#include "InterpolationFunctionsLagrange.hpp"


int main(int, char**){
    using namespace female;

    // female::Mesh1D mesh(Point3(0.0,0.0,0.0), Point3(1.0, 2.00, 3.0), 10);
    female::math::interp::Lagrange<2> phi(
        { [](double x){  return 0.5 * (1.0 - x); }, 
          [](double x){  return 0.5 * (1.0 + x); } }, 

        { [](double xi){  return -0.50; }, 
          [](double xi){  return +0.50; } }
        );


    std::cout << phi.func(1)(1.0) << std::endl;

    return 0;
}
