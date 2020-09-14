// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// cube.h
//
// Simple cube mesh with coloured sides

#ifndef CUBE2_H
#define CUBE2_H

#include "Mesh.h"

namespace T3D
{
	class Cube2 : public Mesh
	{
	public:
		Cube2(float x, float y, float z);
		virtual ~Cube2(void);
	};
}

#endif

