#ifndef _BDRF_H_
#define _BDRF_H_

#include <constants.h>
#include <color.h>
#include <vector.h>
#include <shaderec.h>
#include <sampler.h>

template <typename T>
class BRDF{

    public:
        BRDF(void);
        BRDF(const BRDF<T>&);
        ~BRDF(void);
    
        virtual BRDF<T>* clone(void) const = 0;
                BRDF<T>& operator=(const BRDF<T>&);
                void     setSampler(Sampler<T>*);
        virtual Color<T> f(const ShadeRec<T>&, const Vector<T>&, const Vector<T>&) const;
        virtual Color<T> samplef(const ShadeRec<T>&, const Vector<T>&, Vector<T>&) const;
        virtual Color<T> samplef(const ShadeRec<T>&, const Vector<T>&, Vector<T>&, T&) const;
        virtual Color<T> rho(const ShadeRec<T>&, const Vector<T>&) const;
    
    protected:
        Sampler<T>* sampler;
};

template <typename T>
BRDF<T>::BRDF(void) :
    sampler(nullptr) {}

template <typename T>
BRDF<T>::BRDF(const BRDF<T>& b)
{
    if(b.sampler != nullptr)
        sampler = b.sampler->clone();
    else
        sampler = nullptr;
}

template <typename T>
BRDF<T>::~BRDF(void)
{
    if(sampler != nullptr){
        delete sampler;
        sampler = nullptr;
    }
}

template <typename T>
BRDF<T>&
BRDF<T>::operator=(const BRDF<T>& rhs)
{
    if(this == &rhs)
        return *this;

    if(rhs.sampler != nullptr)
        sampler = rhs.sampler->clone();
    
    return *this;
}

template <typename T>
void
BRDF<T>::setSampler(Sampler<T>* s)
{
    sampler = s;
    sampler->mapSamplesToHemisphere(1);
}

template <typename T>
Color<T>
BRDF<T>::f(const ShadeRec<T>& sr, const Vector<T>& wo, const Vector<T>& wi) const
{
    return black;
}

template <typename T>
Color<T>
BRDF<T>::samplef(const ShadeRec<T>& sr, const Vector<T>& wo, Vector<T>& wi) const
{
    return black;
}

template <typename T>
Color<T>
BRDF<T>::samplef(const ShadeRec<T>& sr, const Vector<T>& wo, Vector<T>& wi, T& p) const
{
    return black;
}

template <typename T>
Color<T>
BRDF<T>::rho(const ShadeRec<T>& sr, const Vector<T>& wo) const
{
    return black;
}
#endif
