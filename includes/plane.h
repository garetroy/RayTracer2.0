#ifndef _PLANE_H_
#define _PLANE_H_

#include <iostream>

#include "point.h"
#include "object.h"
#include "constants.h"

using std::ostream;

template <typename T>
class Plane : public Object<T>{
    
    public:
        Plane(void);
        Plane(const Point<T> p, const Normal<T>& n);
        Plane(const Plane<T>& plane);
        
                Plane<T>& operator=(const Plane<T>& rhs);
        virtual Plane<T>* clone(void) const;
        virtual bool      hit(const Ray<T>& ray, T& tmin,
                              ShadeRec<T>& sr) const;

        friend ostream &operator<<(ostream& os, const Plane<T>& in)
        {
            os << "Plane: " << std::endl << " " << in.p
                << std::endl << " " << in.n; 
            return os;
        }

    private:
        Point<T>  p;
        Normal<T> n;

        static const T kEpsilon;
};
typedef Plane<float>  Planef;
typedef Plane<double> Planed;

template <typename T>
const T Plane<T>::kEpsilon = 0.001;

template <typename T>
Plane<T>::Plane(void) :
    Object<T>(),
    p(0.0),
    n(0,1,0) {}

template <typename T>
Plane<T>::Plane(const Point<T> p, const Normal<T>& n) :
    Object<T>(),
    p(p),
    n(n)
{
    n.normalize();
}

template <typename T>
Plane<T>::Plane(const Plane& plane) :
    Object<T>(),
    p(plane.p),
    n(plane.n) {}

template <typename T>
Plane<T>&
Plane<T>::operator=(const Plane<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    Object<T>::operator= (rhs);
    p = rhs.p;
    n = rhs.n;
    
    return *this;
}

template <typename T>
Plane<T>*
Plane<T>::clone(void) const{
    return new Plane(*this);
}

template <typename T>
bool
Plane<T>::hit(const Ray<T>& ray, T& tmin, ShadeRec<T>& sr) const
{
	T t = (p - ray.origin) * n / (ray.direction * n); 
	if (t > kEpsilon) {
		tmin = t;
		sr.normal = n;
		sr.localhitpoint = ray.origin + t * ray.direction;
		return true;	
	}

	return false;
}

#endif
