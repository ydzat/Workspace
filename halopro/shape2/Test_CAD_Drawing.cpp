#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h> 
#include <iostream> 
#include "CAD_Drawing.h"

using namespace std;
using namespace CAD;

void Test_CAD_Drawing(void); 

int main(void) {   

    Test_CAD_Drawing();    
    _CrtDumpMemoryLeaks();    
    return 0; 

}

void Test_CAD_Drawing(void){

    CAD_Drawing cad01;

    Shape *sh[3];

    sh[0] = new Circle();
    cout << sh[0]->GetuiNumberoflnstances() << endl;
    cad01.AddShape(sh[0]);

    sh[1] = new Rectangle();
    cout << sh[0]->GetuiNumberoflnstances() << endl;
    cad01.AddShape(sh[1]);

    sh[2] = new Triangle();
    cout << sh[0]->GetuiNumberoflnstances() << endl;
    cad01.AddShape(sh[2]);

    cad01.DrawIt();

    cad01.RemoveShape(sh[1]);
    cout << sh[0]->GetuiNumberoflnstances() << endl;

    cad01.RemoveShape(sh[2]);
    cout << sh[0]->GetuiNumberoflnstances() << endl;

    cad01.RemoveShape(sh[0]);
    cout << sh[0]->GetuiNumberoflnstances() << endl;
    
}