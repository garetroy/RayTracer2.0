#ifndef _VIEWPLANE_H_
#define _VIEWPLANE_H_

template <typename T>
struct ViewPlane{
        int h;
        int w;
        T   s;
        T   gamma; 
        T   invGamma;
        T   pixelSize;
        
        Color<T>* buffer;

        ViewPlane(void);
        ViewPlane(int, int); 
        
        void resize(int,int);
        void setPixel(int, int, Color<T>&);
};

template <typename T>
ViewPlane<T>::ViewPlane(void)
{
    h = 0;
    w = 0;
    
    pixelSize = 1.0;
    gamma     = 1.0;

    buffer = nullptr;
}

template <typename T>
ViewPlane<T>::ViewPlane(int _h, int _w)
{
    h = _h;
    w = _w;

    pixelSize  = 1.0;
    gamma      = 1.0; 
    
    buffer = new Color<T>[h*w];
}    

template <typename T>
void
ViewPlane<T>::resize(int _h, int _w)
{
    if(buffer != nullptr)
        delete [] buffer;
    
    h = _h;
    w = _w;
    buffer = new Color<T>[h*w];
}

template <typename T>
void
ViewPlane<T>::setPixel(int i, int j, Color<T>& in)
{
    if(i*j > w*h)
        return;

    for(int k = 0; k < 3; k++)
        buffer[i+j][k] = in[k]; 
    
}

#endif
