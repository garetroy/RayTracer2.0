#ifndef _PHONG_H_
#define _PHONG_H_

#include <lambertian.h>
#include <glossyspecular.h>

template <typename T>
class Phong : public Material<T>{
    
    public:
        Phong(void);
        Phong(const Phong<T>&);
        ~Phong(void);

        virtual Phong<T>* clone(void) const;
                Phong<T>& operator=(const Phong<T>&);
        virtual Color<T> shade(ShadeRec<T>&);
        
        //getters and setters
        void setka(const T);
        void setkd(const T);
        void setcd(const Color<T>);
        void setcd(const T, const T, const T);
        void setcd(const T);

    protected:
        Lambertian<T>*     ambient;
        Lambertian<T>*     diffuse;
        GlossySpecular<T>* specular;
};

template <typename T>
Phong<T>::Phong(void) :
    Material<T>(),
    ambient(new Lambertian<T>),
    diffuse(new Lambertian<T>),
    specular(new GlossySpecular<T>) {}

template <typename T>
Phong<T>::Phong(const Phong<T>& in)
{
}

template <typename T>
Phong<T>::~Phong(void)
{}

template <typename T>
Phong<T>*
Phong<T>::clone(void) const
{
    return new Phong<T>(*this);
}

template <typename T>
Phong<T>&
Phong<T>::operator=(const Phong<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    return *this;
}

template <typename T>
Color<T>
Phong<T>::shade(ShadeRec<T>& in)
{
    Vector<T> wo = -in.ray.direction;
    Color<T>  L  = ambient->rho(in,wo) * in.w.ambient->L(in);
    int       nl = in.w.lights.size();

    for(int i = 0; i < nl; i++){
        Vector<T> wi = in.w.lights[i]->getDirections(in);
        T         nw = in.normal * wi;
        if(nw > 0.0)
            L += (diffuse->f(in,wo,wi) + specular->f(in,wo,wi)) *
                  in.w.lights[i]->L(in) * nw; 
    }
    
    return L;
}

template <typename T>
inline void
Phong<T>::setka(const T ka)
{
    ambient->setkd(ka);
}

template <typename T>
inline void
Phong<T>::setkd(const T c)
{
    diffuse->setcd(c);
}

template <typename T>
inline void
Phong<T>::setcd(const Color<T> c)
{
    ambient->setcd(c);
    diffuse->setcd(c);
}

template <typename T>
inline void
Phong<T>::setcd(const T r, const T g, const T b)
{
    ambient->setcd(r,g,b);
    diffuse->setcd(r,g,b);
}

template <typename T>
inline void
Phong<T>::setcd(const T c)
{
    ambient->setcd(c);
    diffuse->setcd(c);
}
#endif
