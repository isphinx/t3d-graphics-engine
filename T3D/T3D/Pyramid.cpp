// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// cube.cpp
//
// Simple cube mesh with coloured sides
// Note that faces are triangles only and that normals are repeated for each vertex
// This allows use of gl array pointers

#include "Pyramid.h"

namespace T3D
{
	Pyramid::Pyramid(float size)
	{
		// Init vertex and index arrays
		initArrays(4 + 1,	// num vertices
			       4,		// num tris
			       1);		// num quads

		// Set vertices

		int pos=0;
		//front
		setVertex(pos++,-size,-size,-size);
		setVertex(pos++,size,-size,-size);
		setVertex(pos++,size,size,-size);
		setVertex(pos++,-size,size,-size);
		//back
		setVertex(pos++,0,0,size);

		// Build quads
		//front
		setFace(0,3,2,1,0);
		//back
		pos = 0;
		setFace(pos++,4,0,1);
		setFace(pos++,4,1,2);
		setFace(pos++,4,2,3);
		setFace(pos++,4,3,0);

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();	

		// Setup other arrays		
		pos = 0;
		//front
		// for (int i=0; i<5; i++){
		// 	colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		// }
		// //back
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		// }
		// //left
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		// }
		// //right
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		// }
		// //bottom
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		// }
		// //top
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		// }	

		//uvs
		// pos = 0;
		// for (int f = 0; f<5; f++){
		// 	uvs[pos++] = 0; uvs[pos++] = 0; 
		// 	uvs[pos++] = 0; uvs[pos++] = 1; 
		// 	uvs[pos++] = 1; uvs[pos++] = 1; 
		// 	uvs[pos++] = 1; uvs[pos++] = 0; 
		// }
	}


	Pyramid::~Pyramid(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
