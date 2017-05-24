#ifndef _MULTIPLEOBJECTS_H_
#define _MULTIPLEOBJECTS_H_

#include <tracer.h>
#include <world.h>
#include <color.h>

template <typename T>
class MultipleObjects : public Tracer<T>{

    public:
        
        MultipleObjects(void);
        MultipleObjects(World<T>*);
        
        virtual Color<T> traceRay(const Ray<T>&) const;
};

template <typename T>
MultipleObjects<T>::MultipleObjects(void) :
    Tracer<T>() {}

template <typename T>
MultipleObjects<T>::MultipleObjects(World<T>* in) :
    Tracer<T>(in) {}

template <typename T>
Color<T>
MultipleObjects<T>::traceRay(const Ray<T>& in) const
{
    ShadeRec<T> sr(this->world->hitObject(in));

    if(sr.hitobject){
        return sr.color;
    }
    else{
        return this->world->background;
    }
}

#endif
