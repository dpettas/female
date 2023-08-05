#ifndef FEMALE_MESH1D_HPP
#define FEMALE_MESH1D_HPP

#include "Point.hpp"

namespace female{

    class Mesh1D
    {
        public:
            Mesh1D( Point begin, Point end    , int num_elements);
            Mesh1D( Point begin, double length, int num_elements);
            Mesh1D(const Mesh1D& other);
            Mesh1D& operator = (const Mesh1D& other);
            ~Mesh1D();

        private:
            int    m_nnodes= 0;
            Point* m_nodes = nullptr;
    };
    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////

    inline Mesh1D::Mesh1D(Point begin, Point end, int num_elements){

        m_nnodes = num_elements + 1;
        m_nodes  = new Point [m_nnodes];

        for(int i = 1; i < m_nnodes; ++i){
            m_nodes[i];
        }


    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline Mesh1D::~Mesh1D(){
        m_nnodes = 0;
        delete [] m_nodes;
        m_nodes = nullptr;
    }
    //---------------------------------------------------
    //---------------------------------------------------

}
#endif