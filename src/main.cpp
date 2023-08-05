#include <iostream>
#include "DenseMatrix.hpp"
#include "Vector.hpp"
#include "LinearAlgebraOperations.hpp"


int main(int, char**){

    DenseMatrix A ( {{1.0, 0.0, 0.0},
                     {1.0, 2.0, 0.0},
                     {1.0, 2.0, 3.0} });

    Vector B({1.0, 2.0, 3.0});

    std::cout << female::math::solve(A,B) << std::endl;

    return 0;
}
