#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <ostream>

using std::ostream;
using std::endl;

template <typename T>
struct Matrix{
    
   T m[4][4];

    Matrix(void);
    Matrix(const Matrix<T>&);
    
    Matrix& operator=(const Matrix<T>&);
    Matrix  operator*(const Matrix<T>&) const;
    Matrix  operator/(const T);
    void    set_identity(void);

    friend ostream &operator<<(ostream& os, const Matrix<T>& in)
    {
        for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++)
                os << in.m[x][y];
            os << endl;
        }
        return os;
    }
};
typedef Matrix<float>  Matrixf;
typedef Matrix<double> Matrixd;

template <typename T>
Matrix<T>::Matrix(void)
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++) {
	    if (x == y)
	        m[x][y] = 1;
	    else
		m[x][y] = 0;
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix& in)
{
    for (int x = 0; x < 4; x++)				
        for (int y = 0; y < 4; y++)			
	    m[x][y] = in.m[x][y];	
}

template <typename T>
Matrix<T>&
Matrix<T>::operator=(const Matrix<T>& in)
{
    if (this == &in)
        return (*this);

    for (int x = 0; x < 4; x++)				
        for (int y = 0; y < 4; y++)			
	    m[x][y] = in.m[x][y];	

    return (*this);
}

template <typename T>
Matrix<T>
Matrix<T>::operator*(const Matrix<T>& in) const
{
        Matrix<T> product;	

        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++) {
                T sum = 0;
                    for (int j = 0; j < 4; j++)
                        sum += m[x][j] * in.m[j][y]; 
			product.m[x][y] = sum;		
            }	

        return (product);
}

template <typename T>
Matrix<T>
Matrix<T>::operator/(const T in)
{
        for (int x = 0; x < 4; x++)				
            for (int y = 0; y < 4; y++)			
                m[x][y] = m[x][y] / in;	

        return (*this);
}

template <typename T>
void
Matrix<T>::set_identity(void)
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++) {
            if (x == y)
                m[x][y] = 1;
            else
                m[x][y] = 0;
        }
}
    
    

#endif
    
