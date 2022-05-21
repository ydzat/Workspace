#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include "CGContext.h"
#include "CGMath.h"

void CGPointRasterizer::rasterize(const CGVaryings& A)
{
	CGFragmentData fragment;

	// U01 A4a) & A4c)
	// Hinweise:
	//   - fragment.set(...) setzt nur die Varyings. Fragmentkoordinaten werden in
	//     fragment.coordinates hinterlegt.
	//   - m_frag_ops.push_fragment(fragment) reiht das Fragment f�r die Weiterverarbeitung ein.
	//   - m_frag_ops.flush_fragments() verarbeitet _alle_ eingereihten Fragmente.
	//   - m_context.pointRadius enth�lt den aktuellen Punktradius.
	//   - m_context.viewport enth�lt die aktuellen Viewport-Parameter.
	fragment.set(A);
	fragment.coordinates =  A.position;
	m_frag_ops.push_fragment(fragment);
	m_frag_ops.flush_fragments();

	CGVec2i pos_A = A.position;

	for (int dx = -m_context.pointRadius; dx <= m_context.pointRadius; dx++) {
		for (int dy = -m_context.pointRadius; dy <= m_context.pointRadius; dy++) {
			CGVec2i d(dx, dy);

			fragment.coordinates = CGMath::clamp(pos_A + d, m_context.viewport.bottomLeft(), m_context.viewport.topRight());
			m_frag_ops.push_fragment(fragment);
		}
	}



	// Push the fragment into the pipeline.
	m_frag_ops.flush_fragments();


}
