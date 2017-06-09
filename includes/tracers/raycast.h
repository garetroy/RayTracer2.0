#ifndef _RAYCAST_H_
#define _RAYCAST_H_

#include <tracer.h>
#include <world.h>
#include <color.h>

template <typename T>
class RayCast : public Tracer<T>{

    public:
        RayCast(World<T>*);
        virtual Color<T> traceRay(const Ray<T>&, const int depth) const;

    private:
        RayCast(void);
};

template <typename T>
RayCast<T>::RayCast(void) :
    Tracer<T>() {}

template <typename T>
RayCast<T>::RayCast(World<T>* in) :
    Tracer<T>(in) {}

template <typename T>
Color<T>
RayCast<T>::traceRay(const Ray<T>& in, const int depth) const
{
    ShadeRec<T> sr(this->world->hitObject(in));

    if(sr.hitobject){
        sr.ray = in;
        return sr.material->shade(sr);
    }

    return this->world->background;
}

#endif
