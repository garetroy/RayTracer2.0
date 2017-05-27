#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <object.h>
#include <point.h>
#include <ray.h>
#include <normal.h>
#include <bbox.h>
#include <shaderec.h>
#include <functions.h>

template <typename T>
class Triangle: public Object<T>{

    public:
        Triangle(void);
        Triangle(const Point<T>&, const Point<T>&, const Point<T>&);
        Triangle(const Triangle<T>&);
        
        virtual Triangle<T>*   clone(void) const;
                Triangle<T>&   operator=(const Triangle<T>&);
        virtual BoundingBox<T> getBBox(void);
                void           computeNormal(void);
        virtual bool           hit(const Ray<T>&, T&, ShadeRec<T>&) const;

    private:
        Point<T>  v0, v1, v2;
        Normal<T> normal;
};

template <typename T>
Triangle<T>::Triangle(void) :
    Object<T>(),
    v0(0,0,0),
    v1(0,0,1),
    v2(1,0,0),
    normal(0,1,0) {}

template <typename T>
Triangle<T>::Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) :
    Object<T>(),
    v0(a),
    v1(b),
    v2(c)
{
    computeNormal();
}

template <typename T>
Triangle<T>::Triangle(const Triangle<T>& tri) :
    Object<T>(tri),
    v0(tri.v0),
    v1(tri.v1),
    v2(tri.v2),
    normal(tri.normal) {}

template <typename T>
Triangle<T>*
Triangle<T>::clone(void) const
{
    return new Triangle(*this);
}

template <typename T>
Triangle<T>&
Triangle<T>::operator=(const Triangle<T>& rhs)
{
    if(this == &rhs)
        return *this;

    Object<T>::operator=(rhs);
    
    v0     = rhs.v0;
    v1     = rhs.v1;
    v2     = rhs.v2;
    normal = rhs.normal;
    
    return *this;
}

template <typename T>
void
Triangle<T>::computeNormal(void)
{
    normal = (v1 - v0) ^ (v2 - v0);
    normal.normalize();
}

template <typename T>
BoundingBox<T>
Triangle<T>::getBBox(void)
{
    T delta = 0.00001;
    return BoundingBox<T>(minmin(v0.x,v1.x,v2.x)-delta, maxmax(v0.x,v1.x,v2.x)+delta,
                        minmin(v0.y,v1.y,v2.y)-delta, maxmax(v0.y,v1.y,v2.y)+delta, 
                        minmin(v0.z,v1.z,v2.z)-delta, maxmax(v0.z,v1.z,v2.z)+delta);
}

template <typename T>
bool
Triangle<T>::hit(const Ray<T>& ray, T& tmin, ShadeRec<T>& sr) const
{
    T a = v0.x - v1.x;
    T b = v0.x - v2.x;
    T c = ray.direction.x; 
    T d = v0.x - ray.origin.x; 
    T e = v0.y - v1.y;
    T f = v0.y - v2.y;
    T g = ray.direction.y;
    T h = v0.y - ray.origin.y;
    T i = v0.z - v1.z;
    T j = v0.z - v2.z;
    T k = ray.direction.z;
    T l = v0.z - ray.origin.z;

    T m = f * k - g * j;
    T n = h * k - g * l;
    T p = f * l - h * j;
    T q = g * i - e * k; 
    T s = e * j - f * i;

    T invdenom  = 1.0 / (a * m + b * q + c * s);

    T e1 = d * m - b * n - c * p;
    T beta = e1 * invdenom;

    if (beta < 0.0)
        return false;

    T r = r = e * l - h * i;
    T e2 = a * n + d * q + c * r;
    T gamma = e2 * invdenom;

    if (gamma < 0.0 )
        return false;

    if (beta + gamma > 1.0)
        return false;
        
    T e3 = a * p - b * r + d * s;
    T t = e3 * invdenom;

    if (t < kepsilon) 
        return false;
                
    tmin                = t;
    sr.normal           = normal;       
    sr.localhitpoint    = ray.origin + t * ray.direction;    

    return true;       
}
#endif
