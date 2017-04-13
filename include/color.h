#ifndef __RGB_COLOR__
#define __RGB_COLOR__

#include <iostream>
#include <cmath>

using std::ostream;
using std::abs;

template <typename T>
struct Color{
   
    T r,g,b;
    
    Color(void)          : r(0), g(0), b(0) {} 
    Color(T c)           : r(c), g(c), b(c) {}
    Color(T r, T g, T b) : r(r), g(g), b(b) {}

           Color<T>& operator=(const Color<T>&);
    inline Color<T>& operator+=(const Color<T>&);
    inline Color<T>& operator+=(const T);
    inline Color<T>& operator-=(const Color<T>&);
    inline Color<T>& operator-=(const T);
    inline Color<T>& operator*=(const Color<T>&);
    inline Color<T>& operator*=(const T);
    inline Color<T>& operator/=(const Color<T>&);
    inline Color<T>& operator/=(const T);
    inline Color<T>  operator+(const Color<T>&) const;
    inline Color<T>  operator+(const T) const;
    inline Color<T>  operator+(void) const;
    inline Color<T>  operator-(const Color<T>&) const;
    inline Color<T>  operator-(const T) const;
    inline Color<T>  operator-(void) const;
    inline Color<T>  operator*(const Color<T>&) const;
    inline Color<T>  operator*(const T) const;
    inline Color<T>  operator/(const Color<T>&) const;
    inline Color<T>  operator/(const T) const;
    inline bool      operator==(const Color<T>&) const;
    inline T&        operator[](uint8_t);

    inline T         average(void) const;
           Color<T>  powc(T) const;

    friend ostream &operator<<(ostream &os, const Color& in)
    {
        os << "Color: (" << in.r << "," << in.g << "," << in.b << ")";
        return os;
    } 
};
typedef Color<float>  Colorf;
typedef Color<double> Colord;

template <typename T>
Color<T>&
Color<T>::operator=(const Color<T>& rhs)
{
    if(this == &rhs)
        return (*this);
    
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;
    
    return (*this);  
}

template <typename T>
inline Color<T>&
Color<T>::operator+=(const Color<T>& in)
{       
    r += in.r;
    g += in.g;
    b += in.b;

    return (*this); 
}

template <typename T>
inline Color<T>&
Color<T>::operator+=(const T a)
{
    r += a;
    g += a;
    b += a;

    return (*this);
}

template <typename T>
inline Color<T>&
Color<T>::operator-=(const Color<T>& in)
{
    r -= in.r;
    g -= in.g;
    b -= in.b;
    
    return (*this);
}

template <typename T>
inline Color<T>&
Color<T>::operator-=(const T a)
{
    r -= a;
    g -= a;
    b -= a;

    return (*this);
}

template <typename T>
inline Color<T>&
Color<T>::operator*=(const Color<T>& in)
{
    r *= in.r;
    g *= in.g;
    b *= in.b;

    return (*this);
}

template <typename T>
inline Color<T>&
Color<T>::operator*=(const T a)
{
    r *= a;
    g *= a;
    b *= a;

    return (*this);
}

template <typename T>
inline Color<T>&
Color<T>::operator/=(const Color<T>& in)
{
    r /= in.r;
    g /= in.g;
    b /= in.b;

    return (*this);
}

template <typename T>
inline Color<T>&
Color<T>::operator/=(const T a)
{
    r /= a;
    g /= a;
    b /= a;

    return (*this);
}

template <typename T>
inline Color<T>
Color<T>::operator+(const Color<T>& in) const
{
    return Color<T>(r+in.r,g+in.g,b+in.b);
}

template <typename T>
inline Color<T>
Color<T>::operator+(const T in) const
{
    return Color<T>(r+in,g+in,b+in);
}

template <typename T>
inline Color<T>
Color<T>::operator+(void) const
{
    return Color<T>(abs(r),abs(g),abs(b));
}

template <typename T>
inline Color<T>
Color<T>::operator-(const Color<T>& in) const
{
    return Color<T>(r-in.r,g-in.g,b-in.b);
}

template <typename T>
inline Color<T>
Color<T>::operator-(const T in) const
{
    return Color<T>(r-in,g-in,b-in);
}

template <typename T>
inline Color<T>
Color<T>::operator-(void) const
{
    return Color<T>(-r,-g,-b);
}

template <typename T>
inline Color<T>
Color<T>::operator*(const Color<T>& in) const
{
    return Color<T>(r*in.r,g*in.g,b*in.b);
}

template <typename T>
inline Color<T>
Color<T>::operator*(const T in) const
{
    return Color<T>(r*in,g*in,b*in);
}

template <typename T>
inline Color<T>
Color<T>::operator/(const Color<T>& in) const
{
    return Color<T>(r/in.r,g/in.g,b/in.b);
}

template <typename T>
inline Color<T>
Color<T>::operator/(T in) const
{
    return Color<T>(r/in,g/in,b/in);
}

template <typename T>
inline bool
Color<T>::operator==(const Color<T>& in) const
{
    if(r == in.r && g == in.g && b == in.b)
        return true;

    return false;
}

template <typename T>
inline T&
Color<T>::operator[](uint8_t i)
{
   return (&r)[i];
} 

template <typename T>
inline T
Color<T>::average(void) const {
    return (1.0/3.0) * (r + g + b);
}

template <typename T>
Color<T>
Color<T>::powc(T p) const
{
    return Color<T>(pow(r,p),pow(g,p),pow(b,p));
}

template <typename T>
inline Color<T>
operator+(const T a, const Color<T>& c)
{
    return Color<T>(a+c.r,a+c.g,a+c.b);
}

template <typename T>
inline Color<T>
operator-(const T a, const Color<T>& c)
{
    return Color<T>(a-c.r,a-c.g,a-c.b);
}

template <typename T>
inline Color<T>
operator*(const T a, const Color<T>& c)
{
    return Color<T>(a*c.r,a*c.g,a*c.b);
}

template <typename T>
inline Color<T>
operator/(const T a, const Color<T>& c)
{
    return Color<T>(a/c.r,a/c.g,a/c.b);
}

#endif
