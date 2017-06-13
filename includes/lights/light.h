#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <vector.h>
#include <color.h>
#include <ray.h>
#include <constants.h>

template <typename T>
class ShadeRec;

template <typename T>
class Light{
    
    public:
        Light(void);
        Light(const Light<T>&);
        ~Light(void); 

        virtual Light<T>* clone(void) const = 0;
                Light<T>& operator=(const Light<T>&);
        virtual Vector<T> getDirections(ShadeRec<T>&) = 0; 
        virtual Color<T>  L(ShadeRec<T>&);
        virtual bool      castsShade(void);
        virtual bool      inShadow(const Ray<T>&, const ShadeRec<T>&) const;
    
};

template <typename T>
Light<T>::Light(void)
{} 

template <typename T>
Light<T>::Light(const Light<T>& in)
{} 

template <typename T>
Light<T>::~Light(void)
{}

template <typename T>
Light<T>&
Light<T>::operator=(const Light<T>& rhs){
    if(this == &rhs)
        return *this;
    
    return *this;
}

template <typename T>
Color<T>
Light<T>::L(ShadeRec<T> &in)
{
    return black;
}

template <typename T>
bool
Light<T>::castsShade(void)
{
    return false;
}

template <typename T>
bool
Light<T>::inShadow(const Ray<T>& in, const ShadeRec<T>& sr) const
{
    return false;
}
#endif
