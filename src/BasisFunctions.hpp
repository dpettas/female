#ifndef FEMALE_BASIS_FUNCTIONS_HPP
#define FEMALE_BASIS_FUNCTIONS_HPP

#include "InterpolationFunctionsLagrange.hpp"

namespace female::fem::BasisFunctions{
    using namespace female::math::interp;

static Lagrange<2> Lagrange1DL    ({ [](double x){return 0.5*(1.0 - x);}, 
                                     [](double x){return 0.5*(1.0 + x);} });

static Lagrange<3> Lagrange1DQ    ({ [](double x){return 0.50 * (1.0 - x) * x;}, 
                                     [](double x){return (1.0-x) * (1.0 + x) ;},
                                     [](double x){return 0.50 * (1.0 + x) * x;} });


}


#endif