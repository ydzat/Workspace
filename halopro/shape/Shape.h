#pragma once


class Shape
{
public:
	Shape();
	~Shape();
	virtual void Draw() = 0;
	int GetuiNumberoflnstances();

protected:
	int uiNumberoflnstances;

};	

