#ifndef _AMBIENT_H_
#define _AMBIENT_H_

#include <light.h>

template <typename T>
class Ambient : public Light<T>{

    public:
        Ambient(void);
        Ambient(const Ambient<T>&);
        ~Ambient(void);
        
        virtual Ambient<T>* clone(void) const;
                Ambient<T>& operator=(const Ambient<T>&);
        virtual Vector<T> getDirections(ShadeRec<T>&);
        virtual Color<T>  L(ShadeRec<T>&);

    protected:
        T        ls;
        Color<T> color;
};

template <typename T>
Ambient<T>::Ambient(void) :
    Light<T>(),
    ls(1.0),
    color(1.0) {} 


template <typename T>
Ambient<T>::Ambient(const Ambient<T>& in) :
    Light<T>(),
    ls(in.ls),
    color(in.color) {}

template <typename T>
Ambient<T>::~Ambient(void)
{}

template <typename T>
Ambient<T>*
Ambient<T>::clone(void) const
{
   return new Ambient<T>(*this);
}  

template <typename T>
Ambient<T>&
Ambient<T>::operator=(const Ambient<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    Light<T>::operator=(rhs);

    return *this;
}

template <typename T>
Vector<T>
Ambient<T>::getDirections(ShadeRec<T>& in)
{
    return Vector<T>(0.0);
}

template <typename T>
Color<T>
Ambient<T>::L(ShadeRec<T>& sr)
{
    return ls*color;
}
#endif
