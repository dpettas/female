#ifndef FEMALE_LINEARALGEBRAOPERATIONS_HPP
#define FEMALE_LINEARALGEBRAOPERATIONS_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "DenseMatrix.hpp"


namespace female::math
{
    double dist(const Point& p1, const Point& p0);
    double dist_sq(const Point& p1, const Point& p0);



    double l2_norm_sq(const Vector& vec);
    double l2_norm   (const Vector& vec);
    Vector solve( DenseMatrix& A, Vector& b );
    
} // namespace FEMALE::Test




#endif