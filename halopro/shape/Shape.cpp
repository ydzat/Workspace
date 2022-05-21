#include "Shape.h"
 
Shape::Shape() 
{
	uiNumberoflnstances = 0;
	//uiNumberoflnstances ++;
#ifdef _DEBUG
	std::cout << "Shape Default Constructor is called" << std::endl;
#endif // _DEBUG
}

Shape::~Shape()
{
#ifdef _DEBUG
	std::cout << "Shape Deconstructor is called" << std::endl;
#endif // _DEBUG

}

 int Shape::GetuiNumberoflnstances()
{
	return uiNumberoflnstances;
}

