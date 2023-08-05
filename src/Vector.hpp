#ifndef FEMALE_VECTOR_HPP
#define FEMALE_VECTOR_HPP

#include <cstddef>
#include <vector>
#include <iostream>

class Vector
{
    public:
        Vector() = default;
        Vector(int nrows);
        Vector(const Vector& other);
        Vector(Vector&& other);
        Vector operator = (const Vector& other);
        Vector(std::vector<double> vec);
        ~Vector();

        double* data();
        const double* data() const;
        std::size_t num_rows() const;
        std::size_t num_cols() const;
        std::size_t size() const;

        double& index(int row);
        const double& index(int row) const;

        double& operator() (int row);
        const double& operator()(int row) const;

        friend std::ostream& operator << (std::ostream& os, const Vector& vec);

    private:
        int m_nrows = 0;
        double* m_data = nullptr;
};
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

inline Vector::Vector(int nrows)
{
    m_nrows = nrows;
    m_data  = new double [m_nrows];
}

//-----------------------------------------------------
//-----------------------------------------------------

inline Vector::Vector(std::vector<double> vec)
{
    m_nrows = vec.size();
    m_data  = new double [m_nrows];
    for(int i = 0; i < m_nrows; ++i){
        m_data[i] = vec[i];
    }
}

//-----------------------------------------------------
//-----------------------------------------------------

inline Vector::~Vector()
{
    delete [] m_data;
    m_data = nullptr;
    m_nrows = 0;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline Vector::Vector(const Vector& other)
{
    m_nrows = other.m_nrows;
    m_data  = new double [m_nrows];

    for(std::size_t i = 0; i < m_nrows; ++i){
        m_data[i] = other.m_data[i];
    }
}
//-----------------------------------------------------
//-----------------------------------------------------

inline Vector::Vector(Vector&& other){
    m_nrows = other.m_nrows;
    m_data  = other.m_data;
    other.m_data = nullptr;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline Vector Vector::operator=(const Vector& other){
    return Vector(other);
}


//-----------------------------------------------------
//-----------------------------------------------------

inline double& Vector::index(int row)
{
    return m_data[row];
}
//-----------------------------------------------------
//-----------------------------------------------------

inline const double& Vector::index(int row) const
{
    return m_data[row];
}
//-----------------------------------------------------
//-----------------------------------------------------

inline double& Vector::operator()(int row){
    return index(row);
}
//-----------------------------------------------------
//-----------------------------------------------------

inline const double& Vector::operator()(int row) const{
    return index(row);
}
//-----------------------------------------------------
//-----------------------------------------------------

inline std::size_t Vector::num_rows() const{
    return m_nrows;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline std::size_t Vector::size() const{
    return m_nrows;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline std::size_t Vector::num_cols() const{
    return 1;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline double* Vector::data(){
    return m_data;
}

//-----------------------------------------------------
//-----------------------------------------------------

inline const double* Vector::data() const{
    return m_data;
}

//-----------------------------------------------------
//-----------------------------------------------------

inline std::ostream& operator << (std::ostream& os, const Vector& vec){
    os << '[';
    for(int i = 0; i < vec.m_nrows; ++i){
        os << vec(i) << " ";
    }
    os << ']';

    return os;
}
//-----------------------------------------------------
//-----------------------------------------------------




#endif // FEMALE_VECTOR_HPP


