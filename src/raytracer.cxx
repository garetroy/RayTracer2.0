#include <iostream>
#include <color.h>
#include <vector>
#include <ambient.h>
#include <glossyspecular.h>
#include <phong.h>
#include <vector.h>
#include <ray.h>
#include <shaderec.h>
#include <bbox.h>
#include <point.h>
#include <mesh.h>
#include <plane.h>
#include <object.h>
#include <sphere.h>
#include <world.h>
#include <omp.h>
#include <directional.h>
#include <directional.h>

using namespace std;

int 
main()
{
    //double time = omp_get_wtime();
    Worldd newworld;
    
    Pointd zeros(0.0,0.0,-200.3);
    Pointd pos2(-134.0,600.03,200.2);
    Pointd pos(300.03,-300.05,-1.3);
    Directional<double>* light2 = new Directional<double>;
    light2->setDirection(0,0,500);
    light2->scaleRadience(2.0);
    newworld.addLight(light2);

    Phong<double>* matt = new Phong<double>;
    matt->setka(0.25);
    matt->setkd(0.65);
    matt->setcd(1,1,0);

    Sphere<double> news(zeros,300.0);
    Sphere<double> news2(pos,25.0);
    Triangle<double> tri(pos2,pos,zeros);
    news.setMaterial(matt);
    news2.setMaterial(matt);
    tri.setMaterial(matt);
    

    newworld.addObject(&news);
    newworld.addObject(&news2);
    newworld.addObject(&tri);
    newworld.render();
    newworld.writeScreen();
    //cerr << omp_get_wtime() - time << endl;
    return 1;
}
