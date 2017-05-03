#include "../../include/vector.h"
#include "../../include/point.h"
#include "../../include/normal.h"
#include <iostream>

using namespace std;

int main()
{
    Normald menorm(10);
    Pointd  mepoint(11); 

    Vectord v1;
    Vectord v2(1);
    Vectord v3(2,4,6);
    Vectord v4(v3);
    Vectord v5(menorm);
    Vectord v6(mepoint);

    //Checking constructors
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << v4 << endl;
    cout << v5 << endl;
    cout << v6 << endl;
    

    //-- CHecking assignment start
    Vectord vtov = v4;
    Vectord ntov = menorm;
    Vectord ptov = mepoint;
    
    cout << vtov << endl;
    cout << ntov << endl;
    cout << ptov << endl;
    
    //Checking addition/subtraction assignment 
    v2 += v2;
    v2 += 1.0;
    v2 -= 1.0;
    v2 -= v2;
    
    cout << v2 << endl;

    //Checking multiplication/division assignment
    Vectord twos(2);
    twos *= twos;
    twos *= 2.0;
    twos /= 2.0;
    twos /= twos; 
    
    cout << twos << endl;
    
    //Checking addition
    Vectord negthrees(-3);
    Vectord zeros(0);
    zeros = zeros + 3;
    negthrees = +negthrees;
    
    cout << negthrees << endl;
    cout << zeros << endl;
    
    
    return 0;
}
