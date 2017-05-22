#ifndef _WORLD_H_
#define _WORLD_H_

#include <iostream>
#include <vtkPNGWriter.h>
#include <vtkImageData.h> 

#include "constants.h"
#include "viewplane.h"
#include "singlesphere.h"
#include "normal.h"
#include "vector.h"
#include "tracer.h"
#include "object.h"
#include "point.h"
#include "ray.h"

template <typename T>
struct World{
    
    ViewPlane<T>       vp;
    Color<T>           background;
    SingleSphere<T>*   tracer;
    Sphere<T>          sphere;
//    vector<Object<T>*> objects;
    
    World(void);
    World(ViewPlane<T>& in);
    
    void render(void);
    void writeScreen(void);
    void addObject(Object<T>* in);

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
    tracer =  new SingleSphere<T>(this); 
    sphere.setCenter(Point<T>(0.0));
    sphere.setRadius(85.0);
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

            vp.setPixel(i,j,color); // Something is going on with this set pixel
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
    for(int i = 0; i < (vp.h*vp.w)/3; i++){
        buffer[i]   = (unsigned char)std::min(vp.buffer[i][0]*255,255.0);
        buffer[i+1] = (unsigned char)std::min(vp.buffer[i][1]*255,255.0);
        buffer[i+2] = (unsigned char)std::min(vp.buffer[i][2]*255,255.0);
        std::cout << "Pixel[" << i << "]: " << buffer[i] << " " << buffer[i+1] << " " << buffer[i+2] << std::endl;
    }
         
    vtkPNGWriter *writer = vtkPNGWriter::New();
    writer->SetInputData(image);
    writer->SetFileName("blob.png");
    writer->Write();
    writer->Delete();
    image->Delete();

}

/*template <typename T>
inline void
World<T>::addObject(Object<T>* in)
{
    objects.push_back(in);
}*/

#endif
