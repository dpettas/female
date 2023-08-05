#ifndef FEMALE_POINT_HPP
#define FEMALE_POINT_HPP

#include <cstddef>
#include <iostream>

namespace female
{
    
    class Point3
    {
        public: 
            Point3();
            explicit Point3(double x0, double x1, double x2);

            std::size_t size() const;

            const double& x0() const;
            const double& x1() const;
            const double& x2() const;
            double& x0();
            double& x1();
            double& x2();

            Point3  operator + (const Point3& other);
            Point3  operator - (const Point3& other);
            Point3  operator * (double lambda);

            Point3& operator +=(const Point3& other);
            Point3& operator -=(const Point3& other);

            friend std::ostream& operator << (std::ostream&, const Point3& p);
            
        private: 
            double m_x[3];
    };
    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////

    inline Point3::Point3()
    {
        m_x[0] = 0.0;
        m_x[1] = 0.0;
        m_x[2] = 0.0;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point3::Point3(double x0, double x1, double x2)
    {
        m_x[0] = x0;
        m_x[1] = x1;
        m_x[2] = x2;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point3 Point3::operator+(const Point3& other){
        Point3 out;
        out.m_x[0] = m_x[0] + other.m_x[0];
        out.m_x[1] = m_x[1] + other.m_x[1];
        out.m_x[2] = m_x[2] + other.m_x[2];
        return out;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point3 Point3::operator-(const Point3& other){
        Point3 out;
        out.m_x[0] = m_x[0] - other.m_x[0];
        out.m_x[1] = m_x[1] - other.m_x[1];
        out.m_x[2] = m_x[2] - other.m_x[2];
        return out;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point3& Point3::operator+=(const Point3& other){
        m_x[0] += other.m_x[0];
        m_x[1] += other.m_x[1];
        m_x[2] += other.m_x[2];
        return *this;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point3& Point3::operator-=(const Point3& other){
        m_x[0] -= other.m_x[0];
        m_x[1] -= other.m_x[1];
        m_x[2] -= other.m_x[2];
        return *this;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point3 Point3::operator * (double lambda){
        Point3 out;
        out.m_x[0] = lambda * m_x[0];
        out.m_x[1] = lambda * m_x[1];
        out.m_x[2] = lambda * m_x[2];
        return out;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline const double& Point3::x0() const{
        return m_x[0];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline const double& Point3::x1() const{
        return m_x[1];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline const double& Point3::x2() const{
        return m_x[2];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline double& Point3::x0(){
        return m_x[0];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline double& Point3::x1(){
        return m_x[1];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline double& Point3::x2(){
        return m_x[2];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline std::size_t Point3::size() const{
        return 3;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline std::ostream& operator << (std::ostream& os, const Point3& p){
        char buf[1024];
        sprintf(buf,"Point3 :: [%f,%f,%f]", p.x0(), p.x1(), p.x2());
        os << buf;
        return os;
    }

}

#endif