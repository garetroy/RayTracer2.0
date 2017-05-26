#ifndef _JITTERED_H_
#define _JITTERED_H_

#include <sampler.h>

template <typename T>
class Jittered: public Sampler<T>{
    
    public:
        Jittered(void);
        Jittered(const int);
        Jittered(const int, const int);
        Jittered(const Jittered<T>&);
        
        Jittered<T>& operator=(const Jittered<T>&);
        
        virtual Jittered<T>* clone(void) const;

        private:
            virtual void generateSamples(void);
};

template <typename T>
Jittered<T>::Jittered(void) :
    Sampler<T>() {}

template <typename T>
Jittered<T>::Jittered(const int numsam, const int m) :
    Sampler<T>(numsam, m)
{
    generateSamples();
}

template <typename T>
Jittered<T>::Jittered(const Jittered<T>& j) :
    Sampler<T>(j)
{
    generateSamples();
}

template <typename T>
Jittered<T>&
Jittered<T>::operator=(const Jittered<T>& rhs)
{
    if(this == &rhs)
        return *this;

    Sampler<T>::operator=(rhs);
    
    return *this;
}

template <typename T>
void
Jittered<T>::generateSamples(void)
{
    int n = (int) sqrt((T)this->numsamples);
    
    for(int i = 0; i < this->numsets; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++){
                Point<T> sp((k+(double)rand()/RAND_MAX)/n, (j+(double)rand()/RAND_MAX)/n); 
                this->samples.push_back(sp);
            }
}
#endif
