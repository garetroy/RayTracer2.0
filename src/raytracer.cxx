#include <iostream>
#include <color.h>
#include <vector.h>
#include <ray.h>
#include <shaderec.h>
#include <bbox.h>
#include <point.h>
#include <mesh.h>
#include <plane.h>
#include <sphere.h>
#include <world.h>

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
