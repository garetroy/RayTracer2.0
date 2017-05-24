#ifndef _POINT_H_
#define _POINT_H_

#include <math.h>
#include <cstdint>
#include <iostream>

using std::ostream;

template <typename T>
struct Vector;

template <typename T>
struct Matrix;

template <typename T>
struct Point{

    T x, y , z;

    Point(void) : x(0), y(0), z(0) {}
    Point(const T a) : x(a), y(a), z(a) {} 
    Point(const T x, const T y, const T z) : x(x), y(y), z(z) {}
    Point(const Point<T>&);

    Point<T>& operator=(const Point<T>);

    inline Point<T>  operator*(const T) const;
    inline Point<T>  operator+(const Vector<T>&) const;
    inline Point<T>  operator-(void) const;
    inline Point<T>  operator-(const Vector<T>&) const;
    inline Vector<T> operator-(const Point<T>&) const;
    inline T&        operator[](uint8_t i);
           T    d_squared(const Point<T>&) const;
           T    distance(const Point<T>&) const;

    friend ostream &operator<<(ostream& os, const Point<T>& in)
    {
        os << "Point: (" << in.x << "," << in.y << "," << in.z << ")";
        return os;
    }
};
typedef Point<float>  Pointf;
typedef Point<double> Pointd;

template <typename T>
Point<T>::Point(const Point<T>& p) : x(p.x), y(p.y), z(p.z)
{} 

template <typename T>
Point<T>&
Point<T>::operator=(const Point<T> rhs)
{
    if(this == &rhs)
        return (*this);

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    
    return (*this);
}

template <typename T>
inline Point<T>
Point<T>::operator*(const T a) const
{
   return Point<T>(x*a, y*a, z*a); 
}

template <typename T>
inline Point<T>
Point<T>::operator+(const Vector<T>& in) const
{
    return Point<T>(x+in.x, y+in.y, z+in.z);
}

template <typename T>
inline Point<T>
Point<T>::operator-(void) const
{
    return Point<T>(-x,-y,-z);
}

template <typename T>
inline Point<T>
Point<T>::operator-(const Vector<T>& in) const
{
    return Point<T>(x-in.x, y-in.y, z-in.z);
}

template <typename T>
inline Vector<T>
Point<T>::operator-(const Point<T>& in) const
{
    return Vector<T>(x-in.x, y-in.y, z-in.z);
}

template <typename T>
inline T&
Point<T>::operator[](uint8_t i)
{
    if(i < 0 || i > 2)
        return(&x)[i];

    return (&x)[i];
}

template <typename T>
T
Point<T>::d_squared(const Point<T>& in) const
{
    return (x-in.x) * (x-in.x) + (y-in.y) * (y-in.y) + (z-in.z) * (z-in.z);
}

template <typename T>
 T
Point<T>::distance(const Point<T>& in) const
{
    return sqrt(((x-in.x) * (x-in.x) + (y-in.y) * (y-in.y) + (z-in.z) * (z-in.z)));
}

template <typename T>
inline Point<T>
operator*(T a, const Point<T>& in)
{
    return Point<T>(a*in.x,a*in.y,a*in.z);
}

template <typename T>
Point<T>
operator* (const Matrix<T>& in, const Point<T>& p)
{
	return (Point<T>(in.m[0][0] * p.x + in.m[0][1] * p.y + in.m[0][2] * p.z + in.m[0][3],in.m[1][0] * p.x + in.m[1][1] * p.y + in.m[1][2] * p.z + in.m[1][3],in.m[2][0] * p.x + in.m[2][1] * p.y + in.m[2][2] * p.z + in.m[2][3]));
}

#endif
