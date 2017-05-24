#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>

#include <ray.h>
#include <bbox.h>
#include <color.h>
#include <shaderec.h>
#include <constants.h>

using std::ostream;

template <typename T>
class Object{

    public:
        Object(void);
        Object(const Object<T>& object);
        virtual Object<T>* clone(void) const = 0;
        virtual bool hit(const Ray<T>& ray, T& tmin,
                         ShadeRec<T>& rc) const = 0;
        
        virtual Point<T> sample(void);
        virtual void     addObject(Object<T>* obj);
        virtual T        pdf(ShadeRec<T>& sr);
        

        //Setters/Getters
        void     setColor(const Color<T>& c);
        void     setColor(const T r, const T g, const T b);
        Color<T> getColor(void);

        virtual void           setBbox(void);
        virtual BoundingBox<T> getBbox(void);
         
    protected:
       Color<T>   color;
       Object<T>& operator=(const Object<T>& rhs);
    
    friend ostream &operator<<(ostream& os, const Object<T>& in)
    {
        os << "Object: " << std::endl << " " << in.color;
        return os;
    }
};
typedef Object<float>  Objectf;
typedef Object<double> Objectd;

template <typename T>
Object<T>::Object(void) :
    color(red) {}

template <typename T>
Object<T>::Object(const Object<T>& object) :
    color(object.color) {}

template <typename T>
Point<T>
Object<T>::sample(void)
{
    return Point<T>(0.0);
}

template <typename T>
void
Object<T>::addObject(Object<T>* obj)
{}

template <typename T>
T
Object<T>::pdf(ShadeRec<T>& sr)
{
    //Returns probability density
    return 0.0;
}

template <typename T>
inline void
Object<T>::setColor(const Color<T>& c)
{
    color = c;
}

template <typename T>
inline void
Object<T>::setColor(const T r, const T g, const T b)
{
    color.r = r;
    color.b = b;
    color.g = g;
}

template <typename T> 
inline Color<T>
Object<T>::getColor(void)
{
    return color;
}

template <typename T>
void
Object<T>::setBbox(void)
{}

template <typename T>
BoundingBox<T>
Object<T>::getBbox(void)
{
    return BoundingBox<T>();
}

template <typename T>
Object<T>&
Object<T>::operator= (const Object<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    color = rhs.color;
    
    return *this;
}


#endif
