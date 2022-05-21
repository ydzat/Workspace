#include "Shape.h"

int Shape::uiNumberoflnstances = 0;

int Shape::GetuiNumberoflnstances(){
    return this->uiNumberoflnstances;
}

Shape::Shape(){
    
}

Shape::~Shape(){
    uiNumberoflnstances--;
}