#ifndef FEMALE_LINEARALGEBRAOPERATIONS_HPP
#define FEMALE_LINEARALGEBRAOPERATIONS_HPP

#include "Vector.hpp"
#include "DenseMatrix.hpp"


namespace female::math
{
    double l2_norm_sq(const Vector& vec);
    double l2_norm   (const Vector& vec);
    Vector solve( DenseMatrix& A, Vector& b );
    
} // namespace FEMALE::Test




#endif