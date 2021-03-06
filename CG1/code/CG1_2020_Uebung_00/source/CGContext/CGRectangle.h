#pragma once

#include "CGVector.h"
class CGRectangle
{
	CGVec2i m_bottom_left;
	CGVec2i m_top_right;
	int m_width;
	int m_height;

public:
	CGRectangle(int x, int y, int w, int h)
		:m_bottom_left(x, y), m_top_right(x + w - 1, y + h - 1), m_width(w), m_height(h) {}

	void set(int x, int y, int w, int h)
	{
		m_bottom_left = { x,y };
		m_top_right = { x + w - 1,y + h - 1 };
		m_width = w;
		m_height = h;
	}
	// Returns the top right pixel coordinate that is _inside_ the CGRectangle
	const CGVec2i& topRight()const
	{
		return m_top_right;
	}

	CGVec2i topRight() {
		return m_top_right;
	}

	const CGVec2i& bottomLeft()const
	{
		return m_bottom_left;
	}

	CGVec2i& bottomLeft()
	{
		return m_bottom_left;
	}

	int width() const
	{
		return m_width;
	}

	int height() const
	{
		return m_height;
	}


	/// returns true if the point p is inside this rectangle
	bool isInside(const CGVec2i& p) const
	{
		// U06 A3b)
		//assert(false && "Not implemented yet!");
		int x_min = m_bottom_left.x;
		int y_min = m_bottom_left.y;
		int x_max = m_top_right.x;
		int y_max = m_top_right.y;
		if (p.x < x_min || p.x > x_max || p.y < y_min || p.y > y_max) return false;
		return true;
	}
};
