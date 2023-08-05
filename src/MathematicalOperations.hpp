#ifndef FEMALE_MATHEMATICALOPERATIONS_HPP
#define FEMALE_MATHEMATICALOPERATIONS_HPP

#include "Point3.hpp"
#include "Vec3.hpp"
#include "Vector.hpp"
#include "DenseMatrix.hpp"


namespace female::math
{
    double from_rad_to_deg(double theta_rad);
    double from_deg_to_rad(double theta_deg);

    Vec3 normalize(const Vec3& v);
    double angle(const Vec3& v0, const Vec3& v1);
    Vec3 proj(const Vec3& v0, const Vec3& v1);
    Vec3 perpendicular(const Vec3& v0, const Vec3& v1);

    double dot(const Vec3& v0, const Vec3& v1);
    Vec3 cross(const Vec3& v0, const Vec3& v1);




    double dist(const Point3& p1, const Point3& p0);
    double dist_sq(const Point3& p1, const Point3& p0);



    double l2_norm_sq(const Vector& vec);
    double l2_norm   (const Vector& vec);
    Vector solve( DenseMatrix& A, Vector& b );
    
} // namespace FEMALE::Test




#endif