#pragma once
#include "CGMatrix.h"
#include "CGVector.h"
#include "CGTexture.h"
#include "CG.h"

//---------------------------------------------------------------------------
/// Vertex attribute container (vertex processing inputs).
struct CGVertexAttributes
{
	CGVec4 position;
	CGVec4 normal;
	CGVec4 color;
	CGVec4 texcoord;
};

/// Vertex varying container (vertex processing outputs).
struct CGVaryings
{
	CGVec4 position;
	CGVec4 normal;
	CGVec4 color;
	CGVec4 texcoord;
	CGVec4 position_es;
};

/// Fragment data container.
struct CGFragmentData
{
	CGVec2i coordinates;   /// Fragment specific framebuffer coordinate
	CGVaryings varyings;   /// Varyings as copied from vertex or interpolated.

	void set(const CGVaryings& A)
	{
		varyings = A;
	}

	void set(const CGVaryings& A, const CGVaryings& B, float ratio)
	{
		const float ir = 1.0f - ratio;
		const float r = ratio;
		varyings.position = ir * A.position + r * B.position;
		varyings.color = ir * A.color + r * B.color;
		varyings.normal = ir * A.normal + r * B.normal;
		varyings.texcoord = ir * A.texcoord + r * B.texcoord;
		varyings.position_es = ir * A.position_es + r * B.position_es;
	}

	void set(const CGVaryings& A, const CGVaryings& B, const CGVaryings& C, float alpha, float beta, float gamma)
	{
		// Übung 05, Aufgabe 2a).
		// Hinweis: Beachten Sie, dass alle Attribute des Varyings interpoliert werden müssen:
		// - position
		// - color
		// - normal
		// - texcoord
		// - position_es
	}
};

