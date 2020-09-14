// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// FancyKeyBody.h
//
// Simple Cylinder mesh with coloured sides

#ifndef KEY2_H
#define KEY2_H

#include "Mesh.h"
#include <vector>

using namespace std;

namespace T3D
{
class FancyKeyBody : public Mesh
{
	public:
	FancyKeyBody(int	density,
		float r1, // The radius of the holes in the key head
		float r2, // The outer radius of the key head (r1<r2)
		float offset, // The separation of the holes in the key head
		float depth,  // The (uniform) thickness of the key
		float stemlength,   // The length of the key stem
		float stemradius   // The radius of the key stem
	);

	virtual ~FancyKeyBody(void);
};
}

#endif

