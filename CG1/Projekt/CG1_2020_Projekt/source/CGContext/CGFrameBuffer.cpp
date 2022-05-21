#include "CGFrameBuffer.h"
#include <stdlib.h> // for malloc
#include <string.h> // for memcpy
#include "CG.h"
#include "CGVector.h"
//------------------------------------------------------------------------------
// CGFRAMEBUFFER
//------------------------------------------------------------------------------
bool CGFrameBuffer::allocate(int width, int height)
{
	bool retval = colorBuffer.reserve(width,height);
	// also reserve a depth buffer
	retval = retval && depthBuffer.reserve(width, height);
	return retval;
}
//------------------------------------------------------------------------------
int CGFrameBuffer::getWidth() const
{
	return colorBuffer.getWidth();
}
//------------------------------------------------------------------------------
int CGFrameBuffer::getHeight() const
{
	return colorBuffer.getHeight();
}


//------------------------------------------------------------------------------
// CGFRAMEBUFFER::CGBUFFER4UB
//------------------------------------------------------------------------------
CGFrameBuffer::CGColorBuffer::CGColorBuffer()
{
	m_buffer_data = nullptr;
}
//------------------------------------------------------------------------------
CGFrameBuffer::CGColorBuffer::~CGColorBuffer()
{
	free(m_buffer_data);
	m_buffer_data = nullptr;
}
//------------------------------------------------------------------------------
bool CGFrameBuffer::CGColorBuffer::reserve(const int width, const int height)
{
	m_width = width;
	m_height = height;

	// allocate the memory for the buffer
	// U01 A1a)
    if(m_buffer_data = static_cast<unsigned char*>(malloc(4*width*height*sizeof(unsigned char)))) return true;
    return false;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::set_white(const CGVec2i& p)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	// U01 A1b)
    int buffer_pos = (p.y*m_width+p.x)*4;

    for(int i=0; i<4; i++){     // assign 255 to all 4 subpixels
        m_buffer_data[buffer_pos+i]=255;
    }
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::set(const CGVec2i &p, const CGVec4 &rgba)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	// U01 A1c)
    int buffer_pos = (p.y*m_width+p.x)*4;

    for(int i=0; i<4; i++){
        m_buffer_data[buffer_pos+i] = static_cast<unsigned char>(rgba[i]*255); // convert float number in [0,1] to valid color value in [0,255]
    }


}
//------------------------------------------------------------------------------
CGVec4 CGFrameBuffer::CGColorBuffer::get(const CGVec2i &p) const
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	CGVec4 rgba(0.0f);
    int buffer_pos = (p.y*m_width+p.x)*4;

    // U01 A1d)
    for(int i=0; i<4; i++){
        rgba[i] = m_buffer_data[buffer_pos+i]/255.0f;
    }

	return rgba;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::clear(const CGVec4& rgba)
{
	assert(m_buffer_data != nullptr);
	// U01 A1e)
    CGVec2i p;
    for(p.y=0; p.y < m_height; p.y++){
        for(p.x=0; p.x < m_width; p.x++){
            set(p, rgba);
        }
    }
}
//------------------------------------------------------------------------------
unsigned char* CGFrameBuffer::CGColorBuffer::getDataPointer() const
{
	return m_buffer_data;
}
//------------------------------------------------------------------------------
int CGFrameBuffer::CGColorBuffer::getWidth() const
{
	return m_width;
}
//------------------------------------------------------------------------------
int CGFrameBuffer::CGColorBuffer::getHeight() const
{
	return m_height;
}


//------------------------------------------------------------------------------
// CGFRAMEBUFFER::CGBUFFER1F
//------------------------------------------------------------------------------
CGFrameBuffer::CGDepthBuffer::CGDepthBuffer()
{
	m_buffer_data = nullptr;
}
//------------------------------------------------------------------------------
CGFrameBuffer::CGDepthBuffer::~CGDepthBuffer()
{
	free(m_buffer_data);
	m_buffer_data = nullptr;
}
//------------------------------------------------------------------------------
bool CGFrameBuffer::CGDepthBuffer::reserve(const int width,const int height)
{
	m_width = width;
	m_height = height;
	// U09 A1 a)
    if(m_buffer_data = static_cast<float*>(malloc(width * height * sizeof(float)))) return true;
	return false;
}
//------------------------------------------------------------------------------
float CGFrameBuffer::CGDepthBuffer::get(const CGVec2i &p) const
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);
	// U09 A1 a)
    int buffer_pos = (p.y * m_width + p.x);

    return m_buffer_data[buffer_pos];
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGDepthBuffer::set(const CGVec2i &p, const float z)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);
	// U09 A1 a)

    int buffer_pos = (p.y * m_width + p.x);

    m_buffer_data[buffer_pos] = z;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGDepthBuffer::clear()
{
	assert(m_buffer_data != nullptr);
	// U09 A1 a)

    for(int pos = 0; pos < m_height * m_width; pos++){
        m_buffer_data[pos] = 1.0;
    }
}
//------------------------------------------------------------------------------
float* CGFrameBuffer::CGDepthBuffer::getDataPointer() const
{
	return m_buffer_data;
}
//------------------------------------------------------------------------------
int CGFrameBuffer::CGDepthBuffer::getWidth() const
{
	return m_width;
}
//------------------------------------------------------------------------------
int CGFrameBuffer::CGDepthBuffer::getHeight() const
{
	return m_height;
}
//------------------------------------------------------------------------------
