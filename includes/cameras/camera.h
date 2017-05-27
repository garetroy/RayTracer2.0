#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <point.h>
#include <vector.h>

template <typename T>
class World;

template <typename T>
class Camera{

    public:
        Camera();
        Camera(const Camera<T>&);
        

        virtual Camera<T>* clone(void) const = 0;
                Camera<T>& operator=(const Camera<T>&);
        virtual void       renderScene(World<T>&) = 0;
                void       computeUVW(void);

        //Setters
                void setEye(const Point<T>&);
                void setEye(const T, const T, const T);
                void setLookat(const Point<T>&);
                void setLookat(const T, const T, const T);
                void setUp(const Point<T>&);
                void setUp(const T, const T, const T);

    protected:
        Point<T>  eye;
        Point<T>  lookat;
        Vector<T> up;
        Vector<T> u,v,w;
        T         exposuretime;
};

template <typename T>
Camera<T>::Camera(void) :
    eye(0,0,500),
    lookat(0),
    up(0,1,0),
    u(1,0,0),
    v(0,1,0),
    w(0,0,1),
    exposuretime(1.0) {}

template <typename T>
Camera<T>::Camera(const Camera<T>& c) :
    eye(c.eye),
    lookat(c.lookat),
    up(c.up),
    u(c.u),
    v(c.v),
    w(c.w),
    exposuretime(c.exposure_time) {}

template <typename T>
Camera<T>*
Camera<T>::clone(void) const
{
    return new Camera<T>(*this);
}

template <typename T>
Camera<T>&
Camera<T>::operator=(const Camera<T>& rhs)
{
    if(this == &rhs)
        return *this;
        
    eye          = rhs.eye;
    lookat       = rhs.lookat;
    up           = rhs.up;
    u            = rhs.u;
    v            = rhs.v;
    w            = rhs.w;
    exposuretime = rhs.exposuretime;

    return *this;
}

template <typename T>
void
Camera<T>::computeUVW(void)
{
    w = eye - lookat;
    w.normalize();
    u = up ^ w;
    u.normalize();
    v = w ^ u;

    if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y){ 
        u = Vector<T>(0, 0, 1);
        v = Vector<T>(1, 0, 0);
        w = Vector<T>(0, 1, 0);	
    }else if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) {
        u = Vector<T>(1, 0, 0);
        v = Vector<T>(0, 0, 1);
        w = Vector<T>(0, -1, 0);
    }
}
template <typename T>
inline void 
Camera<T>::setEye(const Point<T>& p)
{
    eye = p;
}

template <typename T>
inline void
Camera<T>::setEye(const T x, const T y, const T z)
{
    eye.x = x;
    eye.y = y;
    eye.z = z;
}

template <typename T>
inline void 
Camera<T>::setLookat(const Point<T>& p)
{
    lookat = p;
}

template <typename T>
inline void 
Camera<T>::setLookat(const T x, const T y, const T z)
{
    lookat.x = x;
    lookat.y = y;
    lookat.z = z;
}

template <typename T>
inline void
Camera<T>::setUp(const Point<T>& p)
{
    up = p;
}

template <typename T>
inline void 
Camera<T>::setUp(const T x, const T y, const T z)
{
    up.x = x;
    up.y = y;
    up.z = z;
}
#endif
