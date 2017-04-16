#ifndef _BBOX_H_
#define _BBOX_H_

#include <iostream>

#include "ray.h"
#include "point.h"

using std::ostream;

template <typename T>
struct BoundingBox{
    
    T x1, x2, y1, y2, z1, z2;
    
    BoundingBox(void);
    BoundingBox(const T, const T, const T, const T, const T, const T); 
    BoundingBox(const Point<T>, const Point<T>);
    BoundingBox(const BoundingBox<T>&);

    BoundingBox<T>& operator=(const BoundingBox<T>&);
    bool            hit(const Ray<T>&) const;
    bool            inside(const Point<T>&) const;

    friend ostream &operator<<(ostream& os, const BoundingBox<T>& in)
    {
        os << "BoundingBox: (" << in.x1 << "," << in.y1 << "," << in.z1 << ") ";
        os << "(" << in.x2 << "," << in.y2 << "," << in.z2 << ")";
        return os;
    }
};
typedef BoundingBox<float>  BoundingBoxf;
typedef BoundingBox<double> BoundingBoxd;

template <typename T>
BoundingBox<T>::BoundingBox(void)
    :   x1(0), x2(0), y1(0), y2(0), z1(0), z2(0)
{}

template <typename T>
BoundingBox<T>::BoundingBox(const T x1, const T x2, const T y1, const T y2, const T z1, const T z2)
    :   x1(x1), x2(x2), y1(y1), y2(y2), z1(z1), z2(z2)
{}

template <typename T>
BoundingBox<T>::BoundingBox(const Point<T> p1, const Point<T> p2)
    :   x1(p1.x), x2(p2.x), y1(p1.y), y2(p2.y), z1(p1.z), z2(p2.z)
{}

template <typename T>
BoundingBox<T>::BoundingBox(const BoundingBox<T>& rhs)
    :   x1(rhs.x1), x2(rhs.x2), y1(rhs.y1), y2(rhs.y2), z1(rhs.z1), z2(rhs.z2)
{}

template <typename T>
BoundingBox<T>&
BoundingBox<T>::operator=(const BoundingBox<T>& rhs)
{
   if(this == &rhs)
        return (*this);
    
    x1 = rhs.x1;
    x2 = rhs.x2;
    y1 = rhs.y1;
    y2 = rhs.y2;
    z1 = rhs.z1;
    z2 = rhs.z2;

    return (*this);
}

template <typename T>
bool
BoundingBox<T>::hit(const Ray<T>& ray) const
{
    T xmin, ymin, zmin, xmax, ymax, zmax, t0, t1;

    T a = 1.0/ray.direction.x;
    if(a >= 0){
        xmin = (x1 - ray.origin.x) * a;
        xmax = (x2 - ray.origin.x) * a;
    } else {
        xmin = (x2 - ray.origin.x) * a;
        xmax = (x1 - ray.origin.x) * a;
    }

    T b = 1.0/ray.direction.y;
    if(b >= 0){
        ymin = (y1 - ray.origin.y) * b;
        ymax = (y2 - ray.origin.y) * b;
    } else {
        ymin = (y2 - ray.origin.y) * b;
        ymax = (y1 - ray.origin.y) * b;
    } 
    
    T c = 1.0/ray.direction.z;
    if(c >= 0){
        zmin = (z1 - ray.origin.z) * c;
        zmax = (z2 - ray.origin.z) * c;
    } else {
        zmin = (z2 - ray.origin.z) * c;
        zmax = (z1 - ray.origin.z) * c;
    } 

    if(xmin > ymin)
        t0 = xmin;
    else
        t0 = ymin; 

    if(zmin > t0)
        t0 = zmin;

    if(xmax < ymax)
        t1 = xmax;
    else
        t1 = ymax;

    if(zmax < t1)
        t1 = zmax;

    return (t0 < t1 && t1 > kepsilon);
}

template <typename T>
bool
BoundingBox<T>::inside(const Point<T>& in) const
{
    return (in.x > x1 && in.x < x2) && (in.y > y1 && in.y < y2) &&(in.z > z1 && in.z < z2);
}

#endif
