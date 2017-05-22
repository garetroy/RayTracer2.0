#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <math.h>
#include <iostream>

#include "object.h"
#include "vector.h"

using std::ostream;

template <typename T>
class Sphere: public Object<T>{

    public:
        Sphere(void);
        Sphere(Point<T>& c, T r);
        Sphere(const Sphere<T>& rhs);
        
        virtual Sphere<T>* clone(void) const;
                Sphere<T>& operator=(const Sphere<T>& sphere);
        virtual bool hit(const Ray<T>& ray, T& t, ShadeRec<T>& s) const;

        //Getter Setters
        void setCenter(const Point<T>& c);
        void setCenter(const T x, const T y, const T z); 
        void setRadius(const T r);
        
        friend ostream &operator<<(ostream& os, const Sphere<T>& in)
        {
            os << "Sphere: " << std::endl << " " << in.center << std::endl;
            os << " Radius: " << in.radius;
        
            return os;
        }
    private:
        Point<T> center;
        T        radius;
    
        static const T kEpsilon;
};
typedef Sphere<float>  Spheref;
typedef Sphere<double> Sphered;

template <typename T>
const T Sphere<T>::kEpsilon = 0.001;

template <typename T>
Sphere<T>::Sphere(void) :
    center(Point<T>(0.0)),
    radius(1.0) {}

template <typename T>
Sphere<T>::Sphere(Point<T>& c, T r)
{
    center.x = c.x;
    center.y = c.y;
    center.z = c.z;
    
    radius = r;
}

template <typename T>
Sphere<T>::Sphere(const Sphere<T>& rhs)
{
    center.x = rhs.center.x;
    center.y = rhs.center.y;
    center.z = rhs.center.z;

    radius = rhs.radius;
}

template <typename T>
Sphere<T>*
Sphere<T>::clone(void) const
{
    return new Sphere(*this); 
}

template <typename T>
Sphere<T>&
Sphere<T>::operator=(const Sphere<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    Object<T>::operator=(rhs);
    
    center = rhs.center;
    radius = rhs.radius;
    
    return *this;
}

template <typename T>
bool
Sphere<T>::hit(const Ray<T>& ray, T& tmin, ShadeRec<T>& sr) const 
{
        double          t;
        Vector<T>       temp    = ray.origin - center;
        double          a       = ray.direction * ray.direction;
        double          b       = 2.0 * temp * ray.direction;
        double          c       = temp * temp - radius * radius;
        double          disc    = b * b - 4.0 * a * c;
	
        if (disc < 0.0)
	        return false;
        else {	
	        double e = sqrt(disc);
	        double denom = 2.0 * a;
	        t = (-b - e) / denom;    

	        if (t > kEpsilon) {
		        tmin               = t;
                        sr.normal          = t*ray.direction;
		        sr.normal          = (temp + sr.normal) / radius;
		        sr.localhitpoint = ray.origin + t * ray.direction;
		        return true;
	        } 	

	        t = (-b + e) / denom;    

	        if (t > kEpsilon) {
		        tmin               = t;
                        sr.normal          = t*ray.direction;
		        sr.normal          = (temp + sr.normal) / radius;
		        sr.localhitpoint = ray.origin + t * ray.direction;
		        return true;
	        } 
        }

        return false;        
}

template <typename T>
inline void
Sphere<T>::setCenter(const Point<T>& c)
{
    center.x = c.x;
    center.y = c.y;
    center.z = c.z;
}

template <typename T>
inline void
Sphere<T>::setCenter(const T x, const T y, const T z)
{
    center.x = x;
    center.y = y;
    center.z = z;
}

template <typename T>
inline void
Sphere<T>::setRadius(const T r)
{
    radius = r;
}

#endif
