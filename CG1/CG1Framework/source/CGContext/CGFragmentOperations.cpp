#include "CGFragmentOperations.h"
#include "CGFrameBuffer.h"
#include "CGContext.h"
//------------------------------------------------------------------------------
CGFragmentOperations::CGFragmentOperations(CGContext &context, CGFrameBuffer &framebuffer)
	:m_context(context),m_frame_buffer(framebuffer)
{
	m_num_fragments = 0;
}
//------------------------------------------------------------------------------
void CGFragmentOperations::push_fragment(const CGFragmentData &frag)
{
	//U02 A3c)
#if 0
	// enable this only for rasterizer benchmarking
	// bypass complete fragment pipeline, write directly to color buffer
	m_frame_buffer.colorBuffer.set_white(frag.coordinates);
#else
	m_fragment_buffer[m_num_fragments] = frag;
	m_num_fragments++;
	if(m_num_fragments == CG_MAX_FRAGMENTS_IN_PIPELINE)
		flush_fragments();
#endif
}
//------------------------------------------------------------------------------
void CGFragmentOperations::flush_fragments()
{
	// #pragma omp parallel for
	for(unsigned int i  =0 ; i < m_num_fragments;i++)
	{
		process_fragment(m_fragment_buffer[i]);
	}
	m_num_fragments = 0;
}
//------------------------------------------------------------------------------
bool CGFragmentOperations::fragment_clipping(const CGFragmentData &fragment)
{
	//returns true if the fragment is inside the viewport
	// U06 A3b)
    if(m_context.viewport.isInside(fragment.coordinates)) return true;
    return false;
}
//------------------------------------------------------------------------------
bool CGFragmentOperations::z_test(const CGFragmentData &fragment)
{
	//returns true if the fragment is visible
	// U09 A1c)
    if(fragment.varyings.position.z < m_frame_buffer.depthBuffer.get(fragment.coordinates)) return true;
    return false;
}
//------------------------------------------------------------------------------
void CGFragmentOperations::fragment_blending(CGFragmentData &fragment)
{
	// U09 A2a)
    float alpha = fragment.varyings.color.w;
    const CGVec4 backColor = m_frame_buffer.colorBuffer.get(fragment.coordinates);
    const CGVec4 fragColor = fragment.varyings.color;

    fragment.varyings.color = fragColor * alpha + backColor * (1.0f - alpha);
}
//------------------------------------------------------------------------------
void CGFragmentOperations::write_to_framebuffer(const CGFragmentData &fragment)
{
	// Write the current fragment into the framebuffer.
	// color into color buffer
	m_frame_buffer.colorBuffer.set(fragment.coordinates,fragment.varyings.color);

	// window space z coordinate into depth buffer
    if(m_context.depthTestIsEnabled)
        m_frame_buffer.depthBuffer.set(fragment.coordinates, fragment.varyings.position.z);
}
//------------------------------------------------------------------------------
void CGFragmentOperations::process_fragment(CGFragmentData &fragment)
{
	if(!fragment_clipping(fragment))
		return;

	// early depth test
	if(m_context.depthTestIsEnabled && !z_test(fragment))
		return;

	CGVec4 clr;
	m_context.currentProgram->fragment_shader(fragment.varyings,clr);
	fragment.varyings.color = clr;

	if(m_context.blendingIsEnabled)
		fragment_blending(fragment);

	write_to_framebuffer(fragment);
}
