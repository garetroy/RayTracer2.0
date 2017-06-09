#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <color.h>
#include <shaderec.h>
#include <constants.h>
#include <ray.h>
#include <vector.h>
#include <world.h>

template <typename T>
class Material{
    
    public:
        Material(void);
        Material(Material<T>&);
        ~Material(void);

        virtual Material<T>* clone(void) const = 0;
                Material<T>& operator=(const Material<T>&);
        virtual Color<T> shade(ShadeRec<T>&);
};

template <typename T>
Material<T>::Material(void)
{}

template <typename T>
Material<T>::Material(Material<T>& in)
{}

template <typename T>
Material<T>::~Material(void)
{}

template <typename T>
Material<T>&
Material<T>::operator=(const Material<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    return *this;
}

template <typename T>
Color<T>
Material<T>::shade(ShadeRec<T>& in)
{
    return black;
}
#endif
