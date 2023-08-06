#include <iostream>
#include "DenseMatrix.hpp"
#include "Vector.hpp"
#include "Point3.hpp"
#include "Vec3.hpp"
#include "MathematicalOperations.hpp"
#include "Mesh1D.hpp"


int main(int, char**){
    using namespace female;

    female::Mesh1D mesh(Point3(0.0,0.0,0.0), Point3(1.0, 2.00, 3.0), 10);

    std::cout << mesh << std::endl;

    return 0;
}
