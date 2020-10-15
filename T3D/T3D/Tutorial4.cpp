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
#include "Key.h"
#include "Lamp.h"
#include "AnimationTask.h"

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
		// camObj->getTransform()->setLocalPosition(Vector3(0,0,20));
		camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 3));
		camObj->getTransform()->setLocalRotation(Vector3(0,0,0));
		camObj->setCamera(renderer->camera);
		camObj->getTransform()->setParent(root);
		camObj->addComponent(new KeyboardController());

		// material
		Material *color = renderer->createMaterial(Renderer::PR_OPAQUE);
		color->setDiffuse(1,0,1,1);

		// pyramid
		// model = new GameObject(this);
		// model->setMesh(new Pyramid(1));
		// model->setMaterial(color);
		// model->getTransform()->setLocalPosition(Vector3(5,0,0));
		// model->getTransform()->setParent(root);
		// model->getTransform()->name = "Pyramid";

		// cylinder
		// GameObject *model = NULL;
		// model = new GameObject(this);
		// model->setMesh(new Cylinder(400, 1, 1));
		// model->setMaterial(color);
		// model->getTransform()->setLocalPosition(Vector3(5,0,0));
		// model->getTransform()->setParent(root);
		// model->getTransform()->name = "Cylinder";


		Material *grey = renderer->createMaterial(Renderer::PR_OPAQUE);
		grey->setDiffuse(0.8,0.8,0.9,1);
		Lamp *lamp = new Lamp(this);
		lamp->setMaterial(grey);
		lamp->getTransform()->setLocalPosition(Vector3(0,0,0));
		lamp->getTransform()->setParent(root);

		lamp->base->setMaterial(grey);
		lamp->arm1->setMaterial(grey);
		lamp->arm2->setMaterial(grey);

		// AnimationTask *animTask = new AnimationTask(this);
		// animTask->lamp = lamp->getTransform();
		// addTask(animTask);

		Animation *anim = new Animation(10.0);
		lamp->addComponent(anim);
		anim->addKey("ElbowJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
		anim->addKey("ElbowJoint", 5.0, Quaternion(Vector3(-Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
		anim->addKey("ElbowJoint", 7.0, Quaternion(Vector3(Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
		anim->addKey("ElbowJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
		anim->addKey("ShadeJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
		anim->addKey("ShadeJoint", 5.0, Quaternion(Vector3(0, 0, -Math::HALF_PI)), Vector3(0, 0.2, 0));
		anim->addKey("ShadeJoint", 7.0, Quaternion(Vector3(0, 0, Math::HALF_PI)), Vector3(0, 0.2, 0));
		anim->addKey("ShadeJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
		anim->loop(true);
		anim->play();

		// Quaternion q = Quaternion(Vector3(-Math::PI/10,Math::PI/4,0));
		// lamp->baseJoint->getTransform()->setLocalRotation(q);
		// q = Quaternion(Vector3(Math::PI/4,0,0));
		// lamp->elbowJoint->getTransform()->setLocalRotation(q);

		return true;
	}

}
