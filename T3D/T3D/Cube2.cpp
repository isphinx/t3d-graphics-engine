// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// cube2.cpp
//
// Simple cube mesh with coloured sides
// Note that faces are triangles only and that normals are repeated for each vertex
// This allows use of gl array pointers

#include "Cube2.h"

namespace T3D
{
	Cube2::Cube2(float size)
	{
		// Init vertex and index arrays
		initArrays(8,	// num vertices
			       0,		// num tris
			       6);		// num quads

		// Set vertices

		int pos=0;
		//front
		setVertex(pos++,-size,-size,-size);
		setVertex(pos++,size,-size,-size);
		setVertex(pos++,size,size,-size);
		setVertex(pos++,-size,size,-size);
		// //back
		setVertex(pos++,-size,-size,size);
		setVertex(pos++,size,-size,size);
		setVertex(pos++,size,size,size);
		setVertex(pos++,-size,size,size);

		// Build quads
		pos = 0;
		//front
		setFace(pos++,3,2,1,0);
		//back
		setFace(pos++,4,5,6,7);
		//left
		// setFace(pos++,11,10,9,8);
		setFace(pos++,4,7,3,0);
		//right
		setFace(pos++,6,5,1,2);
		// setFace(pos++,12,13,14,15);
		//bottom
		setFace(pos++,0,1,5,4);
		// setFace(pos++,19,18,17,16);
		//top
		setFace(pos++,7,6,2,3);
		// setFace(pos++,20,21,22,23);

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();	

		// Setup other arrays		
		pos = 0;
		//front
		for (int i=0; i<4; i++){
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//back
		for (int i=0; i<4; i++){
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}

		//uvs
		pos = 0;
		for (int f = 0; f<2; f++){
			uvs[pos++] = 0; uvs[pos++] = 0; 
			uvs[pos++] = 0; uvs[pos++] = 1; 
			uvs[pos++] = 1; uvs[pos++] = 1; 
			uvs[pos++] = 1; uvs[pos++] = 0; 
		}
	}


	Cube2::~Cube2(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
