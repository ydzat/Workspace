#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include <algorithm>
void CGStupidLineRasterizer::rasterize(const CGVaryings& A,const CGVaryings& B)
{

	// draw a line from vertex0 to vertex1
	CGVec2i start,end;
	start.set((int)A.position.x,
	          (int)A.position.y);
	end.set((int)B.position.x,
	        (int)B.position.y);

	bool swapxy;

	if (abs(end.y - start.y) > abs(end.x - start.x)) swapxy = true;
	else swapxy = false;

	if (swapxy) {
		std::swap(start.x, start.y);
		std::swap(end.x, end.y);
	}
	// Make sure we rasterize from left to right!
	if (start[0] > end[0]) {
		std::swap(start, end);
	}


	// Fragment to work on (initialize from vertex, set coordinates, push).
	CGFragmentData fragment;
	fragment.set(A);

	// U02 A2a) & A2b)
	float dx = end[0] - start[0];
	float dy = end[1] - start[1];
	float m;
	if (dx <=0 ) m = 0.0;
	else m = dy / dx;
	
	float c = end[1] - m * end[0];

	int x = (int)start[0];
	
	while (x <= (int)end[0]) {

		int y = (int)(m * x + c+0.5);
		if (swapxy)
			fragment.coordinates.set(y, x);
		else
			fragment.coordinates.set(x, y);
		m_frag_ops.push_fragment(fragment);
		x++;
	}


	m_frag_ops.flush_fragments();
}
