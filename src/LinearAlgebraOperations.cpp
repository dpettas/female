#include "LinearAlgebraOperations.hpp"
#include "Vector.hpp"
#include "DenseMatrix.hpp"

extern "C"{
    void dgetrf_(int* M, int *N, double* A, int* lda, int* IPIV, int* INFO);
    void dgetrs_(char* C, int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO);
}


Vector solver( DenseMatrix& A, Vector& b )
{
    int N = A.num_rows();
    int* ipiv = new int [N];
    int info;

    dgetrf_(&N, &N, A.data(), &N, ipiv, &info);

    return Vector();
}