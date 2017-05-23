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
    
    Pointd zeros(0.0);
    Sphere<double> news(zeros,85.0);
    
    newworld.addObject(&news);
    newworld.render();
    newworld.writeScreen();
    return 1;
}
