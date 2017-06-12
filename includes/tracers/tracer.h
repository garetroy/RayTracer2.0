#ifndef _TRACER_H_
#define _TRACER_H_

#include <constants.h>
#include <ray.h>
#include <color.h>

template <typename T>
class World;

template <typename T>
class Tracer{
    
    public:
        Tracer(void);
        Tracer(World<T>* world);
        virtual ~Tracer(void);
    
        virtual Color<T> traceRay(const Ray<T>&) const;
        virtual Color<T> traceRay(const Ray<T>,
                                const int) const;
        virtual Color<T> traceRay(const Ray<T>, T&,const int) const;

    protected:
        World<T>* world;
};
typedef Tracer<float>  Tracerf;
typedef Tracer<double> Tracerd;

template <typename T>
Tracer<T>::Tracer(void) :
    world(nullptr) {}

template <typename T>
Tracer<T>::Tracer(World<T>* world) :
    world(world) {}

template <typename T>
Tracer<T>::~Tracer(void)
{
    if(world != nullptr)
        world = nullptr;
}
template <typename T>
Color<T>
Tracer<T>::traceRay(const Ray<T>& ray) const
{
    return black;
}

template <typename T>
Color<T>
Tracer<T>::traceRay(const Ray<T> ray, const int depth) const 
{
    return black;
}

template <typename T>
Color<T>
Tracer<T>::traceRay(const Ray<T> ray,T& tmin, const int depth) const 
{
    return black;
}
        
#endif

