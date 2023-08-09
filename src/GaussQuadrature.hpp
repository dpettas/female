#ifndef FEMALE_GAUSS_QUADRATURE_HPP
#define FEMALE_GAUSS_QUADRATURE_HPP

#include <array>
#include <cmath>


namespace female::math::integr
{
    struct GPoint1D{
        double x;
        double w;
    };

    static std::array<GPoint1D,1> Gpoint1D_1 = { {0.0, 2.0} };
    // static std::array<GPoint1D,2> Gpoint1D_2 = { { 1.0, 1.0},
    //                                              {-1.0, 1.0} };



    
} 






#endif