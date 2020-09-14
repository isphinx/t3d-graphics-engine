// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// Cylinder.h
//
// Simple Cylinder mesh with coloured sides

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Mesh.h"

namespace T3D
{
	class Cylinder : public Mesh
	{
	public:
		Cylinder(float radius, float height, int density);
		virtual ~Cylinder(void);
	};
}

#endif

