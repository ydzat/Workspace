#include "Circle.h"


Circle::Circle()
{
	uiNumberoflnstances++;

#ifdef _DEBUG
	std::cout << "Circle Constructor is called" << std::endl;
#endif // _DEBUG
}
Circle::~Circle()
{
#ifdef _DEBUG
	std::cout << "Circle Deconstructor is called" << std::endl;
#endif // _DEBUG
}

void Circle::Draw()
{
	std::cout << "Draw Circle"<<std::endl;
}
