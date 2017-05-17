#include <iostream>
#include "./include/color.h"
#include "./include/vector.h"
#include "./include/ray.h"
#include "./include/shaderec.h"
#include "./include/bbox.h"
#include "./include/point.h"
#include "./include/mesh.h"
#include "./include/plane.h"
#include "./include/sphere.h"
#include "./include/world.h"

using namespace std;

int 
main()
{
    Worldd newworld;
    
    newworld.render();
    return 1;
}
