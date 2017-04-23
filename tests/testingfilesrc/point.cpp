#include <iostream>

#include "../../include/point.h"
#include "../../include/vector.h"
#include "../../include/matrix.h"

using namespace std;

int
main()
{
    Pointd point;
    Pointd point2(1);
    Pointd point3(2);
    Pointd point4(2,4,6);
    Pointd point5(point2);

    //Checking construction
    cout << point << endl;
    cout << point2 << endl;
    cout << point3 << endl;    
    cout << point4 << endl;
    cout << point5 << endl;

    //-- Checking assignment start
    
    //Checking multiplication
    point3 = point3 * 2.0;
    point2 = 2.0 * point2;
    cout << point3 << endl;
    cout << point2 << endl;

    //Checking addition
    Vector<double> vec(2);
    point3 = point3 + vec; 
    cout << point3 << endl; 

    //Checking negation and subtraction
    vec = point4 - point3;
    point4 = point4 - vec;
    point2 = -point2;
    cout << vec << endl;
    cout << point4 << endl;
    cout << point2 << endl;

    //Checking Matrix multi
    Matrix<double> mat;
    point5 = mat * point;
    cout << point5 << endl; 
    
    //-- Checking assignment end/   

    //Checking acessor
    cout << point2[1] << endl;
    cout << point2[5] << endl;

    //Checking d_squared
    Pointd twos(2);
    cout << twos.d_squared(twos) << endl;

    //Checking distance
    Pointd threes(1.7320508076); 
    Pointd zeros(0);
    cout << threes.distance(zeros) << endl; 
}
    

