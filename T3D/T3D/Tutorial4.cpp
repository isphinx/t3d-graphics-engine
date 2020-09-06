// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Xin Li
//
// Tutorial4.cpp
//
// Base application for tutorial 4.

#include "Tutorial4.h"
#include "Camera.h"
#include "KeyboardController.h"
#include "Cube2.h"
#include "Pyramid.h"
#include "Cylinder.h"

namespace T3D{

	Tutorial4::Tutorial4(void)
	{
		drawArea = new Texture(1024,640,false);
		drawArea->clear(Colour(255,255,255,255));
	}


	Tutorial4::~Tutorial4(void)
	{
	}

	bool Tutorial4::init(){
		WinGLApplication::init();

		// light
		GameObject *lightObj = new GameObject(this);
		Light *light = new Light(Light::DIRECTIONAL);
		light->setAmbient(1,1,1);
		light->setDiffuse(1,1,1);
		light->setSpecular(1,1,1);
		lightObj->setLight(light);
		lightObj->getTransform()->
		setLocalRotation(Vector3(-45*Math::DEG2RAD, 70*Math::DEG2RAD, 0));
		lightObj->getTransform()->setParent(root);

		// carema
		GameObject *camObj = new GameObject(this);
		renderer->camera = new Camera(Camera::PERSPECTIVE,0.1,500.0,45.0,1.6);
		camObj->getTransform()->setLocalPosition(Vector3(0,0,20));
		camObj->getTransform()->setLocalRotation(Vector3(0,0,0));
		camObj->setCamera(renderer->camera);
		camObj->getTransform()->setParent(root);
		camObj->addComponent(new KeyboardController());

		// material
		Material *color = renderer->createMaterial(Renderer::PR_OPAQUE);
		color->setDiffuse(1,0,0,1);

		GameObject *model = NULL;
		// pyramid
		// model = new GameObject(this);
		// model->setMesh(new Pyramid(1));
		// model->setMaterial(color);
		// model->getTransform()->setLocalPosition(Vector3(-5,0,0));
		// model->getTransform()->setParent(root);
		// model->getTransform()->name = "Pyramid";

		// cube
		model = new GameObject(this);
		model->setMesh(new Cylinder(10, 5, 2));
		model->setMaterial(color);
		model->getTransform()->setLocalPosition(Vector3(5,0,0));
		model->getTransform()->setParent(root);
		model->getTransform()->name = "Cylinder";

		return true;
	}

}
