// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// Cylinder.cpp
//
// Simple Cylinder mesh with coloured sides
// Note that faces are triangles only and that normals are repeated for each vertex
// This allows use of gl array pointers

#include "Math.h"
#include "Cylinder.h"

namespace T3D
{
	Cylinder::Cylinder(float radius, float height, int density)
	{
		// Set vertices
		int d = density;
		float r = radius;
		float h = height;

		initArrays(d * 4 + 2, 2 * d, d);

		int topsidestart = 0;
		int botsidestart = d;
		int topcapstart = 2 * d;
		int botcapstart = 3 * d;
		int topcentre = 4 * d;
		int botcentre = 4 * d + 1;

		float dTheta = Math::TWO_PI / d;
		for (int i = 0; i < d; i++) {
			float theta = i * dTheta;
			float x = r * cos(theta);
			float z = r * sin(theta);

			// top vertex
			setVertex(topsidestart+i, x, h, z);
			// bottom vertex
			setVertex(botsidestart+i, x, -h, z);
			// top cap
			setVertex(topcapstart+i, x, h, z);
			// bottom cap
			setVertex(botcapstart+i, x, -h, z);
		}
		setVertex(topcentre, 0, h, 0);
		setVertex(botcentre, 0, -h, 0);

		for (int i = 0; i < d; i++) {
			setFace(i, // face id
					topsidestart + i,
					topsidestart + (i + 1) % d,
					botsidestart + (i + 1) % d,
					botsidestart + i
					);
			setFace(i,
					topcentre,
					topsidestart + ((i + 1) % d),
					topsidestart + i
					);
			setFace(d + i,
					botcentre,
					botsidestart + i,
					botsidestart + ((i + 1) % d)
					);

		}


		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();	

		// Setup other arrays		
		int pos = 0;
		// side
		for (int i=0; i<d*4+2; i++){
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}

		// //uvs
		// pos = 0;
		// for (int f = 0; f<6; f++){
		// 	uvs[pos++] = 0; uvs[pos++] = 0; 
		// 	uvs[pos++] = 0; uvs[pos++] = 1; 
		// 	uvs[pos++] = 1; uvs[pos++] = 1; 
		// 	uvs[pos++] = 1; uvs[pos++] = 0; 
		// }
	}


	Cylinder::~Cylinder(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
