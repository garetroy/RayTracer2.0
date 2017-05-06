#include "../../include/vector.h"
#include "../../include/point.h"
#include "../../include/matrix.h"
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
    

    //-- Checking assignment start
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
    zeros     = zeros + 3;
    negthrees = +negthrees;
    
    cout << negthrees << endl;
    cout << zeros << endl;

    //Checking subtraction
    Vectord negfours(-4);
    Vectord fives(5);
    fives    = fives + 5; 
    negfours = -negfours;

    cout << fives << endl;
    cout << negfours << endl;
    

    //Checking mulitplication
    twos *= 0;
    twos += 2;
    Vectord temp(0);
    temp = twos * 2;

    cout << temp << endl;

    //Checking division
    twos *= 0;
    twos += 2;
    twos = twos / 2;
    
    cout << twos << endl;

    //Checking cross product 
    Vectord in(1,2,3);
    Vectord out(3,2,1);
    
    out = in^out;
    
    cout << out << endl;

    //-- Checking assignment stop

    //Checking bool operator
    Vectord True1(1);
    Vectord True2(1);
    Vectord False(2); 

    cout << (True1 == True2) << endl;
    cout << (True1 == False) << endl;

    //Checking [] accessor
    Vectord testing(9,2,-4);
   
    cout << testing[2] << endl;
    cout << testing[5] << endl;
    cout << testing[-1] << endl; 

    //Checking type return operations
    Vectord sixes(6);
    
    cout << (sixes + sixes) << endl; 
    cout << (sixes - sixes) << endl;
    cout << (sixes * sixes) << endl;
    cout << (sixes / sixes) << endl;

    //Checking normalization
    Vectord nor(9,1231,2);
    Vectord ne(3,4,5);
    nor = nor.hat(); 
    ne.normalize();

    cout << nor << endl;
    cout << ne << endl;
    
    //Checking length
    Vectord newtwos(2,2,2); 
    
    cout << newtwos.length() << endl;

    //Checking left side multiplication
    Vectord tens(10);
    tens = 10.0 * tens;
    
    cout << tens << endl;

    //Checking Matrix Multi
    Vectord eleven(11);
    Matrixd matri;
    
    eleven = matri * eleven;

    cout << eleven << endl;

    return 0;
}
