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
	// Hinweise:
	//   - m_buffer_data ist eine Membervariable; auf sie kann auch in anderen Methoden der Klasse
	//     CGColorBuffer zugegriffen werden.
	//   - malloc nimmt einen Parameter entgegen: die Anzahl der zu reservierenden Bytes
	//   - malloc gibt einen Zeiger auf den allozierten Speicher zur?ck (als void*, m_buffer_data
	//     ist aber vom Typ unsigned char*)
	// m_buffer_data = ...

	return m_buffer_data != nullptr;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::set_white(const CGVec2i& p)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	// U01 A1b)
	// Hinweise:
	//   - Gebrauchen Sie Zeigerarithmetik, um die Adresse des Pixels bei (p.x, p.y) zu berechnen.
	//   - m_buffer_data zeigt auf den Anfang des Speicherbereichs, der in CGColorBuffer::reserve
	//     reserviert wurde.
	// ...
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::set(const CGVec2i &p, const CGVec4 &rgba)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	// U01 A1c)
	// Hinweise:
	//   - Die Werte der einzelnen Kan?le des Parameters rgba sind vom Typ float und liegen im
	//     Intervall [0.0, 1.0]
	//   - Welcher Wertebereich ist f?r eine vorzeichenfreie 8-Bit-Ganzzahl (unsigned char) zul?ssig?
	//     Auf diesen Bereich muss das Intervall [0.0, 1.0] der Eingabewerte abgebildet werden.
	// ...
}
//------------------------------------------------------------------------------
CGVec4 CGFrameBuffer::CGColorBuffer::get(const CGVec2i &p) const
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	CGVec4 rgba;

	// U01 A1d)
	// Hinweise:
	//   - F?r diese Operation muss die in CGColorBuffer::set vorgenommene Umrechnung invertiert
	//     werden.
	// ...

	return rgba;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::clear(const CGVec4& rgba)
{
	assert(m_buffer_data != nullptr);

	// U01 A1e)
	// Hinweise:
	//   - Rechnen Sie zun?chst die Eingabefarbe analog zu CGColorBuffer::set um und kopieren Sie
	//     die resultierenden Werte dann pro Pixel einmal in den Color Buffer.
	// ...
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
	// ...
	return true;
}
//------------------------------------------------------------------------------
float CGFrameBuffer::CGDepthBuffer::get(const CGVec2i &p) const
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);
	// U09 A1 a)
	// ...

	return 0.0f;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGDepthBuffer::set(const CGVec2i &p, const float z)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);
	// U09 A1 a)
	// ...

}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGDepthBuffer::clear()
{
	assert(m_buffer_data != nullptr);
	// U09 A1 a)
	// ...
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
