#ifndef _REGULAR_H_
#define _REGULAR_H_

#include <sampler.h>

template <typename T>
class Regular: public Sampler<T>{
    
    public:
        Regular(void);
        Regular(const int);
        Regular(const Regular&);
        
                Regular<T>& operator=(const Regular<T>&);
        virtual Regular<T>* clone(void) const;
        virtual void        generateSamples(void);
};

template <typename T>
Regular<T>::Regular(void) :
    Sampler<T>() {}

template <typename T>
Regular<T>::Regular(const int num) :
    Sampler<T>(num)
{
    generateSamples();
}

template <typename T>
Regular<T>::Regular(const Regular<T>& in) :
    Sampler<T>(in)
{
    generateSamples();
}

template <typename T>
Regular<T>&
Regular<T>::operator=(const Regular<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    Sampler<T>::operator=(rhs);
    
    return *this;
} 

template <typename T>
Regular<T>*
Regular<T>::clone(void) const
{
    return new Regular<T>(*this);
}

template <typename T>
void
Regular<T>::generateSamples(void)
{
    int n = (int)sqrt((T)this->numsamples);

    for(int p = 0; p < this->numsets; p++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) 
                this->samples.push_back(Point<T>((j+0.5)/n, (i+0.5)/n));
}
#endif
