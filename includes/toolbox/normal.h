#ifndef _NORMAL_H_
#define _NORMAL_H_

#include <math.h>

#include <ostream>
#include <cstdint>


using std::ostream;

template <typename T>
struct Vector;

template <typename T>
struct Point;

template <typename T>
struct Matrix;

template <typename T>
struct Normal{

    T x, y, z;

    Normal(void) : x(0), y(0), z(0) {}
    Normal(T a) : x(a), y(a), z(a) {}
    Normal(T x, T y, T z) : x(x), y(y), z(z) {}
    Normal(const Normal<T>&);
    Normal(const Vector<T>&);

           Normal<T>& operator=(const Normal<T>&);
           Normal<T>& operator=(const Vector<T>&);
           Normal<T>& operator=(const Point<T>&);
    inline Normal<T>& operator+=(const Normal<T>&);
    inline Normal<T>  operator-(void) const;
    inline Normal<T>  operator+(const Normal<T>&) const;
    inline Normal<T>  operator*(const T a) const;
    inline T          operator*(const Vector<T>&) const;
    inline T&         operator[](uint8_t); 
    
    void       normalize(void);

    friend ostream &operator<<(ostream& os, const Normal<T>& in)
    {
        os << "Normal: (" << in.x << "," << in.y << "," << in.z << ")";
        return os;
    }
};
typedef Normal<float>  Normalf;
typedef Normal<double> Normald;

template <typename T>
Normal<T>::Normal(const Normal<T>& in) : x(in.x), y(in.y), z(in.z)
{}

template <typename T>
Normal<T>::Normal(const Vector<T>& in) : x(in.x), y(in.y), z(in.z)
{}

template <typename T>
Normal<T>&
Normal<T>::operator=(const Normal<T>& rhs)
{
    if(this == &rhs)
        return (*this);

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return (*this);
}

template <typename T>
Normal<T>&
Normal<T>::operator=(const Vector<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return (*this);
}

template <typename T>
Normal<T>&
Normal<T>::operator=(const Point<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    
    return (*this);
}

template <typename T>
inline Normal<T>&
Normal<T>::operator+=(const Normal<T>& in) 
{
    x += in.x;
    y += in.y;
    z += in.z;
    
    return (*this);
}

template <typename T>
inline Normal<T>
Normal<T>::operator-(void) const
{
    return Normal<T>(-x,-y-z);
}

template <typename T>
inline Normal<T>
Normal<T>::operator+(const Normal<T>& in) const
{
    return Normal(x+in.x, y+in.y, z+in.y); 
}

template <typename T>
inline Normal<T>
Normal<T>::operator*(const T a) const 
{
    return Normal<T>(x*a, y*a, z*a);
}

template <typename T>
inline T
Normal<T>::operator*(const Vector<T>& in) const 
{
    return (x*in.x + y*in.y + z*in.z);
}

template <typename T>
inline T&
Normal<T>::operator[](uint8_t i) 
{
   return (&x)[i]; 
}

template <typename T>
void
Normal<T>::normalize(void)
{
    T length = sqrt(x*x + y*y + z*z);
    x /= length; y /= length; z /= length;
}
    
template <typename T>
inline Normal<T>
operator*(const T p, const Normal<T>& in)
{
    return Normal<T>(p*in.x, p*in.y, p*in.z);
}

template <typename T>
inline Vector<T>
operator+(const Vector<T>& v, const Normal<T>& n)
{
    return Vector<T>(v.x+n.x, v.y+n.y, v.z+n.z);
}

template <typename T>
inline Vector<T>
operator-(const Vector<T>& v, const Normal<T>& n)
{
    return Vector<T>(v.x-n.x, v.y-n.y, v.z-n.z);
}

template <typename T>
inline T
operator*(const Vector<T> v, const Normal<T> n)
{
    return v.x*n.x + v.y*n.y + v.z*n.z;
}

template <typename T>
Normal<T>
operator*(const Matrix<T>& in, const Normal<T>& n)
{
    return (Normal<T>(in.m[0][0] * n.x + in.m[1][0] * n.y + in.m[2][0] * n.z, in.m[0][1] * n.x + in.m[1][1] * n.y + in.m[2][1] * n.z, in.m[0][2] * n.x + in.m[1][2] * n.y + in.m[2][2] * n.z));
}

#endif
