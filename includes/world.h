#ifndef _WORLD_H_
#define _WORLD_H_

#include <iostream>
#include <vtkPNGWriter.h>
#include <vtkImageData.h> 

#include "multipleobjects.h"
#include "constants.h"
#include "viewplane.h"
#include "normal.h"
#include "vector.h"
#include "tracer.h"
#include "object.h"
#include "point.h"
#include "ray.h"

template <typename T>
struct World{
    
    ViewPlane<T>        vp;
    Color<T>            background;
    MultipleObjects<T>* tracer;
    vector<Object<T>*> objects;
    
    World(void);
    World(ViewPlane<T>& in);
    
    void        render(void);
    void        writeScreen(void);
    void        addObject(Object<T>*);
    ShadeRec<T> hitObject(const Ray<T>&);

    friend ostream &operator<<(ostream& os, const World<T>&in)
    {
	    os << "World: " << std::endl << " " << in.background << std::endl;
	    return os;
    }
}; 
typedef World<float>  Worldf;
typedef World<double> Worldd;

template <typename T>
World<T>::World(void)
{
    vp.resize(200,200);

    background = black; 
    tracer =  new MultipleObjects<T>(this); 
}

template <typename T>
World<T>::World(ViewPlane<T>& in)
{
    vp(in);
    background = black; 
}

template <typename T>
void
World<T>::render(void)
{
    Color<T> color;
    Ray<T>   ray;
    T        zw, x, y;
    
    zw = 100.0;

    ray.direction = Vector<T>(0,0,-1);
    for(int i = 0; i < vp.w; i++)
        for(int j = 0; j <= vp.h; j++){

            x = vp.s * (j - 0.5 * (vp.h - 1.0));
            y = vp.s * (i - 0.5 * (vp.w - 1.0));

            ray.origin = Point<T>(x,y,zw);
            color      = tracer->traceRay(ray);

            vp.setPixel(i,j,color);
        }
}

template <typename T>
void 
World<T>::writeScreen(void)
{
    vtkImageData *image = vtkImageData::New();
    image->SetDimensions(200,200,1);
    image->AllocateScalars(VTK_UNSIGNED_CHAR, 3);
    unsigned char *buffer = 
        (unsigned char *) image->GetScalarPointer(0,0,0);
    for(int i = 0; i < vp.h*vp.w; i++){
        buffer[3*i]     = (unsigned char)vp.buffer[i][0];
        buffer[3*i+1]   = (unsigned char)vp.buffer[i][1];
        buffer[3*i+2]   = (unsigned char)vp.buffer[i][2];
    }
         
    vtkPNGWriter *writer = vtkPNGWriter::New();
    writer->SetInputData(image);
    writer->SetFileName("blob.png");
    writer->Write();
    writer->Delete();
    image->Delete();

}

template <typename T>
inline void
World<T>::addObject(Object<T>* in)
{
    objects.push_back(in);
}

template <typename T>
ShadeRec<T>
World<T>::hitObject(const Ray<T>& in)
{
    ShadeRec<T> sr(*this); 
    T t;
    T tmin              = khugevalue;
    int num_objects     = objects.size();

    for (int j = 0; j < num_objects; j++)
            if (objects[j]->hit(in, t, sr) && (t < tmin)) {
                    sr.hitobject   = true;
                    tmin           = t;
                    sr.color       = objects[j]->getColor();
            }  
    return sr;   
}

#endif
