// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// Key2.h
//
// Simple Cylinder mesh with coloured sides

#ifndef KEY2_H
#define KEY2_H

#include "Mesh.h"
#include <vector>

using namespace std;

namespace T3D
{
	class Key2 : public Mesh
	{
	public:
		Key2(int	density,
			float r1,
			float r2,
			float offset, // The displacement of the hole in the key head
			float depth, // The (uniform) thickness of the key
			float seglength, // The length of each segment of the key stem
			float segwidth, // The (maximum) width of the key stem
			vector<float> code // The width % for each segment of the key
		);
		virtual ~Key2(void);
	};
}

#endif

