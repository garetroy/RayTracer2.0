#include "../../include/mesh.h"
#include "../../include/normal.h"
#include "../../include/point.h"
#include <iostream>

using namespace std;

int main()
{
    
    //Testing constructors
    Meshd inmesh;
    inmesh.numvertices = 100;
    Meshd inmesh2(inmesh);
    cout << inmesh << endl;
    cout << inmesh2 << endl;

    //Testing assignment
    inmesh = inmesh2;
    cout << inmesh2 << endl;

} 
