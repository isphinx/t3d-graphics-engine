// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// cube.h
//
// Simple cube mesh with coloured sides

#ifndef PYRAMID_H
#define PYRAMID_H

#include "Mesh.h"

namespace T3D
{
	class Pyramid : public Mesh
	{
	public:
		Pyramid(float size);
		virtual ~Pyramid(void);
	};
}

#endif

