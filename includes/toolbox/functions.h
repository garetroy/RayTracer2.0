#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

template <typename T>
inline T
clamp(const T x, const T min, const T max)
{
    return (x < min ? min : (x > max ? max : x));
}

template <typename T>
inline T
minmin(const T x, const T x2, const T x3)
{
    return std::min(std::min(x,x2),x3);
}

template <typename T>
inline T
maxmax(const T x, const T x2, const T x3)
{
    return std::max(std::max(x,x2),x3);
}
#endif
