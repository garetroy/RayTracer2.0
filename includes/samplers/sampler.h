#ifndef _SAMPLER_H_
#define _SAMPLER_H_

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <point.h>

template <typename T>
class Sampler{
    
    public:
        Sampler(void);
        Sampler(const int);
        Sampler(const int, const int);
        Sampler(const Sampler<T>&);
        virtual ~Sampler(void);

        virtual void        generateSamples(void) = 0;
                void        setupShuffledIndices(void);
                Point<T>    sampleUnitSquare(void);
                Sampler<T>& operator=(const Sampler<T>&); 
        virtual Sampler<T>* clone(void) const = 0;

                int getNumSamples(void); 
    
    protected:
        int              numsamples;
        int              numsets;
        int              jump;
        vector<Point<T>> samples;
        vector<int>      shuffledindices;
        unsigned long    count;
};

template <typename T>
Sampler<T>::Sampler(void) :
    numsamples(1),
    numsets(83),
    count(0),
    jump(0)
{
    samples.reserve(numsamples*numsets);
    setupShuffledIndices();
}

template <typename T>
Sampler<T>::Sampler(const int numsamples) :
    numsamples(numsamples),
    numsets(83),
    count(0),
    jump(0)
{
    samples.reserve(numsamples*numsets);
    setupShuffledIndices();
}

template <typename T>
Sampler<T>::Sampler(const int numsamples, const int nsets) :
    numsamples(numsamples),
    numsets(nsets),
    count(0),
    jump(0)
{
    samples.reserve(numsamples*numsets);
    setupShuffledIndices();
}

template <typename T>
Sampler<T>::Sampler(const Sampler<T>& in) :
    numsamples(in.numsamples),
    numsets(in.numsets),
    count(in.count),
    jump(in.jump),
    shuffledindices(in.shuffledindices),
    samples(in.samples) {}

template <typename T>
Sampler<T>::~Sampler(void)
{}

template <typename T>
Sampler<T>&
Sampler<T>::operator=(const Sampler<T>& rhs)
{
    if(this == &rhs)
        return *this;
    
    numsamples       = rhs.numsamples;
    numsets          = rhs.numsets;
    jump             = rhs.jump;
    samples          = rhs.samples;
    shuffledindices  = rhs.shuffledindices;
    count            = rhs.count;

    return *this;
}

template <typename T>
void
Sampler<T>::setupShuffledIndices(void)
{
    shuffledindices.reserve(numsamples * numsets);
    vector<int> indices;
    
    for (int j = 0; j < numsamples; j++)
            indices.push_back(j);
    
    for (int p = 0; p < numsets; p++) { 
        random_shuffle(indices.begin(), indices.end());	
        for (int j = 0; j < numsamples; j++)
            shuffledindices.push_back(indices[j]);
    }	
}

template <typename T>
Point<T>
Sampler<T>::sampleUnitSquare(void) 
{
    if (count % numsamples == 0)
        jump = (rand() % numsets) * numsamples;	

    return (samples[jump + count++ % numsamples]);	
} 

template <typename T>
int
Sampler<T>::getNumSamples(void)
{
    return numsamples;
} 
#endif
