// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// FancyKeyBody.cpp

#include "Math.h"
#include "FancyKeyBody.h"


namespace T3D
{
	FancyKeyBody::FancyKeyBody(int	density,
							   float r1, float r2,
							   float offset, float depth,
							   float stemlength, float stemradius)
	{
		// Set vertices
		int d = density;
		float h = depth/2;

		int numVertex = d * 4 + d * 2 + d * 4 + 2;
		int numTri = d * 2;
		int numSqua = d * 4 + d + d*3;

		initArrays(numVertex, numTri, numSqua);

		int outtopstart = 0;
		int outbotstart = d;
		int intopstart = d * 2;
		int inbotstart = d * 3;
		float stemtopstart = d * 4;
		float stembotstart = d * 5;

		float ringtopstart = d * 6;
		float ringbotstart = d * 7;
		float inringtopstart = d * 8;
		float inringbotstart = d * 9;
		float stemcenter = d * 10;

		float hoffset = offset / 2;

		float codewide = 7;

		// vertex
		float dTheta = Math::TWO_PI / d;
		for (int i = 0; i < d; i++) {
			float theta = i * dTheta;
			float outsidex = r2 * sin(theta);
			float outsidez = r2 * cos(theta) - r2;
			float insidex = r1 * sin(theta) + ((i>d/2)? -hoffset:hoffset);
			float insidez = r1 * cos(theta) - r2;

			// top vertex
			setVertex(outtopstart+i, outsidex, h, outsidez);
			// bottom vertex
			setVertex(outbotstart+i, outsidex, -h, outsidez);
			// top cap
			setVertex(intopstart+i, insidex, h, insidez);
			// bottom cap
			setVertex(inbotstart+i, insidex, -h, insidez);


			float stemtopx = stemradius * 0.6 * sin(theta);
			float stemtopy = stemradius * 0.6 * cos(theta);
			float stembotx = stemradius * sin(theta);
			float stemboty = stemradius * cos(theta);

			setVertex(stemtopstart+i, stemtopx, stemtopy, -offset);
			setVertex(stembotstart+i, stembotx, stemboty, stemlength);

			float ringtopx = stemradius * 1.1 * sin(theta);
			float ringtopy = stemradius * 1.1 * cos(theta);
			float ringbotx = stemradius * 1.1 * sin(theta);
			float ringboty = stemradius * 1.1 * cos(theta);
			setVertex(ringtopstart+i, ringtopx, ringtopy, stemlength - codewide - 1.5);
			setVertex(ringbotstart+i, ringbotx, ringboty, stemlength - codewide - 1);

			float inringtopx = stemradius * 0.6 * sin(theta);
			float inringtopy = stemradius * 0.6 * cos(theta);
			float inringbotx = stemradius * 0.6 * sin(theta);
			float inringboty = stemradius * 0.6 * cos(theta);
			setVertex(inringtopstart+i, inringtopx, inringtopy, stemlength - codewide-1.8);
			setVertex(inringbotstart+i, inringbotx, inringboty, stemlength - codewide-0.9);
		}
		setVertex(stemcenter, 0, 0, -offset-0.8);
		setVertex(stemcenter+1, 0, 0, stemlength + 0.3);

		int pos = 0;
		// faces
		for (int i = 0; i < d; i++) {
			setFace(i, // face id
					outbotstart + i,
					outbotstart + (i + 1) % d,
					outtopstart + (i + 1) % d,
					outtopstart + i
					);
			setFace(d + i,
					intopstart + i,
					intopstart + (i + 1) % d,
					inbotstart + (i + 1) % d,
					inbotstart + i
					);
			setFace(d*2+i, // face id
					outtopstart + i,
					outtopstart + (i + 1) % d,
					intopstart + (i + 1) % d,
					intopstart + i
					);
			setFace(d*3+i, // face id
					inbotstart + i,
					inbotstart + (i + 1) % d,
					outbotstart + (i + 1) % d,
					outbotstart + i
					);
			setFace(d*4+i, // face id
					stembotstart + i,
					stembotstart + (i + 1) % d,
					stemtopstart + (i + 1) % d,
					stemtopstart + i
					);

			setFace(d*5+i, // face id
					ringbotstart + i,
					ringbotstart + (i + 1) % d,
					ringtopstart + (i + 1) % d,
					ringtopstart + i
					);

			setFace(d*6+i, // face id
					ringtopstart + i,
					ringtopstart + (i + 1) % d,
					inringtopstart + (i + 1) % d,
					inringtopstart + i
					);

			setFace(d*7+i, // face id
					inringbotstart + i,
					inringbotstart + (i + 1) % d,
					ringbotstart + (i + 1) % d,
					ringbotstart + i
					);

			setFace(pos++, // face id
					stemtopstart + i,
					stemtopstart + (i + 1) % d,
					stemcenter
					);

			setFace(pos++, // face id
					stemcenter + 1,
					stembotstart + (i + 1) % d,
					stembotstart + i
					);
		}

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();	
	}


	FancyKeyBody::~FancyKeyBody(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
