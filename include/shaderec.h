#ifndef _SHADEREC_H_
#define _SHADEREC_H_

#include "constants.h"
#include "point.h"
#include "normal.h"
#include "color.h"
#include "ray.h"

template <typename T>
class Material;
template <typename T>
class World;

template <typename T>
struct ShadeRec{

    //Material<T>* material;
    Normal<T>    normal;
    World<T>&    w;
    Point<T>     hitpoint;
    Point<T>     localhitpoint;
    Color<T>     color;
    Ray<T>       ray;
    bool         hitobject;
    int          depth;
    T            t;
    T            u;
    T            v;

    ShadeRec(World<T>&);
    ShadeRec(const ShadeRec<T>&);
    ~ShadeRec(void);
};
typedef ShadeRec<float>  ShadeRecf;
typedef ShadeRec<double> ShadeRecd;

template <typename T>
ShadeRec<T>::ShadeRec(World<T>& in)
    : hitobject(false),
     // material(nullptr),
      hitpoint(),
      normal(),
      ray(),
      depth(0),
      color(black),
      t(0.0),
      u(0.0),
      v(0.0),
      w(in)
{}

template <typename T>
ShadeRec<T>::ShadeRec(const ShadeRec& sr)
    : hitobject(sr.hitobject),
      //material(sr.material),
      hitpoint(sr.hitpoint),
      localhitpoint(sr.localhitpoint),
      normal(sr.normal),
      ray(sr.ray),
      depth(sr.depth),
      color(sr.color),
      t(sr.t),
      u(sr.u),
      v(sr.v),
      w(sr.w)
{}

template <typename T>
ShadeRec<T>::~ShadeRec(void)
{
    /*if(material){
        delete material;
        material = nullptr;
    }*/
}

#endif
