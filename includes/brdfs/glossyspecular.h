#ifndef _GLOSSY_H_
#define _GLOSSY_H_

#include <brdf.h>
#include <multijittered.h>

template <typename T>
class GlossySpecular: public BRDF<T>{

    public:
        GlossySpecular(void);
        GlossySpecular(const GlossySpecular<T>&);
        ~GlossySpecular(void);
        
        virtual GlossySpecular<T>* clone(void) const;
        virtual Color<T>       f(const ShadeRec<T>&, const Vector<T>&, const Vector<T>&) const;
        virtual Color<T>       samplef(const ShadeRec<T>&, const Vector<T>&, Vector<T>& wi, T&) const;
        virtual Color<T>       rho(const ShadeRec<T>&, const Vector<T>&) const;
        
        //setters
        void setks(const T);
        void setcs(const Color<T>&);
        void setcs(const T, const T, const T);
        void setcs(const T);
        void setexp(const T);
        void setSampler(Sampler<T>*, const T);
        void setSamples(const int, const T);
        void setNormal(const Normal<T>&);

    private:
        T           ks;
        Color<T>    cs;
        T           exp;
        Sampler<T>* sampler;
};

template <typename T>
GlossySpecular<T>::GlossySpecular(void) :
    BRDF<T>(),
    ks(0.0),
    cs(1.0),
    sampler(nullptr) {}

template <typename T>
GlossySpecular<T>::GlossySpecular(const GlossySpecular<T>& in) :
    BRDF<T>(in),
    ks(in.ks),
    cs(in.cs),
    sampler(in.sampler) {}

template <typename T>
GlossySpecular<T>::~GlossySpecular(void)
{}

template <typename T>
GlossySpecular<T>*
GlossySpecular<T>::clone(void) const 
{
    return new GlossySpecular(*this);
}

template <typename T>
Color<T>
GlossySpecular<T>::f(const ShadeRec<T>& sr, const Vector<T>& wo, const Vector<T>& wi) const
{
    Color<T>  l;
    T         ndotwi = sr.normal * wi;
    Vector<T> r(-wi + 2.0 * sr.normal * ndotwi);
    T         rdotwo = r * wo;
    
    if(rdotwo > 0.0)
        l = ks * cs * pow(rdotwo, exp);

    return l;
}

template <typename T>
Color<T>
GlossySpecular<T>::samplef(const ShadeRec<T>& sr, const Vector<T>& wo, Vector<T>& wi, T& p) const
{
    T         ndotwo = sr.normal * wo;
    Vector<T> r      = -wo + 2.0 * sr.normal * ndotwo;
    Vector<T> w      = r;
    Vector<T> u      = Vector<T>(0.00424,1,0.00764) ^ w;

    u.normalize();

    Vector<T> v      = u ^ w;
    Point<T>  sp     = sampler->sampleHemisphere();
    
    w = sp.x * u + sp.y * v + sp.z * w;    
    
    if(sr.normal * wi < 0.0)
        wi = -sp.x * u - sp.y * v + sp.z * w;

    T phong_lobe = pow(r * wi, exp);
      p          = phong_lobe * (sr.normal * wi);

    return ks * cs * phong_lobe;
}

template <typename T>
Color<T>
GlossySpecular<T>::rho(const ShadeRec<T>& sr, const Vector<T>& wo) const
{
    return black;
}

template <typename T>
inline void
GlossySpecular<T>::setks(const T k)
{
    ks = k;
}

template <typename T>
inline void
GlossySpecular<T>::setcs(const Color<T>& c)
{
    cs = c;
}

template <typename T>
inline void
GlossySpecular<T>::setcs(const T r, const T g, const T b)
{
    cs.r = r;
    cs.g = g;
    cs.b = b;
}

template <typename T>
inline void
GlossySpecular<T>::setcs(const T c)
{
    cs.r = c;
    cs.g = c;
    cs.b = c;
}

template <typename T>
inline void
GlossySpecular<T>::setexp(const T c)
{
    exp = c;
} 

template <typename T>
inline void
GlossySpecular<T>::setSampler(Sampler<T>* in, const T inexp)
{
    sampler = in;
    sampler->mapSamplestoHemisphere(inexp);
}

template <typename T>
inline void
GlossySpecular<T>::setSamples(const int in, const T inexp)
{
    sampler = new MultiJittered<T>(in);
    sampler->mapSamplestoHemisphere(inexp);
}

#endif
