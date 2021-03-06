// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// FancyKey.h
//
// Simple Cylinder mesh with coloured sides

#ifndef FANCYKEY_H
#define FANCYKEY_H

#include "Mesh.h"
#include "GameObject.h"
#include <vector>

using namespace std;

namespace T3D
{
class FancyKey : public GameObject
{
	public:
	FancyKey(
		T3DApplication *app, Material *color,
		int d,    // The density of the key head (outer and inner cylinder)
		float r1, // The radius of the holes in the key head
		float r2, // The outer radius of the key head (r1<r2)
		float offset, // The separation of the holes in the key head
		float depth,  // The (uniform) thickness of the key
		float stemlength,   // The length of the key stem
		float stemradius,   // The radius of the key stem
		vector<float> code  // An encoding of the key shape
	);


	virtual ~FancyKey(void);
};
}

#endif

