// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// FancyKey.cpp

#include "Math.h"
#include "FancyKey.h"


namespace T3D
{
	FancyKey::FancyKey(int density, float r1, float r2, float offset,
			 float depth, float seglength, float segwidth,
			 vector<float> code)
	{
		// Set vertices
		int d = density;
		float h = depth/2;
		int numJoint = d / 10;
		int numVertex = d * 4 + code.size() * 4;
		int numTri = numJoint * 4;
		int numSqua = d * 4 + (code.size() - 1) * 4 + 1 + 2;

		initArrays(numVertex, numTri, numSqua);

		int outtopstart = 0;
		int outbotstart = d;
		int intopstart = d * 2;
		int inbotstart = d * 3;
		int codestart = d * 4;

		float dTheta = Math::TWO_PI / d;
		for (int i = 0; i < d; i++) {
			float theta = i * dTheta;
			float outsidex = r2 * sin(theta);
			float outsidez = r2 * cos(theta) - r2;
			float insidex = r1 * sin(theta);
			float insidez = r1 * cos(theta) - r2 - offset;

			// top vertex
			setVertex(outtopstart+i, outsidex, h, outsidez);
			// bottom vertex
			setVertex(outbotstart+i, outsidex, -h, outsidez);
			// top cap
			setVertex(intopstart+i, insidex, h, insidez);
			// bottom cap
			setVertex(inbotstart+i, insidex, -h, insidez);
		}

		for(int i = 0; i < code.size(); i++) {
			setVertex(codestart + i * 4 + 0, segwidth * code[i] - segwidth/2, h,  i * seglength);
			setVertex(codestart + i * 4 + 1, segwidth * code[i] - segwidth/2, -h,  i * seglength);
			setVertex(codestart + i * 4 + 2, -segwidth/2, -h, i * seglength);
			setVertex(codestart + i * 4 + 3, -segwidth/2, h, i * seglength);
		}

		// hollow circle
		for (int i = 0; i < d; i++) {
			setFace(i, // face id
					outtopstart + i,
					outtopstart + (i + 1) % d,
					outbotstart + (i + 1) % d,
					outbotstart + i
					);
			setFace(d + i,
					inbotstart + i,
					inbotstart + (i + 1) % d,
					intopstart + (i + 1) % d,
					intopstart + i
					);
			setFace(d*2+i, // face id
					intopstart + i,
					intopstart + (i + 1) % d,
					outtopstart + (i + 1) % d,
					outtopstart + i
					);
			setFace(d*3+i, // face id
					outbotstart + i,
					outbotstart + (i + 1) % d,
					inbotstart + (i + 1) % d,
					inbotstart + i
					);

		}

		// code faces
		int pos = codestart;
		for(int i = 0; i < code.size() - 1; i++) {
			setFace(pos++, //codestart + i * 4,
					codestart + i * 4 + 4,
					codestart + i * 4 + 7,
					codestart + i * 4 + 3,
					codestart + i * 4
					);
			setFace(pos++, //codestart + i * 4 + 1,
					codestart + i * 4 + 1,
					codestart + i * 4 + 2,
					codestart + i * 4 + 6,
					codestart + i * 4 + 5
					);
			setFace(pos++, //codestart + i * 4 + 2,
					codestart + i * 4 + 2,
					codestart + i * 4 + 3,
					codestart + i * 4 + 7,
					codestart + i * 4 + 6
					);
			setFace(pos++, //codestart + i * 4 + 3,
					codestart + i * 4 + 5,
					codestart + i * 4 + 4,
					codestart + i * 4 + 0,
					codestart + i * 4 + 1
					);
		}
		setFace(pos++, //numSqua - 1,
				codestart + code.size() * 4 - 4 + 0,
				codestart + code.size() * 4 - 4 + 1,
				codestart + code.size() * 4 - 4 + 2,
				codestart + code.size() * 4 - 4 + 3
				);

		setFace(pos++,
				outtopstart + numJoint,
				outbotstart + numJoint,
				codestart + 1,
				codestart + 0
				);
		setFace(pos++,
				codestart + 3,
				codestart + 2,
				outbotstart + d - numJoint,
				outtopstart + d - numJoint
				);

		pos = 0;
		for(int i = 0; i < numJoint; i++) {
			setFace(pos++, //numSqua - 1,
					outtopstart + i,
					outtopstart + i + 1,
					codestart
					);
			setFace(pos++,
					codestart + 3,
					outtopstart + (d - i - 1) % d,
					outtopstart + (d - i) % d
					);
			setFace(pos++, //numSqua - 1,
					codestart + 1,
					outbotstart + i + 1,
					outbotstart + i
					);
			setFace(pos++,
					outbotstart + (d - i) % d,
					outbotstart + (d - i - 1) % d,
					codestart + 2
					);
		}

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();	

		// Setup other arrays		
		pos = 0;
		// side
		for (int i=0; i < numVertex; i++){
			colors[pos++] = 1; colors[pos++] = 1; colors[pos++] = 1; colors[pos++] = 1;
		}
	}


	FancyKey::~FancyKey(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
