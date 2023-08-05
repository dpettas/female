#include "LinearAlgebraOperations.hpp"
#include "Vector.hpp"
#include "DenseMatrix.hpp"

#include <iostream>
#include <cmath>

extern "C"{
    void dgetrf_(int* M, int *N, double* A, int* lda, int* IPIV, int* INFO);
    void dgetrs_(char* C, int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO);
}


namespace female::math{

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

    double dist_sq(const Point& p1, const Point& p0){
       return (p1.x0() - p0.x0()) * (p1.x0() - p0.x0()) +
              (p1.x1() - p0.x1()) * (p1.x1() - p0.x1()) +
              (p1.x2() - p0.x2()) * (p1.x2() - p0.x2());
    }
//----------------------------------------------------------
//----------------------------------------------------------

    double dist(const Point& p1, const Point& p0){
        return std::sqrt(dist(p1,p0));
    }



}

