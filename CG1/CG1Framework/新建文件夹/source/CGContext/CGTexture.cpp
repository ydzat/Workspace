/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
#include "CGTexture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CGMath.h"

//------------------------------------------------------------------------------
// CGTEXTURE2D
//------------------------------------------------------------------------------
CGTexture2D::CGTexture2D()
{
	reset();
}
//------------------------------------------------------------------------------
CGTexture2D::~CGTexture2D()
{
	free(m_data);
	m_data = nullptr;
}
//------------------------------------------------------------------------------
void CGTexture2D::reset()
{
	m_width = m_height = 0;
	filterMode = CG_NEAREST;
	wrapMode = CG_CLAMP;
	m_data = nullptr;
}
//------------------------------------------------------------------------------
void CGTexture2D::allocate(int width, int height, const unsigned char* data4ub)
{
	this->m_width = width;
	this->m_height = height;
	m_data = (unsigned char*)realloc(m_data, (size_t)(width * height) * 4);
	memcpy(m_data, data4ub, (size_t)(width * height) * 4);
}

//------------------------------------------------------------------------------
CGVec4 CGTexture2D::fetchTexel(int x, int y) const
{
	assert(m_data != nullptr);
	// U11 A2a)
	if (wrapMode == CG_CLAMP) {
		if (x >= m_width) {
			x = m_width - 1;
		}
		else if (x < 0) {
			x = 0;
		}
		if (y >= m_height) {
			y = m_height - 1;
		}
		else if (y < 0) {
			y = 0;
		}
	}
	else {
		while (x < 0) x += m_width; while (x >= m_width) x -= m_width;
		while (y < 0) y += m_height; while (y >= m_height) y -= m_height;
	}
	unsigned int index = (y * m_width + x) * 4;
	CGVec4 sam(m_data[index + 0], m_data[index + 1], m_data[index + 2], m_data[index + 3]);
	sam /= 255.0f;
	return sam;
}
//------------------------------------------------------------------------------
CGVec4 CGTexture2D::sample(const CGVec4& texcoord) const
{

	float s = texcoord.x * m_width;
	float t = texcoord.y * m_height;

	CGVec4* sample = new CGVec4();

	if (filterMode == CG_NEAREST) {
		*sample = fetchTexel(static_cast<int>(s), static_cast<int>(t));
	}

	else {
		int sa = floor(s - 0.5);
		int ta = floor(t - 0.5);

		float alpha = s - 0.5 - sa;
		float beta = t - 0.5 - ta;

		CGVec4 A = fetchTexel(sa, ta);
		CGVec4 B = fetchTexel(sa + 1, ta);
		CGVec4 C = fetchTexel(sa, ta + 1);
		CGVec4 D = fetchTexel(sa + 1, ta + 1);

		*sample = (1 - beta) * ((1 - alpha) * A + alpha * B) + beta * ((1 - alpha) * C + alpha * D);
	}

	return *sample;
}
//------------------------------------------------------------------------------
