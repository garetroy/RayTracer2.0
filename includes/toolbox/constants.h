#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <math.h>
#include <color.h>

const double TWO_PI     = 2*M_PI;
const double PI_ON_180  = 0.0174532925199432957; 
const double INVPI      = 1/M_PI;
const double INVTWO_PI  = 1/TWO_PI;
const double kepsilon   = 0.0001;
const double khugevalue = 1.0E10;

const Colord black(0.0);
const Colord white(1.0);
const Colord red(1.0,0.0,0.0);

const double invrandmax = 1.0 / double(RAND_MAX);

#endif
