#ifndef _RAY_H_
#define _RAY_H_

#include <iostream>

#include "point.h"
#include "vector.h"

using std::ostream;

template <typename T>
struct Ray{
    
    Point<T>  origin;
    Vector<T> direction;
    
    Ray(void) : origin(0), direction(0,0,1) {}
    Ray(const Point<T>& origin, const Vector<T>& direction) : origin(origin), direction(direction) {}
    Ray(const Ray<T>& ray) : origin(ray.origin), direction(ray.direction) {}
    
    Ray& operator=(const Ray<T>&);

    friend ostream &operator<<(ostream& os, const Ray<T>& in)
    {
        os << "Ray: (" << in.origin << "," << in.direction << ")";
        return os;
    }
};
typedef Ray<float>  Rayf;
typedef Ray<double> Rayd;

template <typename T>
Ray<T>&
Ray<T>::operator=(const Ray<T>& rhs)
{
    if(this == &rhs)
        return (*this);
    
    origin    = rhs.origin;
    direction = rhs.direction;

    return (*this);
}

#endif
