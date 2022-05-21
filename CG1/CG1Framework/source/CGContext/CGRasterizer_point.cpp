#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include "CGContext.h"
#include "CGMath.h"

void CGPointRasterizer::rasterize(const CGVaryings& A)
{
	// Initialize the fragment.
	CGFragmentData fragment;
	// And set coordinates. (SetFragment initializes just the attributes + varyings).

	fragment.set(A);
	fragment.coordinates =  A.position;
	m_frag_ops.push_fragment(fragment);
	m_frag_ops.flush_fragments();

    // U01: A4a) & A4c) Raster bigger points. Point radius is stored in
	// m_context.pointRadius. The viewport in m_context.viewport.
     CGVec2i pos_A = A.position;

    for(int dx=-m_context.pointRadius; dx <= m_context.pointRadius; dx++){
        for(int dy=-m_context.pointRadius; dy <= m_context.pointRadius; dy++){
            CGVec2i d(dx,dy);

            fragment.coordinates = CGMath::clamp(pos_A + d,m_context.viewport.bottomLeft(),m_context.viewport.topRight());
            m_frag_ops.push_fragment(fragment);
        }
    }



	// Push the fragment into the pipeline.
	m_frag_ops.flush_fragments();
}
