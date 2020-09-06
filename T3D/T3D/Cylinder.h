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
		Cylinder(int density, float radius, float height);
		virtual ~Cylinder(void);
	};
}

#endif

