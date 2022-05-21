#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
#ifdef _DEBUG
	std::cout << "Rectangle Constructor is called" << std::endl;
#endif // _DEBUG
	uiNumberoflnstances++;
}

Rectangle::~Rectangle()
{
#ifdef _DEBUG
	std::cout << "Rectangle Deconstructor is called" << std::endl;
#endif // _DEBUG
}


void Rectangle::Draw()
{
	std::cout << "Draw Rectangle" << std::endl;
}