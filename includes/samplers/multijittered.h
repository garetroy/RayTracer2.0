#ifndef _MULTI_JITTERED_H_
#define _MULTI_JITTERED_H_

#include <sampler.h>
#include <math.h>

template <typename T>
class MultiJittered: public Sampler<T>{
    
    public:
        MultiJittered(void);
        MultiJittered(const int);
        MultiJittered(const int, const int);
        MultiJittered(const MultiJittered<T>&);
        
                MultiJittered<T>& operator=(const MultiJittered<T>&);
        virtual MultiJittered<T>* clone(void) const; 
        

    private:
        virtual void generateSamples(void);
};

template <typename T>
MultiJittered<T>::MultiJittered(void) :
    Sampler<T>() {}

template <typename T>
MultiJittered<T>::MultiJittered(const int ns) :
        Sampler<T>(ns)
{
    generateSamples();
}

template <typename T>
MultiJittered<T>::MultiJittered(const int ns, const int n) :
        Sampler<T>(ns,n)
{
    generateSamples();
}

template <typename T>
MultiJittered<T>::MultiJittered(const MultiJittered<T>& in) :
        Sampler<T>(in)
{
    generateSamples();
}

template <typename T>
MultiJittered<T>&
MultiJittered<T>::operator=(const MultiJittered<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    Sampler<T>::operator=(rhs);
    
    return this;
}

template <typename T>
MultiJittered<T>*
MultiJittered<T>::clone(void) const
{
    return new MultiJittered(*this);
}

template <typename T>
void
MultiJittered<T>::generateSamples(void)
{
    int n = (int)sqrt((T)this->numsamples);
    T   subcellwidth = 1.0/ (T)this->numsamples;

    Point<T> fillpoint;
    for(int i = 0; i < this->numsamples*this->numsets; i++)
        this->samples.push_back(fillpoint);

    //Start distribution
    for(int p = 0; p < this->numsets; p++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                T rand1 = (T)fmod((T)rand(),(subcellwidth+1));
                T rand2 = (T)fmod((T)rand(),(subcellwidth+1));
                this->samples[i*n+j+p * this->numsamples].x = (i*n+j) * subcellwidth + rand1;
                this->samples[i*n+j+p * this->numsamples].y = (i*n+j) * subcellwidth + rand2;
            }

    //Shuffle x
    for(int p = 0; p < this->numsets; p++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int k = rand()%((n-1)-j+1)+j;
                T   t = this->samples[i*n+j+p*this->numsamples].x;
                
                this->samples[i*n+j+p*this->numsamples].x = this->samples[i*n+k+p*this->numsamples].x; 
                this->samples[i*n+k+p*this->numsamples].x = t;
            }

    for(int p = 0; p < this->numsets; p++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int k = rand()%((n-1)-j+1)+j;
                T   t = this->samples[j*n+i+p*this->numsamples].y;
                
                this->samples[j*n+i+p*this->numsamples].y = this->samples[k*n+i+p*this->numsamples].y; 
                this->samples[j*n+i+p*this->numsamples].y = t;
            }
}
#endif
