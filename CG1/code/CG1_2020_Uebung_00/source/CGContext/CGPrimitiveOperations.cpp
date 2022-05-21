﻿#include "CGPrimitiveOperations.h"
#include "CGPrimClipper.h"
#include "CGContext.h"
#include "CGRasterizer.h"

// This method is usded to silence the unused, parameter warnings!
template<typename ... Args> void unused(const Args& ...) { }

//------------------------------------------------------------------------------
void CGPrimitiveOperations::invoke_line_rasterization(const CGVaryings& a, const CGVaryings& b)
{
	if (m_context.bresenhamIsEnabled)
		m_bresenham_line_rasterizer.rasterize(a, b);
	else
		m_stupid_line_rasterizer.rasterize(a, b);
}

//------------------------------------------------------------------------------
bool CGPrimitiveOperations::backface_culling(const CGVaryings& a, const CGVaryings& b, const CGVaryings& c)
{
	unused(a, b, c);
	return true;
}

//------------------------------------------------------------------------------
void CGPrimitiveOperations::invoke_triangle_rasterization(const CGVaryings& a, const CGVaryings& b, const CGVaryings& c)
{
	// TODO: Übung 04, Aufgabe 2a
	// Hinweis: Mit den drei Varyings, welche der Methode Übergeben werden, können wir ein einfaches Gitternetz eines 
	//          Dreiecks zeichnen. Dazu müssen wir lediglich eine Linie zwischen den einzelnen Punkten zeichnen. Das
	//          zeichnen der Linien Übernimmt die Methode `invoke_line_rasterization`.
	/*注意：通过传递给方法的三个Varying，我们可以绘制一个简单的三角形网格。
	我们要做的就是在每个点之间画一条线。
	线条的绘制是通过“ invoke_line_rasterization”方法完成的。*/

	if (m_context.polygonMode == CG_LINE) {
		invoke_line_rasterization(a, b);
		invoke_line_rasterization(b, c);
		invoke_line_rasterization(c, a);
	}
	else { // m_context.polygonMode == CG_FILL
		m_triangle_rasterizer.rasterize(a, b, c);
	}

}

//------------------------------------------------------------------------------
CGPrimitiveOperations::CGPrimitiveOperations(CGContext& context, CGPointRasterizer& point_raster, CGLineRasterizer& line_raster, CGLineRasterizer& bresenham_raster, CGTriangleRasterizer& tri_raster) :
	m_context(context), m_point_rasterizer(point_raster), m_stupid_line_rasterizer(line_raster), m_bresenham_line_rasterizer(bresenham_raster), m_triangle_rasterizer(tri_raster)
{
	m_num_vertices = 0;

	setPrimitiveMode(CG_POINTS);
}

//------------------------------------------------------------------------------
void CGPrimitiveOperations::setPrimitiveMode(CGPrimitiveType prim_mode)
{
	m_primitive_mode = prim_mode;

	switch (m_primitive_mode)
	{
	case CG_POINTS: m_required_vertices = 1; break;
	case CG_LINES: m_required_vertices = 2; break;
	case CG_TRIANGLES: m_required_vertices = 3; break;
	}
}

//------------------------------------------------------------------------------
void CGPrimitiveOperations::pushVertex(const CGVaryings& v)
{
	// primitive assembly
	m_vertex_varyings[m_num_vertices++] = v;

	if (m_num_vertices < m_required_vertices)
		return;

	perspective_divide_primitives();
	viewport_transform_primitives();

	// We might have to rasterize more than one primitive.
	for (unsigned int i = 0; i < m_num_vertices; i += m_required_vertices)
	{

		switch (m_primitive_mode)
		{
		case CG_POINTS: m_point_rasterizer.rasterize(m_vertex_varyings[i]); break;
		case CG_LINES: invoke_line_rasterization(m_vertex_varyings[i], m_vertex_varyings[i + 1]); break;
		case CG_TRIANGLES: invoke_triangle_rasterization(m_vertex_varyings[i], m_vertex_varyings[i + 1], m_vertex_varyings[i + 2]); break;
		}
	}

	// Purge vertex list.
	m_num_vertices = 0;
}

//------------------------------------------------------------------------------
void CGPrimitiveOperations::clip_primitive()
{
	int newPrimCount;

	switch (m_primitive_mode)
	{
	case CG_POINTS:
		m_num_vertices = CGPrimClipper::clip_point(m_vertex_varyings, (int)m_num_vertices); break;
	case CG_LINES:
		m_num_vertices = CGPrimClipper::clip_line(m_vertex_varyings, (int)m_num_vertices); break;
	case CG_TRIANGLES:
		// Clipped vertices need to be re-assembled into triangles
		newPrimCount = (int)CGPrimClipper::clip_poly(m_vertex_varyings, (int)m_num_vertices) - 2;
		m_num_vertices = 0; //reset the pipeline

		for (int i = 0; i < newPrimCount; ++i)
		{
			//as triangle fan
			m_vertex_varyings[m_num_vertices++] = CGPrimClipper::out_buf()[0];
			m_vertex_varyings[m_num_vertices++] = CGPrimClipper::out_buf()[i + 1];
			m_vertex_varyings[m_num_vertices++] = CGPrimClipper::out_buf()[i + 2];
		}

		break;
	}
}
//------------------------------------------------------------------------------
void CGPrimitiveOperations::perspective_divide_primitives()
{
	//for (unsigned int i = 0; i < m_num_vertices; i++)
	//{
	//}
}
//------------------------------------------------------------------------------
void CGPrimitiveOperations::viewport_transform_primitives()
{
	for (unsigned int i = 0; i < m_num_vertices; i++)
	{
		CGVec4& pos = m_vertex_varyings[i].position;

		pos.x = m_context.viewport.bottomLeft().x + 0.5 * (pos.x + 1.0) * m_context.viewport.width();
		pos.y = m_context.viewport.bottomLeft().y + 0.5 * (pos.y + 1.0) * m_context.viewport.height();
		pos.z = (pos.z + 1.0) / 2.0;

	}
}
