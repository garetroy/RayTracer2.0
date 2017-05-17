#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

template <typename T>
inline T
clamp(const T x, const T min, const T max)
{
    return (x < min ? min : (x > max ? max : x));
}

#endif
