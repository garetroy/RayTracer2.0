#ifndef _SINGLESPHERE_H_
#define _SINGLESPHERE_H_

#include <world.h>
#include <shaderec.h>
#include <tracer.h>

template <typename T>
struct SingleSphere : public Tracer<T>{
    
    World<T>* world;
    SingleSphere(void);
    SingleSphere(World<T>* world);

    virtual Color<T> traceRay(const Ray<T>& ray) const;
};

template <typename T>
SingleSphere<T>::SingleSphere(void) :
    Tracer<T>() {}

template <typename T>
SingleSphere<T>::SingleSphere(World<T>* world)
{
     this->world = world;
}

template <typename T>
Color<T>
SingleSphere<T>::traceRay(const Ray<T>& ray) const
{
    ShadeRec<T> sr(*world);
    T           t;

    if(world->sphere.hit(ray,t,sr)){
        return red;
    }else{
        return black;
    }
}

#endif
