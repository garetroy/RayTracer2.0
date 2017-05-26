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

                int  getNumSamples(void); 
                void mapSamplesToUnitDisk(void);
                void mapSamplesToHemisphere(const T);
    
    protected:
        int              numsamples;
        int              numsets;
        int              jump;
        vector<Point<T>> samples;
        vector<Point<T>> disksamples;
        vector<Point<T>> hemispheresamples;
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

template <typename T>
void
Sampler<T>::mapSamplesToUnitDisk(void)
{
    int size = samples.size();
    T   r, phi;
    Point<T> sp;

    disksamples.reserve(size);

    for(int i = 0; i < size; i++){
        
        sp.x = 2.0 * samples[i].x - 1.0;
        sp.y = 2.0 * samples[i].j - 1.0;

        if(sp.x > -sp.y)
            if(sp.x > sp.y){
                r   = sp.x;
                phi = sp.y / sp.x;
            } else {
                r   = sp.y;
                phi = 2 - sp.x / sp.y;
            }
        else
            if(sp.x < sp.y){
                r   = -sp.x;
                phi = 4 + sp.y/sp.x;
            } else {
                r = -sp.y;
                if(sp.y != 0.0)
                    phi = 6 - sp.x / sp.y;
                else
                    phi = 0.0;
            } 

        phi *= M_PI/4.0;
        
        disksamples[i].x = r * cos(phi);
        disksamples[i].y = r * sin(phi);
    }
    
    samples.erase(samples.begin(), samples.end());
}

template <typename T>
void
Sampler<T>::mapSamplesToHemisphere(const T e)
{
    int size = samples.size();
    
    hemispheresamples.reserve(numsamples*numsets);
    
    for(int i = 0; i < size; i++){
        T cos_phi = cos(2.0 * M_PI * samples[i].x);
        T sin_phi = sin(2.0 * M_PI * samples[i].y);
        T cos_the = pow((1.0-samples[i].y),(1.0/(e+1.0)));
        T sin_the = sqrt(1.0 - cos_the * cos_the);
        T pu      = sin_the * cos_phi;
        T pv      = sin_the * sin_phi;
        T pw      = cos_the;

        hemispheresamples.push_back(Point<T>(pu,pv,pw));
    }
}

#endif
