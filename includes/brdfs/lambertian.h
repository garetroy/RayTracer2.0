#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include <brdf.h>

template <typename T>
class Lambertian: public BRDF<T>{

    public:
        Lambertian(void);
        Lambertian(const Lambertian<T>&);
        virtual ~Lambertian(void);
        
                Lambertian<T>& operator=(const Lambertian<T>&); 
        virtual Lambertian<T>* clone(void) const;
        virtual Color<T>       f(const ShadeRec<T>&, const Vector<T>&, const Vector<T>&) const;
        virtual Color<T>       samplef(const ShadeRec<T>&, const Vector<T>&, Vector<T>& wi, T&) const;
        virtual Color<T>       rho(const ShadeRec<T>&, const Vector<T>&) const;
        
        //setters
        void setka(const T);
        void setkd(const T);
        void setcd(const Color<T>&);
        void setcd(const T, const T, const T);
        void setcd(const T);

    private:
        T        kd;
        Color<T> cd;
};

template <typename T>
Lambertian<T>::Lambertian(void) :
    BRDF<T>(),
    kd(0.0),
    cd(0.0) {}

template <typename T>
Lambertian<T>::Lambertian(const Lambertian<T>& in) :
    BRDF<T>(in),
    kd(in.kd),
    cd(in.cd) {}

template <typename T>
Lambertian<T>::~Lambertian(void)
{}

template <typename T>
Lambertian<T>&
Lambertian<T>::operator=(const Lambertian<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    BRDF<T>::operator=(rhs);

    kd = rhs.kd;
    cd = rhs.cd;
    
    return *this;
}

template <typename T>
Lambertian<T>*
Lambertian<T>::clone(void) const 
{
    return new Lambertian(*this);
}

template <typename T>
Color<T>
Lambertian<T>::f(const ShadeRec<T>& sr, const Vector<T>& wo, const Vector<T>& wi) const
{
    return kd*cd*INVPI;
}

template <typename T>
Color<T>
Lambertian<T>::samplef(const ShadeRec<T>& sr, const Vector<T>& wo, Vector<T>& wi, T& p) const
{
    Vector<T> w = sr.normal;
    Vector<T> v = Vector<T>(.0034, 1, 0.0071) ^ w;
    v.normalize();
    Vector<T> u = v ^ w;

    Point<T> sp = this->sampler->sampleHemisphere();
    wi = sp.x * u + sp.y * v + sp.z * w;
    wi.normalize();
    
    p = sr.normal * wi * INVPI;
    
    return kd * cd * INVPI;
}

template <typename T>
Color<T>
Lambertian<T>::rho(const ShadeRec<T>& sr, const Vector<T>& wo) const
{
    return kd*cd;
}

template <typename T>
inline void
Lambertian<T>::setka(const T k)
{
    kd = k;
}

template <typename T>
inline void
Lambertian<T>::setkd(const T k)
{
    kd = k;
}

template <typename T>
inline void
Lambertian<T>::setcd(const Color<T>& c)
{
    cd = c;
}

template <typename T>
inline void
Lambertian<T>::setcd(const T r, const T g, const T b)
{
    cd.r = r;
    cd.g = g;
    cd.b = b;
}

template <typename T>
inline void
Lambertian<T>::setcd(const T c)
{
    cd.r = c;
    cd.g = c;
    cd.b = c;
}
#endif
