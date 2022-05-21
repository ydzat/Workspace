#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include <algorithm>

void CGBresenhamLineRasterizer::rasterize(const CGVaryings& A,const CGVaryings& B)
{
	// draw a line from a to  b
	CGVec2i start,end;
	start.set((int)A.position.x,
	         (int)A.position.y);
	end.set((int)B.position.x,
	       (int)B.position.y);

	// fragment to work on (initialize from vertex, set coordinates, push).
	CGFragmentData fragment;
	fragment.set(A);
	// U2 A1 & A2
    bool swapxy = abs(end.y-start.y) > abs(end.x-start.x);

    if(swapxy){
        std::swap(start.x,start.y);
        std::swap(end.x,end.y);
    }

	int x = start.x;
    int y = start.y;

    int dx = abs(end.x-start.x);
    int dy = abs(end.y-start.y);

    int d = 2*dy - dx;
    int dE = 2*dy;
    int dNE = 2*(dy-dx);

    int xstep = (end.x >= start.x)? 1: -1;
    int ystep = (end.y >= start.y)? 1: -1;

    float ratio = 0.0f;

    while (x != end.x + xstep) {

        if(swapxy)
            fragment.coordinates.set(y,x);
        else
            fragment.coordinates.set(x,y);

        fragment.set(A,B,ratio);

		m_frag_ops.push_fragment(fragment);

        x+=xstep;
        ratio += 1.0f/(float)dx;

        if(d <= 0) //E
            d += dE;
        else { //NE
            d += dNE;
            y += ystep;
        }
	}

	m_frag_ops.flush_fragments();
}
