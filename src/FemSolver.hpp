#ifndef FEMALE_FEMSOLVER_HPP
#define FEMALE_FEMSOLVER_HPP

#include "DenseMatrix.hpp"
#include "Vector.hpp"
#include "Mesh1D.hpp"
#include "InterpolationFunctionsLagrange.hpp"
#include "BasisFunctions.hpp"
#include "MathematicalOperations.hpp"


namespace female::fem::solver{

    class FemSolver
    {
        public:
            FemSolver() = default;

            void SetMesh( const Mesh1D& mesh);
            void SetBasisFunctions(const math::interp::Lagrange<2>& BasisFunc);
        private:
            Mesh1D                    m_mesh;
            math::interp::Lagrange<2> m_phi;
            Vector      rhs;
            DenseMatrix Jac;

    };
    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////

    void FemSolver::SetMesh(const Mesh1D& mesh){
        m_mesh = mesh;
    }
    //-----------------------------------------------------
    //-----------------------------------------------------

    void FemSolver::SetBasisFunctions( const math::interp::Lagrange<2>& BasisFunc){
        m_phi = BasisFunc;
    }
    //-----------------------------------------------------
    //-----------------------------------------------------



}





#endif