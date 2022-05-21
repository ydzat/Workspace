#include "CAD_Drawing.h"
#include <iostream>
using namespace CAD;
using namespace std;

CAD_Drawing::CAD_Drawing(void){
    setShapes.clear();
}


CAD_Drawing::~CAD_Drawing(void){

}

void CAD_Drawing::AddShape(Shape* pointer){
    
    setShapes.insert(pointer);
}

void CAD_Drawing::RemoveShape(Shape* pointer){
    
    delete pointer;
    pointer = NULL;
    setShapes.erase(pointer);
}

void CAD_Drawing::DrawIt(void){
    for (auto it : setShapes)
	{
        cout << it->Draw() << endl;
        
    }
}