#ifndef _VIEWPLANE_H_
#define _VIEWPLANE_H_

template <typename T>
struct ViewPlane{
        int h;
        int w;
        int numsamples;
        T   s;
        T   gamma; 
        T   invGamma;
        T   pixelSize;
        
        Color<T>*   buffer;
        Sampler<T>* sampler;

        ViewPlane(void);
        ViewPlane(int, int); 
        
        void resize(int,int);
        void setPixel(int, int, Color<T>&);
        void setSampler(Sampler<T>*);
//        void setSamples(Sampler<T>&);
};

template <typename T>
ViewPlane<T>::ViewPlane(void)
{
    h = 0;
    w = 0;
    s = 1;
    
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
    if(i+j*w > w*h)
        return;

    for(int k = 0; k < 3; k++)
        buffer[(w*j+i)][k] = std::min(255.0,in[k]*255.0); 
    
}

template <typename T>
void
ViewPlane<T>::setSampler(Sampler<T>* sp)
{
    if(sampler){
        delete sampler;
        sampler = nullptr;
    }
    
    numsamples = sp->getNumSamples();
    sampler = sp;
}

/*template <typename T>
void
ViewPlant<T>::setSamples(const int n)
{
    numsamples = n;
    
    if(sampler){
        delete sampler;
        sampler = nullptr;
    }
    
    if(numsamples > 1)
        sampler = new MultiJittered(numsamples);
    else
        sampler = new Regular(1);
}*/

#endif
