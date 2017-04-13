#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <math.h>
#include <cmath>
#include <iostream>

#include "normal.h"

using std::ostream;
using std::abs;

template <typename T>
class Point;

template <typename T>
struct Vector{
    
    T x, y, z; 

    Vector(void) : x(0), y(0), z(0) {}
    Vector(T a) : x(a), y(a), z(a) {}  
    Vector(T x, T y, T z) : x(x), y(y), z(z) {} 
    Vector(const Vector<T>&);
    Vector(const Normal<T>&);
    Vector(const Point<T>&);

           Vector<T>& operator=(const Vector<T>&);
           Vector<T>& operator=(const Normal<T>&);
           Vector<T>& operator=(const Point<T>&);
    inline Vector<T>& operator+=(const Vector<T>&);
    inline Vector<T>& operator+=(const T);
    inline Vector<T>& operator-=(const Vector<T>&);
    inline Vector<T>& operator-=(const T);
    inline Vector<T>& operator*=(const Vector<T>&);
    inline Vector<T>& operator*=(const T);
    inline Vector<T>& operator/=(const Vector<T>&);
    inline Vector<T>& operator/=(const T);
    inline Vector<T>  operator+(const T) const;
    inline Vector<T>  operator+(void) const;
    inline Vector<T>  operator-(const T) const;
    inline Vector<T>  operator-(void) const;
    inline Vector<T>  operator*(const T) const;
    inline Vector<T>  operator/(const T) const;
    inline Vector<T>  operator^(const Vector<T>&) const;
    inline bool       operator==(const Vector<T>&) const;
    inline T&         operator[](uint8_t);
           T          operator+(const Vector<T>&) const;
           T          operator-(const Vector<T>&) const;
           T          operator*(const Vector<T>&) const;
           T          operator/(const Vector<T>&) const;

           Vector<T>& hat(void);
    inline T          len_squared(void);
           T          length(void);
           void       normalize(void);

    friend ostream &operator<<(ostream& os, const Vector<T> in)
    {
        os << "Vector: (" << in.x << "," << in.y << "," << in.z << ")";
        
        return os;
    }
};
typedef Vector<float>  Vecf;
typedef Vector<double> Vecd;

template <typename T>
Vector<T>::Vector(const Vector<T>& v) : x(v.x), y(v.y), z(v.z)
{}

template <typename T>
Vector<T>::Vector(const Normal<T>& n) : x(n.x), y(n.y), z(n.z)
{}

template <typename T>
Vector<T>::Vector(const Point<T>& p) : x(p.x), y(p.y), z(p.z)
{}

template <typename T>
Vector<T>&
Vector<T>::operator=(const Vector<T>& rhs)
{
    if(this == &rhs)
        return(*this);
        
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    
    return(*this);
}

template <typename T>
Vector<T>&
Vector<T>::operator=(const Normal<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return(*this);
}

template <typename T>
Vector<T>&
Vector<T>::operator=(const Point<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    
    return(*this);
}

template <typename T>
inline Vector<T>&
Vector<T>::operator+=(const Vector<T>& v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return(*this);
}

template <typename T>
inline Vector<T>&
Vector<T>::operator+=(const T a)
{
    x += a;
    y += y;
    z += z;

    return(*this);
}

template <typename T>
inline Vector<T>&
Vector<T>::operator-=(const Vector<T>& v)
{
    x -= v.x;
    y -= v.y;
    z -= z.y;
    
    return(*this);
}

template <typename T>
inline Vector<T>&
Vector<T>::operator-=(const T a)
{
    x -= a;
    y -= a;
    z -= a;

    return(*this);
} 

template <typename T>
inline Vector<T>&
Vector<T>::operator*=(const Vector<T>& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return(*this);
}

template <typename T>
inline Vector<T>&
Vector<T>::operator*=(const T a)
{
    x *= a;
    y *= a;
    z *= a;

    return(*this);
}

template <typename T>
inline Vector<T>&
Vector<T>::operator/=(const Vector<T>& v) 
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return(*this);
}  

template <typename T>
inline Vector<T>&
Vector<T>::operator/=(const T a)
{
    x /= a;
    y /= a;
    z /= a;
    
    return(*this);
}


template <typename T>
inline Vector<T>
Vector<T>::operator+(const T a) const
{
    return Vector(x+a,y+a,z+a);
}

template <typename T>
inline Vector<T>
Vector<T>::operator+(void) const
{
    return Vector(abs(x),abs(y),abs(z));
}

template <typename T>
inline Vector<T>
Vector<T>::operator-(const T a) const
{
    return Vector(x-a,y-a,z-a);
}

template <typename T>
inline Vector<T>
Vector<T>::operator-(void) const
{
    return Vector(-x, -y, -z);
}

template <typename T>
inline Vector<T>
Vector<T>::operator*(const T a) const
{
    return Vector(x*a, y*a, z*a);
}

template <typename T>
Vector<T>
Vector<T>::operator/(const T a) const
{
    return Vector(x/a, y/a, z/a);
}

template <typename T>
inline Vector<T>
Vector<T>::operator^(const Vector<T>& v) const
{
   return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); 
}

template <typename T>
inline bool
Vector<T>::operator==(const Vector<T>& in) const
{
    return x == in.x && y == in.y && z == in.z;
}

template <typename T>
inline T&
Vector<T>::operator[](uint8_t i)
{
    return (&x)[i];
}

template <typename T>
T
Vector<T>::operator+(const Vector<T>& v) const
{
    return (x+v.x + y+v.y + z+v.z); 
}

template <typename T>
T
Vector<T>::operator-(const Vector<T>& v) const
{
    return (x-v.x + y-v.y + z-v.z);
}

template <typename T>
T
Vector<T>::operator*(const Vector<T>& v) const
{
    return (x*v.x + y*v.y + z*v.z);
}

template <typename T>
T
Vector<T>::operator/(const Vector<T>& v) const
{
    return (x/v.x + y/v.y + z/v.z);
}

template <typename T>
Vector<T>& 
Vector<T>::hat(void)
{
    T length = sqrt(x*x + y*y + z*z);  
    x /= length;
    y /= length;
    z /= length;

    return(*this); 
}

template <typename T>
inline T
Vector<T>::len_squared(void)
{
    return (x*x + y*y + z*z);
} 

template <typename T>
T
Vector<T>::length(void)
{
    return sqrt(x*x + y*y + z*z);
}

template <typename T>
void
Vector<T>::normalize(void)
{
    T length = sqrt(x*x + y*y + z*z);
    x /= length;
    y /= length;
    z /= length;
}

template <typename T>
inline Vector<T>
operator*(const T a, const Vector<T>&v)
{
    return Vector<T>(a*v.x, a*v.y, a*v.z);
}

template <typename T>
Vector<T>
operator*(const Matrix<T> m, const Vector<T>& v)
{
    return (Point3D(m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z,m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z,m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z));
}

#endif
