#include "Rectangle.h"

Rectangle::Rectangle(){
    uiNumberoflnstances++;
}

Rectangle::~Rectangle(){
    //uiNumberoflnstances--;
}

string Rectangle::Draw(){
    return "Draw Rectangle";
}