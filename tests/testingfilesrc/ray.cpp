#include <iostream>

#include "../../include/ray.h"
#include "../../include/vector.h"
#include "../../include/point.h"

using namespace std;

int
main()
{
    Vector<double> vec(5);
    Pointd  point(5);
    
    //Checking constructors
    Rayd inray;
    Rayd inray2(point,vec);
    Rayd inray3(inray2);

    cout << inray << endl;
    cout << inray2 << endl;
    cout << inray3 << endl;

    //Checking assignment
    Rayd ray;
    ray = inray3;

    cout << ray << endl;
    return 1;
}
