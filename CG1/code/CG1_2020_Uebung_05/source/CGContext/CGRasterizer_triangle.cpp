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

	m_frag_ops.flush_fragments();
}
