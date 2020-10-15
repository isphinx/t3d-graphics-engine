// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// case.cpp

#include "Case.h"

namespace T3D
{
	Case::Case()
	{
		float x = 1.0f;
		float y = 0.6f;
		float z = 2.5f;

		int numvex = 40;
		
		// Init vertex and index arrays
		initArrays(numvex,	// num vertices
			   0,		// num tris
			   numvex/4);		// num quads

		// Set vertices

		int pos=0;
		//front
		setUV(pos,16/1024.f,459/1024.f);
		setVertex(pos++,-x,-y,z);
		setUV(pos,274/1024.f,459/1024.0f);
		setVertex(pos++,x,-y,z);
		setUV(pos,274/1024.0f,338/1024.0f);
		setVertex(pos++,x,y,z);
		setUV(pos,16/1024.0f,338/1024.0f);
		setVertex(pos++,-x,y,z);

		setUV(pos,16/1024.0f,338/1024.0f);
		setVertex(pos++,-x,y,z);
		setUV(pos,274/1024.0f,338/1024.0f);
		setVertex(pos++,x,y,z);
		setUV(pos,182/1024.0f,211/1024.0f);
		setVertex(pos++,x/2,y*2,z);
		setUV(pos,107/1024.0f,211/1024.0f);
		setVertex(pos++,-x/2,y*2,z);

		//back
		setUV(pos,16/1024.0f,338/1024.0f);
		setVertex(pos++,-x,y,-z);
		setUV(pos,274/1024.0f,338/1024.0f);
		setVertex(pos++,x,y,-z);
		setUV(pos,274/1024.f,459/1024.0f);
		setVertex(pos++,x,-y,-z);
		setUV(pos,16/1024.f,459/1024.f);
		setVertex(pos++,-x,-y,-z);

		setUV(pos,107/1024.0f,211/1024.0f);
		setVertex(pos++,-x/2,y*2,-z);
		setUV(pos,182/1024.0f,211/1024.0f);
		setVertex(pos++,x/2,y*2,-z);
		setUV(pos,274/1024.0f,338/1024.0f);
		setVertex(pos++,x,y,-z);
		setUV(pos,16/1024.0f,338/1024.0f);
		setVertex(pos++,-x,y,-z);

		// top
		setUV(pos,385/1024.0f,630/1024.0f);
		setVertex(pos++,-x/2,y*2,z);
		setUV(pos,385/1024.0f,735/1024.0f);
		setVertex(pos++,x/2,y*2,z);
		setUV(pos,1,735/1024.0f);
		setVertex(pos++,x/2,y*2,-z);
		setUV(pos,1,630/1024.0f);
		setVertex(pos++,-x/2,y*2,-z);

		// bottom
		setUV(pos,0,1);
		setVertex(pos++,-x,-y,-z);
		setUV(pos,0/1024.0f,744/1024.0f);
		setVertex(pos++,x,-y,-z);
		setUV(pos,640/1024.0f,744/1024.0f);
		setVertex(pos++,x,-y,z);
		setUV(pos,640/1024.0f,1);
		setVertex(pos++,-x,-y,z);

		// right
		setUV(pos,0,40/1024.0f);
		setVertex(pos++,x,y,z);
		setUV(pos,0,160/1024.0f);
		setVertex(pos++,x,-y,z);
		setUV(pos,640/1024.0f,160/1024.0f);
		setVertex(pos++,x,-y,-z);
		setUV(pos,640/1024.0f,40/1024.0f);
		setVertex(pos++,x,y,-z);

		setUV(pos,0,478/1024.0f);
		setVertex(pos++,x/2,y*2,z);
		setUV(pos,0,630/1024.0f);
		setVertex(pos++,x,y,z);
		setUV(pos,640/1024.0f,630/1024.0f);
		setVertex(pos++,x,y,-z);
		setUV(pos,640/1024.0f,478/1024.0f);
		setVertex(pos++,x/2,y*2,-z);

		// left
		setUV(pos,385/1024.0f,338/1024.0f);
		setVertex(pos++,-x,y,-z);
		setUV(pos,385/1024.0f,459/1024.0f);
		setVertex(pos++,-x,-y,-z);
		setUV(pos,1,459/1024.0f);
		setVertex(pos++,-x,-y,z);
		setUV(pos,1,338/1024.0f);
		setVertex(pos++,-x,y,z);

		setUV(pos,385/1024.0f,459/1024.0f);
		setVertex(pos++,-x/2,y*2,-z);
		setUV(pos,385/1024.0f,338/1024.0f);
		setVertex(pos++,-x,y,-z);
		setUV(pos,1,338/1024.0f);
		setVertex(pos++,-x,y,z);
		setUV(pos,1,459/1024.0f);
		setVertex(pos++,-x/2,y*2,z);

		// pos = 0;
		// setUV(pos++,0,0);
		// setUV(pos++,1,0);
		// setUV(pos++,1,1);
		// setUV(pos++,0,1);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);
		// setUV(pos++,0,0);

		// Build quads
		pos = 0;
		for (int i = 0; i < numvex / 4; i++) {
			setFace(i,i*4,i*4+1,i*4+2,i*4+3);
		}

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();	

		// // Setup other arrays		
		// pos = 0;
		// //front
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		// }
		// //back
		// for (int i=0; i<4; i++){
		// 	colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		// }

		// //uvs
		// pos = 0;
		// for (int f = 0; f<2; f++){
		// 	uvs[pos++] = 0; uvs[pos++] = 0; 
		// 	uvs[pos++] = 0; uvs[pos++] = 1; 
		// 	uvs[pos++] = 1; uvs[pos++] = 1; 
		// 	uvs[pos++] = 1; uvs[pos++] = 0; 
		// }
	}


	Case::~Case(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
