// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// FancyKey.cpp

#include "Math.h"
#include "FancyKey.h"
#include "FancyKeyBody.h"
#include "Cube2.h"
#include "Transform.h"


namespace T3D
{
	FancyKey::FancyKey(T3DApplication *app, Material *color,
					   int d, float r1, float r2,
					   float offset, float depth,
					   float stemlength, float stemradius,
					   vector<float> code):
	GameObject(app) {
		this->setMaterial(color);

		setMesh(new FancyKeyBody(d,r1,r2,offset,depth,stemlength,stemradius));
		// getTransform()->name = "FancyKeyBody";


		float codewide = 6.0/8;

		GameObject* codecube = new GameObject(app);
		codecube->setMesh(new Cube2(2.0,depth/2,codewide*7/2));
		codecube->getTransform()->setParent(getTransform());
		codecube->getTransform()->setLocalPosition(Vector3(-2.0,0.0,stemlength - codewide *4));
		codecube->setMaterial(color);

		for(int i = 0; i < 7; i++) {
			if(code[i] == 1.0) {
				GameObject* subcode = new GameObject(app);
				subcode->setMesh(new Cube2(0.5,depth/2,codewide/2));
				subcode->getTransform()->setParent(codecube->getTransform());
				subcode->getTransform()->setLocalPosition(Vector3(-2.5,0.0,-2.3 + codewide * i));
				subcode->setMaterial(color);
			}			
			GameObject* subcode = new GameObject(app); subcode->setMesh(new
			Cube2(0.5/2,depth/2,codewide/2));
			subcode->getTransform()->setParent(codecube->getTransform());
			subcode->getTransform()->setLocalPosition(Vector3(-3.25,0.0,-2.3 + codewide * i));
			subcode->setMaterial(color);
			if(code[i+7] == 1.0) {
				GameObject* subcode = new GameObject(app);
				subcode->setMesh(new Cube2(0.5/2,depth/2,codewide/2));
				subcode->getTransform()->setParent(codecube->getTransform());
				subcode->getTransform()->setLocalPosition(Vector3(-3.75,0.0,-2.3 + codewide * i));
				subcode->setMaterial(color);
			}			
		}

	}


	FancyKey::~FancyKey(void)
	{
	}
}
