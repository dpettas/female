#ifndef FEMALE_POINT_HPP
#define FEMALE_POINT_HPP

#include <cstddef>

namespace female
{
    
    class Point
    {
        public: 
            Point();
            Point(double x0, double x1, double x2);

            const double& x0() const;
            const double& x1() const;
            const double& x2() const;
            double& x0();
            double& x1();
            double& x2();

            Point  operator + (const Point& other);
            Point  operator - (const Point& other);
            Point  operator * (double lambda);

            Point& operator +=(const Point& other);
            Point& operator -=(const Point& other);

            
        private: 
            double m_x[3];
    };
    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////

    inline Point::Point()
    {
        m_x[0] = 0.0;
        m_x[1] = 0.0;
        m_x[2] = 0.0;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point::Point(double x0, double x1, double x2)
    {
        m_x[0] = x0;
        m_x[1] = x1;
        m_x[2] = x2;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point Point::operator+(const Point& other){
        Point out;
        out.m_x[0] = m_x[0] + other.m_x[0];
        out.m_x[1] = m_x[1] + other.m_x[1];
        out.m_x[2] = m_x[2] + other.m_x[2];
        return out;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point Point::operator-(const Point& other){
        Point out;
        out.m_x[0] = m_x[0] - other.m_x[0];
        out.m_x[1] = m_x[1] - other.m_x[1];
        out.m_x[2] = m_x[2] - other.m_x[2];
        return out;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point& Point::operator+=(const Point& other){
        m_x[0] += other.m_x[0];
        m_x[1] += other.m_x[1];
        m_x[2] += other.m_x[2];
        return *this;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point& Point::operator-=(const Point& other){
        m_x[0] -= other.m_x[0];
        m_x[1] -= other.m_x[1];
        m_x[2] -= other.m_x[2];
        return *this;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline Point Point::operator * (double lambda){
        Point out;
        out.m_x[0] = lambda * m_x[0];
        out.m_x[1] = lambda * m_x[1];
        out.m_x[2] = lambda * m_x[2];
        return out;
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline const double& Point::x0() const{
        return m_x[0];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline const double& Point::x1() const{
        return m_x[1];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline const double& Point::x2() const{
        return m_x[2];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline double& Point::x0(){
        return m_x[0];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline double& Point::x1(){
        return m_x[1];
    }
    //--------------------------------------------------
    //--------------------------------------------------

    inline double& Point::x2(){
        return m_x[2];
    }
    //--------------------------------------------------
    //--------------------------------------------------

}

#endif