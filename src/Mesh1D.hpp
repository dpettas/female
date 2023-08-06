#ifndef FEMALE_MESH1D_HPP
#define FEMALE_MESH1D_HPP

#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include "Point3.hpp"
#include "Vec3.hpp"
#include "MathematicalOperations.hpp"

namespace female{

    class Mesh1D
    {
        public:
            Mesh1D( Point3 begin, Point3 end   , int num_elements);
            Mesh1D(const Mesh1D& other);
            Mesh1D& operator = (const Mesh1D& other); 
            ~Mesh1D();

            std::size_t num_nodes() const;
            std::size_t num_elements() const;

            Point3* nodes();
            const Point3* nodes() const;

            Point3& node(int i);
            const Point3& node(int i) const;

            std::array<int,2>& element(int i);
            const std::array<int,2>& element(int i) const;
            
            friend std::ostream& operator << (std::ostream& os, const Mesh1D& mesh);

        private:
            int     m_nnodes= 0;
            Point3* m_nodes = nullptr;
            std::vector<std::array<int,2>> m_conn;
    };
    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////

    inline Mesh1D::Mesh1D(Point3 begin, Point3 end, int num_elements){

        m_nnodes = num_elements + 1;
        m_nodes  = new Point3 [m_nnodes];

        // Discretize
        double step = 1.0/(m_nnodes - 1);
        for(int i = 0; i < m_nnodes; ++i){
            m_nodes[i] = begin + i * step * end;
        }

        // Connect the nodes creating linear elements
        m_conn.reserve(num_elements);
        for(int i =0 ; i < m_nnodes-1; ++i){
            m_conn.push_back( {i,i+1} );
        }
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline Mesh1D::Mesh1D(const Mesh1D& other){
        m_nnodes = other.m_nnodes;
        m_nodes  = new Point3 [m_nnodes];
        m_conn   = other.m_conn;

        for(int i = 0; i < m_nnodes; ++i){
            m_nodes[i] = other.m_nodes[i];
        }
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline Mesh1D::~Mesh1D(){
        m_nnodes = 0;
        delete [] m_nodes;
        m_nodes = nullptr;
        m_conn.clear();
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline Mesh1D& Mesh1D::operator = (const Mesh1D& other){
        m_nnodes = 0;
        m_nodes  = new Point3 [m_nnodes];
        m_conn   = other.m_conn;

        for(int i = 0; i < m_nnodes; ++i){
            m_nodes[i] = other.m_nodes[i];
        }

        return *this;
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline std::size_t Mesh1D::num_nodes() const {
        return m_nnodes;
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline std::size_t Mesh1D::num_elements() const{
        return m_nnodes - 1;
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline Point3& Mesh1D::node(int i){
        return m_nodes[i];
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline const Point3& Mesh1D::node(int i) const{
        return m_nodes[i];
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline const Point3* Mesh1D::nodes() const {
        return m_nodes;
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline Point3* Mesh1D::nodes() {
        return m_nodes;
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline std::array<int,2>& Mesh1D::element(int i){
        return m_conn[i];
    }
    //---------------------------------------------------
    //---------------------------------------------------

    inline const std::array<int,2>& Mesh1D::element(int i) const{
        return m_conn[i];
    }
    //---------------------------------------------------
    //---------------------------------------------------

    std::ostream& operator << (std::ostream& os, const Mesh1D& mesh){
        os << "Type         :: Mesh1D";
        os << "Num Nodes    :: " << mesh.m_nnodes       << std::endl;
        os << "Num Elements :: " << mesh.num_elements() << std::endl;
        os << "Nodes        :: " << std::endl;

        for(int i = 0; i < mesh.m_nnodes; ++i){
            std::cout << '\t' << i << " :: " << mesh.m_nodes[i] << std::endl;
        }
        
        os << "Elements     :: " << std::endl;
        int ielem = 0;
        for(auto& elem : mesh.m_conn){
            std::cout << '\t' << ielem++ << " :: (" << elem[0] << "," << elem[1] << ")" << std::endl;
        }

        return os;
    }
    //---------------------------------------------------
    //---------------------------------------------------


}
#endif