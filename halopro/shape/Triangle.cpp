#include"Triangle.h"

Triangle::Triangle() : Shape()
{
#ifdef _DEBUG
	std::cout << "Triangle Constructor is called" << std::endl;
#endif // _DEBUG
	uiNumberoflnstances++;

}

Triangle::~Triangle()
{
#ifdef _DEBUG
	std::cout << "Triangle Deconstructor is called" << std::endl;
#endif // _DEBUG

}

void Triangle::Draw()
{
	std::cout << "Draw Triangle" << std::endl;
}