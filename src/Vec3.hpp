#ifndef FEMALE_VEC3_HPP
#define FEMALE_VEC3_HPP

#include <cstddef>
#include <iostream>
#include <cmath>
#include "Point3.hpp"

namespace female
{
    

    class Vec3
    {
        public:
            Vec3();
            explicit Vec3(double x0, double x1, double x2);
            explicit Vec3(const Point3& end, const Point3& begin = Point3(0.0,0.0,0.0));
            
            std::size_t size() const;
            double norm_sq() const;
            double norm() const;

            double& x0();
            double& x1();
            double& x2();

            const double& x0() const;
            const double& x1() const;
            const double& x2() const;

            double& operator[] (int i);
            const double& operator[] (int i) const;
            Vec3  operator+ (const Vec3& other) const;
            Vec3  operator- (const Vec3& other) const;
            Vec3& operator+=(const Vec3& other);
            Vec3& operator-=(const Vec3& other);
            Vec3& operator*=(double lambda);
            
            friend std::ostream& operator << (std::ostream&, const Vec3& vec);

        private:
            double m_x[3];
    };
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    Vec3 operator*(double lambda, const Vec3& v);


    inline Vec3::Vec3(){
        m_x[0] = 0.0;
        m_x[1] = 0.0;
        m_x[2] = 0.0;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3::Vec3(double x0, double x1, double x2){
        m_x[0] = x0;
        m_x[1] = x1;
        m_x[2] = x2;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3::Vec3(const Point3& end, const Point3& begin){
        m_x[0] = end.x0() - begin.x0();
        m_x[1] = end.x1() - begin.x1();
        m_x[2] = end.x2() - begin.x2();
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline std::size_t Vec3::size() const{
        return 3;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline double& Vec3::x0(){
        return m_x[0];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline double& Vec3::x1(){
        return m_x[1];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline double& Vec3::x2(){
        return m_x[2];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline const double& Vec3::x0() const{
        return m_x[0];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline const double& Vec3::x1() const{
        return m_x[1];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline const double& Vec3::x2() const{
        return m_x[2];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3 Vec3::operator+(const Vec3& other) const{
        Vec3 out;
        out.m_x[0] = m_x[0] + other.m_x[0];
        out.m_x[1] = m_x[1] + other.m_x[1];
        out.m_x[2] = m_x[2] + other.m_x[2];

        return out;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3 Vec3::operator-(const Vec3& other) const{
        Vec3 out;
        out.m_x[0] = m_x[0] - other.m_x[0];
        out.m_x[1] = m_x[1] - other.m_x[1];
        out.m_x[2] = m_x[2] - other.m_x[2];

        return out;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3& Vec3::operator+=(const Vec3& other){
        m_x[0] += other.m_x[0];
        m_x[1] += other.m_x[1];
        m_x[2] += other.m_x[2];

        return *this;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3& Vec3::operator-=(const Vec3& other){
        m_x[0] -= other.m_x[0];
        m_x[1] -= other.m_x[1];
        m_x[2] -= other.m_x[2];

        return *this;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3& Vec3::operator*=(double lambda){
        m_x[0] *= lambda;
        m_x[1] *= lambda;
        m_x[2] *= lambda;

        return *this;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline double& Vec3::operator[] (int i){
        return m_x[i];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline const double& Vec3::operator[] (int i) const{
        return m_x[i];
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline double Vec3::norm_sq() const {
        return (m_x[0] * m_x[0]) + (m_x[1] * m_x[1]) + (m_x[2] * m_x[2]);
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline double Vec3::norm() const{
        return std::sqrt(norm_sq());
    }
    //------------------------------------------------------
    //------------------------------------------------------


    inline std::ostream& operator << (std::ostream& os, const Vec3& vec){
        char buf [1024];
        sprintf(buf,"[%f,%f,%f]",vec.x0(), vec.x1(), vec.x2());
        os << buf;
        return os;
    }
    //------------------------------------------------------
    //------------------------------------------------------

    inline Vec3 operator*(double lambda, const Vec3& v){
        Vec3 out(v);
        out.x0() *= lambda;
        out.x1() *= lambda;
        out.x2() *= lambda;

        return out;
    }
    //------------------------------------------------------
    //------------------------------------------------------

}


#endif