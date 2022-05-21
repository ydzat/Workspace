#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "CAD_Drawing.h"


void Test_CAD_Drawing(void);

int main()
{
	Test_CAD_Drawing();
	_CrtDumpMemoryLeaks();
	return 0;
}

void Test_CAD_Drawing()
{
	CAD::CAD_Drawing cadTest;
	Shape* testarr[3];
	testarr[0] = new Circle();
	testarr[1] = new Rectangle();
	testarr[2] = new Triangle();
	for (int i = 0; i < 3; i++)
	{
		cadTest.AddShape(testarr[i]);
	}

	cadTest.DrawIt();

}