#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include "CGContext.h"
#include <algorithm>

//------------------------------------------------------------------------------
void CGTriangleRasterizer::rasterize(const CGVaryings& A, const CGVaryings& B, const CGVaryings& C)
{
	// shortcuts for position of each input vertex
	const CGVec4& a = A.position;
	const CGVec4& b = B.position;
	const CGVec4& c = C.position;
	CGFragmentData fragment;

	// TODO: Uebung 05, Aufgaben 1b, 2b, 3

	int x_min = static_cast<int>(std::min(std::min(a.x, b.x), c.x));
	int x_max = static_cast<int>(std::max(std::max(a.x, b.x), c.x));
	int y_min = static_cast<int>(std::min(std::min(a.y, b.y), c.y));
	int y_max = static_cast<int>(std::max(std::max(a.y, b.y), c.y));

	float area_ABC = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

	for (int x = x_min; x <= x_max; x++) {

		for (int y = y_min; y <= y_max; y++) {

			float x_pos = static_cast<float>(x + 0.5);
			float y_pos = static_cast<float>(y + 0.5);

			// alpha = det(B-P,C-P)
			float alpha = (b.x - x_pos) * (c.y - y_pos) - (b.y - y_pos) * (c.x - x_pos);
			// beta = det(C-P,A-P)
			float beta = (c.x - x_pos) * (a.y - y_pos) - (c.y - y_pos) * (a.x - x_pos);
			// gamma = det(A-P,B-P)
			float gamma = (a.x - x_pos) * (b.y - y_pos) - (a.y - y_pos) * (b.x - x_pos);

			alpha /= area_ABC;
			beta /= area_ABC;
			gamma /= area_ABC;


			if ((alpha >= 0.0) && (beta >= 0.0) && (gamma >= 0.0)) {

				fragment.coordinates.set(x, y);
				fragment.set(A, B, C, alpha, beta, gamma);
				//fragment.set(A);
				m_frag_ops.push_fragment(fragment);
			}
		}
	}








	m_frag_ops.flush_fragments();
}
