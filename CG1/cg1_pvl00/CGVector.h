#pragma once
#include <cassert>
#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
/// Simple vector container, four elements.
struct CGVec4
{
	float x,y,z,w;
	const float & operator[] (const unsigned int i) const
	{
		// This is a static_assert. It is evaluated during compile time
		// so it does not cost anything during runtime.
		// This asserts, that x,y,z,w are densely packed
		// -> there is no padding in between.
		static_assert ((offsetof(CGVec4,w)-offsetof(CGVec4,x))
		               == sizeof(float)*3,
		               "Elements of CGVec4 are not densely packed :(");
		assert(i<4);
		return (&x)[i];
	}
	float & operator[] (const unsigned int i)
	{
		static_assert ((offsetof(CGVec4,w)-offsetof(CGVec4,x))
		               == sizeof(float)*3,
		               "Elements of CGVec4 are not densely packed :(");
		assert(i<4);
		return (&x)[i];
	}
	void set(const float a, const float b, const float c, const float d)
	{
		x=a;
		y=b;
		z=c;
		w=d;
	}
	void set(const CGVec4& vec)
	{
		for(unsigned int i = 0; i< 4;i++)
			(&x)[i] = vec[i];
	}
	void print(std::string prefix = "") const
	{
		if(!prefix.empty())
			prefix += ":";
		for (unsigned int i = 0 ; i< 4;i++) {
			std::cout<<prefix<<" ("<<(*(this))[i]<<")\n";
		}
	}

	/// special constructors
	CGVec4()
	{
		// empty constructor, leave elements uninitialized
		// use this if you are going to set/overwrite all elements
		// anyways
	}
	CGVec4(const float v)
	{
		set(v,v,v,v);
	}
	CGVec4(const float x,
	       const float y,
	       const float z,
	       const float w = 1.0f)
	{
		set(x,y,z,w);
	}
	CGVec4(const CGVec4& vec)
	{
		set(vec);
	}

	/// mathematic operators
	CGVec4 operator+(const CGVec4 &v) const
	{
		return CGVec4(x+v.x, y+v.y,z+v.z,w+v.w);
	}
	CGVec4 operator-(const CGVec4 &v) const
	{
		return CGVec4(x-v.x, y-v.y,z-v.z,w-v.w);
	}
	CGVec4 operator*(const CGVec4 &v) const
	{
		return CGVec4(x*v.x, y*v.y,z*v.z,w*v.w);
	}
	CGVec4 operator*(const float s) const
	{
		return CGVec4(x*s,y*s,z*s,w*s);
	}
	CGVec4 operator/(const float s) const
	{
		return *this * (1.0f/s);
	}

	CGVec4& operator+=(const CGVec4 &v)
	{
		for(unsigned int i = 0; i< 4;i++)
			(*this)[i] += v[i];
		return  *this;
	}
	CGVec4& operator-=(const CGVec4 &v)
	{
		for(unsigned int i = 0; i< 4;i++)
			(*this)[i] -= v[i];
		return  *this;
	}
	CGVec4& operator*=(const CGVec4 &v)
	{
		for(unsigned int i = 0; i< 4;i++)
			(*this)[i] *= v[i];
		return  *this;
	}
	CGVec4& operator*=(const float s)
	{
		for(unsigned int i = 0; i< 4;i++)
			(*this)[i] *= s;
		return  *this;
	}
	CGVec4& operator/=(const float s)
	{
		for(unsigned int i = 0; i< 4;i++)
			(*this)[i] /=s;
		return  *this;
	}
};

inline CGVec4 operator*(float s, const CGVec4 &v)
{
	return v * s;
}

inline float dot(const CGVec4& a, const CGVec4& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}
