#pragma once
#include <set>
#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"


namespace CAD {
	class CAD_Drawing
	{
	private:
		std::set<Shape*> setShapes;
	public:
		CAD_Drawing(void);
		~CAD_Drawing(void);
		void AddShape(Shape*);
		void RemoveShape(Shape*);
		void DrawIt(void);
	};


}