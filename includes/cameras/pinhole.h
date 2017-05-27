#ifndef _PINHOLE_H_
#define _PINHOLE_H_

#include <vector.h>
#include <color.h>
#include <point.h>
#include <world.h>
#include <camera.h>
#include <math.h>
#include <regular.h>
#include <constants.h>
#include <viewplane.h>
#include <multipleobjects.h>

template <typename T>
class Pinhole: public Camera<T>{

    public:
        Pinhole(void);
        Pinhole(const Pinhole<T>&);
        
        virtual Camera<T>*  clone(void) const;
                Pinhole<T>& operator=(const Pinhole<T>&);
                Vector<T>   rayDirection(const Point<T>&) const;
        virtual void        renderScene(World<T>&);    
        
        //getters/setters
        
        void setViewDistance(const T);
        void setZoom(const T);
        
    private:
        T d;
        T zoom;
};

template <typename T>
Pinhole<T>::Pinhole(void) :
    Camera<T>(),
    d(500),
    zoom(1.0) {}

template <typename T>
Pinhole<T>::Pinhole(const Pinhole<T>& c) :
    Camera<T>(c),
    d(c.d),
    zoom(c.zoom) {}

template <typename T>
Camera<T>*
Pinhole<T>::clone(void) const
{
    return new Pinhole<T>(*this);
}

template <typename T>
Pinhole<T>&
Pinhole<T>::operator=(const Pinhole<T>& rhs)
{
    if(this == &rhs)
        return *this;

    Camera<T>::operator=(rhs);
    
    d    = rhs.d;
    zoom = rhs.zoom;
    
    return *this;
}

template <typename T>
Vector<T>
Pinhole<T>::rayDirection(const Point<T>& p) const
{
    Vector<T>dir = p.x * this->u + p.y * this->v - d * this->w;
    dir.normalize();
    
    return dir;
}

template <typename T>
void
Pinhole<T>::renderScene(World<T>& w)
{
    ViewPlane<T> vp(w.vp);
    Color<T>     color;
    Point<T>     pp;
    Ray<T>       ray;
    int          depth = 0;
    int          n     = (int)sqrt((T)vp.numsamples);

    zoom = .5;

    vp.pixelsize /= this->zoom;
    ray.origin    = this->eye;
    
    for(int i = 0; i < vp.w; i++)
        for(int j = 0; j < vp.w; j++){
            color = black;
            
            for(int p = 0; p < n; p++)
                for(int q = 0; q < n; q++){
                    pp.x = vp.pixelsize * ( j - 0.5 * vp.h + (q + 0.5) / n);
                    pp.y = vp.pixelsize * ( i - 0.5 * vp.w + (p + 0.5) / n);
    
                    ray.direction = rayDirection(pp);
                    color        += w.tracer->traceRay(ray);
                }

        color /= vp.numsamples;
        color *= this->exposuretime;
        vp.setPixel(i,j,color); 
    }
}
    
template <typename T>
inline void
Pinhole<T>::setViewDistance(const T in)
{
    d = in;
}

template <typename T>
inline void
Pinhole<T>::setZoom(const T in)
{
    zoom = in;
}
#endif
