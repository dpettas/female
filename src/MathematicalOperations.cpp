#include "MathematicalOperations.hpp"
#include "Vector.hpp"
#include "DenseMatrix.hpp"

#include <iostream>
#include <cmath>

extern "C"{
    void dgetrf_(int* M, int *N, double* A, int* lda, int* IPIV, int* INFO);
    void dgetrs_(char* C, int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO);
}


namespace female::math{

    double from_rad_to_deg(double theta_rad){
        return theta_rad * 180.0/M_PI;
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double from_deg_to_rad(double theta_deg){
        return theta_deg * M_PI/180.0;
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double l2_norm_sq(const Vector& vec){
        double sum = 0.0;

        for(int i = 0; i < vec.size(); ++i){
            sum += vec(i) * vec(i);
        }
        return sum;
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double l2_norm(const Vector& vec){
        return std::sqrt(l2_norm_sq(vec));
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    Vector solve( DenseMatrix& A, Vector& b )
    {
        int N = A.num_rows();
        int* ipiv = new int [N];
        int info;

        dgetrf_(&N, &N, A.data(), &N, ipiv, &info);
        char trans='T';
        int nrhs = 1;
        dgetrs_(&trans, &N, &nrhs, A.data(), &N, ipiv, b.data(), &N, &info);


        return Vector(b);
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double dist_sq(const Point3& p1, const Point3& p0){
       return (p1.x0() - p0.x0()) * (p1.x0() - p0.x0()) +
              (p1.x1() - p0.x1()) * (p1.x1() - p0.x1()) +
              (p1.x2() - p0.x2()) * (p1.x2() - p0.x2());
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double dist(const Point3& p1, const Point3& p0){
        return std::sqrt(dist_sq(p1,p0));
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    Vec3 normalize(const Vec3& v){
        double inv_norm = 1.0/v.norm();
        return inv_norm * v;
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double dot(const Vec3& v0, const Vec3& v1){
       return v0.x0() * v1.x0() + 
              v0.x1() * v1.x1() +
              v0.x2() * v1.x2();
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    double angle(const Vec3& v0, const Vec3& v1){
        double v0_norm = v0.norm();
        double v1_norm = v1.norm();

        return std::acos( dot(v0,v1)/(v0_norm * v1_norm));
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    Vec3 proj(const Vec3& v0, const Vec3& v1){
        return dot(v0,v1)/dot(v0,v0) * v1;
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    Vec3 perpendicular(const Vec3& v0, const Vec3& v1){
        return v0 - proj(v0,v1);
    }
    //----------------------------------------------------------
    //----------------------------------------------------------

    Vec3 cross(const Vec3& v0, const Vec3& v1){
        Vec3 out;
        out[0] = +(v0[1] * v1[2] - v0[2] * v1[1]);
        out[1] = -(v0[0] * v1[2] - v0[2] * v1[0]);
        out[2] = +(v0[0] * v1[1] - v0[1] * v1[0]);
        return out;
    }
    //----------------------------------------------------------
    //----------------------------------------------------------


}

