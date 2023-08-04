#ifndef FEMALE_DENSEMATRIX_HPP
#define FEMALE_DENSEMATRIX_HPP
#include <cstddef>



class DenseMatrix
{
    public:
        DenseMatrix() = default;
        DenseMatrix(int nrows, int ncols);
        DenseMatrix(const DenseMatrix& other);
        DenseMatrix( DenseMatrix&& other);
        DenseMatrix operator = (const DenseMatrix& other);
        ~DenseMatrix();

        double& index(int i, int j);
        const double& index(int i, int j) const;

        double& operator()(int i, int j);
        const double& operator()(int i, int j) const;

        double* data();
        std::size_t num_rows() const;
        std::size_t num_cols() const;
        std::size_t size() const;

        const double* data() const;
        DenseMatrix transpose() const;

        bool is_square() const;

    private:
        int m_nrows  = 0; 
        int m_ncols  = 0;
        double* m_data = nullptr;
        
};
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

inline DenseMatrix::DenseMatrix(int nrows, int ncols)
{
    m_nrows = nrows;
    m_ncols = ncols;
    m_data = new double [nrows * ncols];
}
//-----------------------------------------------------
//-----------------------------------------------------

inline DenseMatrix::DenseMatrix(DenseMatrix&& other)
{
    m_nrows = other.m_nrows;
    m_ncols = other.m_ncols;
    m_data  = other.m_data;

    other.m_nrows = 0;
    other.m_data  = nullptr;
    other.m_ncols = 0;
}
//-----------------------------------------------------
//-----------------------------------------------------
inline DenseMatrix::~DenseMatrix()
{
    delete [] m_data;
    m_data = nullptr;
    m_nrows = 0;
    m_ncols = 0;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline DenseMatrix::DenseMatrix(const DenseMatrix& other)
{
    m_nrows = other.m_nrows;
    m_ncols = other.m_ncols;
    m_data  = new double [m_nrows * m_ncols];

    for(std::size_t i = 0; i < (m_nrows * m_ncols); ++i){
        m_data[i] = other.m_data[i];
    }
}
//-----------------------------------------------------
//-----------------------------------------------------

inline double& DenseMatrix::index(int i, int j)
{
    return m_data[i * m_ncols + j ];
}
//-----------------------------------------------------
//-----------------------------------------------------

inline const double& DenseMatrix::index(int i, int j) const
{
    return m_data[i * m_ncols + j ];
}
//-----------------------------------------------------
//-----------------------------------------------------

inline bool DenseMatrix::is_square() const{
    return (m_nrows == m_ncols);
}
//-----------------------------------------------------
//-----------------------------------------------------

inline DenseMatrix DenseMatrix::transpose() const 
{
    DenseMatrix transpose(m_ncols, m_nrows);

    for(int i = 0; i < m_ncols; ++i){
        for(int j = 0; j < m_nrows; ++j){
            transpose.index(i,j) = index(j,i);
        }
    }

    return transpose;
}


inline DenseMatrix DenseMatrix::operator = (const DenseMatrix& other)
{
    return DenseMatrix(other);
}
//-----------------------------------------------------
//-----------------------------------------------------

inline double& DenseMatrix::operator()(int i, int j)
{
    return index(i,j);
}
//-----------------------------------------------------
//-----------------------------------------------------

inline const double& DenseMatrix::operator()(int i, int j) const
{
    return index(i,j);
}
//-----------------------------------------------------
//-----------------------------------------------------

inline double* DenseMatrix::data() 
{
    return m_data;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline const double* DenseMatrix::data() const
{
    return m_data;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline std::size_t DenseMatrix::num_rows() const{
    return m_nrows;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline std::size_t DenseMatrix::num_cols() const{
    return m_ncols;
}
//-----------------------------------------------------
//-----------------------------------------------------

inline std::size_t DenseMatrix::size() const{
    return m_nrows * m_ncols;
}
//-----------------------------------------------------
//-----------------------------------------------------


#endif //FEMALE_DENSEMATRIX_HPP