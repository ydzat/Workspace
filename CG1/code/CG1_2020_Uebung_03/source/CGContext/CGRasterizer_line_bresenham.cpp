#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include <algorithm>

void CGBresenhamLineRasterizer::rasterize(const CGVaryings& A,const CGVaryings& B)
{
	// draw a line from vertex0 to vertex1
	CGVec2i start, end;
	start.set((int)A.position.x, (int)A.position.y);
	end.set((int)B.position.x, (int)B.position.y);

	bool swap_xy = abs(end.x - start.x) < abs(end.y - start.y);

	if (swap_xy)
	{
		std::swap(start.x, start.y);
		std::swap(end.x, end.y);
	}

	// Fragment to work on (initialize from vertex, set coordinates, push).
	CGFragmentData fragment;
	fragment.set(A);

	// Aufgaben 1 und 2

	// U03 A1 und A2
	// Hinweise:
	//   - Es werden nur Linien gezeichnet, bei denen der Anstieg m im Bereich [0, 1] liegt. Oder einfacher ausgedrückt: Der Anstieg dx muss 
	//     größer oder gleich dy sein. Außerdem darf dy nicht negativ sein (dy >= 0).
	//   - Den Pseudocode zur Implementierung beider Verfahren finden Sie in der Aufgabenbeschreibung zur dritten Prüfungsvorleistung.

	const int x_step = 1;
	const int y_step = 1;

	// TODO: ...
	
	m_frag_ops.flush_fragments();
}
