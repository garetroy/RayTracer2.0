#include <iostream>
#include "../../include/color.h"

using namespace std;

int
main()
{
    Colord colors;
    Colord colors2(1);
    Colord colors3(10);
    Colord colors4(5,10,15);
    Colord colors5(50,80,10);

    //Checking construction
    cout << colors << endl;
    cout << colors2 << endl;
    cout << colors3 << endl;
    cout << colors4 << endl;
    cout << colors5 << endl;

    //-- Checking assignment start

    //Checking addition 
    colors   = colors2 + colors3;
    colors2 += colors3;
    colors3 += 1;
    colors5  = 5.0 + colors5;

    cout << colors << endl;    
    cout << colors2 << endl;
    cout << colors3 << endl;

    //Checking subtraction
    colors3 -= 1; 
    colors2 -= colors3;
    colors   = colors - colors2 - colors3;
    colors5  = 10.0 - colors5;
    
    cout << colors << endl;
    cout << colors2 << endl;
    cout << colors3 << endl; 

    //Checking multiplication and ==
    Colord tens = colors2 * colors3;
    colors2    *= colors2;
    colors3    *= 1;
    colors5     = 2.0 * colors5;
    if(colors3 == tens)
        cout << "True" << endl;

    cout << colors2 << endl;
    cout << colors3 << endl;

    //checking division
    Colord ones = colors3 /= colors3;
    ones       /= 2; 
    colors5     = 10.0 / colors5;

    cout << ones << endl;

    //checking negation
    colors5 = -colors5;

    //-- Checking assignment end

    //checking [] access
    cout << colors4[0] << " " << colors4[1] << " " << colors4[2] << endl;
    //Checking out of access (returns colors4[0])
    cout << colors4[5] << endl;

    //checking average
    colors2.average(); 
    cout << colors2 << endl;

    //checking pow
    Colord out = colors4.powc(2.0);
    cout << out << endl;
    cout << colors5 << endl;

    return 0;
}
    
