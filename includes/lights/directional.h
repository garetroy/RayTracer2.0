#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_

#include <light.h>
#include <world.h>
#include <shaderec.h>

template <typename T>
class Directional : public Light<T>{

    public:
        Directional(void);
        Directional(const Directional<T>&);
        ~Directional(void);
        
        virtual Directional<T>* clone(void) const = 0;
                Directional<T>& operator=(const Directional<T>&);
        virtual Vector<T> getDirection(ShadeRec<T>&);
        virtual Color<T>  L(ShadeRec<T>&);
                void      scaleRadience(const T);
                void      setColor(const Color<T>&);
                void      setColor(const T);
                void      setColor(const T, const T, const T);
                void      setDirection(Vector<T>);
                void      setDirection(const T, const T, const T);

    private:
        T         ls;
        Color<T>  color;
        Vector<T> dir;
};

template <typename T>
Directional<T>::Directional(void) :
    Light<T>(),
    ls(1.0),
    color(1.0),
    dir(0,1,0) {} 


template <typename T>
Directional<T>::Directional(const Directional<T>& in) :
    Light<T>(),
    ls(in.ls),
    color(in.color),
    dir(in.dir) {}

template <typename T>
Directional<T>::~Directional(void)
{}

template <typename T>
Directional<T>*
Directional<T>::clone(void) const
{
   return new Directional<T>(*this);
}  

template <typename T>
Directional<T>&
Directional<T>::operator=(const Directional<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    Light<T>::operator=(rhs);

    return *this;
}

template <typename T>
Vector<T>
Directional<T>::getDirection(ShadeRec<T>& in)
{
    return dir;
}

template <typename T>
Color<T>
Directional<T>::L(ShadeRec<T>& sr)
{
    return ls*color;
}

template <typename T>
inline void
Directional<T>::scaleRadience(const T a)
{
    ls = a;
}

template <typename T>
inline void
Directional<T>::setColor(const Color<T>& c)
{   
    color = c;
} 
template <typename T>
inline void
Directional<T>::setColor(const T a)
{
    color.r = a;
    color.g = a;
    color.b = a;
}

template <typename T>
inline void
Directional<T>::setColor(const T r, const T g, const T b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

template <typename T>
inline void
Directional<T>::setDirection(Vector<T> in)
{
    dir = in;
    dir.normalize();
} 

template <typename T>
inline void
Directional<T>::setDirection(T dx, T dy, T dz)
{
    dir.x = dx;
    dir.y = dy;
    dir.z = dz;
    dir.normalize();
}

#endif
