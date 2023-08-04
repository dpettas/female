#ifndef FEMALE_VECTOR_HPP
#define FEMALE_VECTOR_HPP

class Vector
{
    public:
        Vector() = default;
        Vector(int nrows);
        ~Vector();

    private:
        int m_nrows = 0;
        double* m_data = nullptr;
};
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

Vector::Vector(int nrows)
{
    m_nrows = nrows;
    m_data  = new double [m_nrows];
}

//-----------------------------------------------------
//-----------------------------------------------------
Vector::~Vector()
{
    delete [] m_data;
    m_nrows = 0;
}

#endif // FEMALE_VECTOR_HPP


