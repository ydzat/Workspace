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
	//   - malloc gibt einen Zeiger auf den allozierten Speicher zuruek (als void*, m_buffer_data
	//     ist aber vom Typ unsigned char*)
	// m_buffer_data = ...
	
	//为缓冲区分配内存

	// U01 A1a）
	//提示：
	//-m_buffer_data是成员变量； 它也可以在该类的其他方法中使用
	//可以访问CGColorBuffer。
	//-malloc使用一个参数：要保留的字节数
	//-malloc返回指向已分配内存点k的指针（如void *，m_buffer_data
	//但类型为unsigned char *）
	// m_buffer_data = ...
	
	if (m_buffer_data = static_cast<unsigned char*>(malloc(4 * width * height * sizeof(unsigned char)))) 
		return true;
	return false;

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

	int buffer_pos = (p.y * m_width + p.x) * 4;

	for (int i = 0; i < 4; i++) {
		m_buffer_data[buffer_pos + i] = 255;
	}

}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::set(const CGVec2i &p, const CGVec4 &rgba)
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	// U01 A1c)
	// Hinweise:
	//   - Die Werte der einzelnen Kan鋖e des Parameters rgba sind vom Typ float und liegen im
	//     Intervall [0.0, 1.0]
	//   - Welcher Wertebereich ist f黵 eine vorzeichenfreie 8-Bit-Ganzzahl (unsigned char) zul鋝sig?
	//     Auf diesen Bereich muss das Intervall [0.0, 1.0] der Eingabewerte abgebildet werden.
	// ...

	int buffer_pos = (p.y * m_width + p.x) * 4;

	m_buffer_data[buffer_pos] = static_cast<unsigned char>(rgba.x*255);
	m_buffer_data[buffer_pos + 1] = static_cast<unsigned char>(rgba.y*255);
	m_buffer_data[buffer_pos + 2] = static_cast<unsigned char>(rgba.z*255);
	m_buffer_data[buffer_pos + 3] = static_cast<unsigned char>(rgba.w*255);

}
//------------------------------------------------------------------------------
CGVec4 CGFrameBuffer::CGColorBuffer::get(const CGVec2i &p) const
{
	assert(m_buffer_data != nullptr);
	assert(p.x < m_width && p.y < m_height && p.x >= 0 && p.y >= 0);

	CGVec4 rgba(0.0f);
	int buffer_pos = (p.y * m_width + p.x) * 4;

	// U01 A1d)
	for (int i = 0; i < 4; i++) {
		rgba[i] = m_buffer_data[buffer_pos + i] / 255.0f;
	}

	return rgba;
}
//------------------------------------------------------------------------------
void CGFrameBuffer::CGColorBuffer::clear(const CGVec4& rgba)
{
	assert(m_buffer_data != nullptr);

	// U01 A1e)
	// Hinweise:
	//   - Rechnen Sie zun鋍hst die Eingabefarbe analog zu CGColorBuffer::set um und kopieren Sie
	//     die resultierenden Werte dann pro Pixel einmal in den Color Buffer.
	// ...
	CGVec2i p;
	for (p.y = 0; p.y < m_height; p.y++) {
		for (p.x = 0; p.x < m_width; p.x++) {
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
