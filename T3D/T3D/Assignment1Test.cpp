// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// Assignment1Test.cpp
//
// Base application for tutorial 4.

#include "Assignment1Test.h"
#include "Camera.h"
#include "KeyboardController.h"
#include "Cube2.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "Key.h"
#include "FancyKey.h"
#include "Robot.h"
#include "Sweep.h"
#include "SweepPath.h"
#include "RotateBehaviour.h"
#include <vector>

namespace T3D{

	Assignment1Test::Assignment1Test(void)
	{
		drawArea = new Texture(1024,640,false);
		drawArea->clear(Colour(255,255,255,255));
	}


	Assignment1Test::~Assignment1Test(void)
	{
	}

	bool Assignment1Test::init(){
		WinGLApplication::init();
		// set ambient
		float* ambient = getRenderer()->ambient;
		ambient[0] = 0.2f;
		ambient[1] = 0.2f;
		ambient[2] = 0.2f;
		ambient[3] = 1;

		// light
		GameObject *lightObj = new GameObject(this);
		Light *light = new Light(Light::DIRECTIONAL);
		light->setAmbient(1, 1, 1);
		light->setDiffuse(1, 1, 1);
		light->setSpecular(1, 1, 1);
		lightObj->setLight(light);
		lightObj->getTransform()->setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
		lightObj->getTransform()->setParent(root);

		// carema
		GameObject *camObj = new GameObject(this);
		renderer->camera = new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
		camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
		camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
		camObj->setCamera(renderer->camera);
		camObj->getTransform()->setParent(root);
		camObj->addComponent(new KeyboardController());

		
		//Create an empty node to use as a rotation point
		GameObject *rotateOrigin = new GameObject(this);
		rotateOrigin->getTransform()->setParent(root);
		rotateOrigin->addComponent(new RotateBehaviour(Vector3(0,1,0)));

		// Material
		Material *color = renderer->createMaterial(Renderer::PR_OPAQUE);
		color->setDiffuse(1,0.1,1,1);

		// task 1 key
		{
			GameObject *bottle = new GameObject(this);
			vector<Vector3> points;
			points.push_back(Vector3(0.95, 0, -0.30));
			points.push_back(Vector3(0.80, 0, -0.58));
			points.push_back(Vector3(0.58, 0, -0.80));
			points.push_back(Vector3(0.30, 0, -0.95));
			points.push_back(Vector3(0.0, 0, -1.0));
			points.push_back(Vector3(-0.30, 0, -0.95));
			points.push_back(Vector3(-0.58, 0, -0.80));
			points.push_back(Vector3(-0.80, 0, -0.58));
			points.push_back(Vector3(-0.95, 0, -0.30));
			points.push_back(Vector3(-1.00, 0, -0.0));
			points.push_back(Vector3(-0.95, 0, 0.30));
			points.push_back(Vector3(-0.80, 0, 0.58));
			points.push_back(Vector3(-0.58, 0, 0.80));
			points.push_back(Vector3(-0.30, 0, 0.95));
			points.push_back(Vector3(-0.0, 0, 1.0));
			points.push_back(Vector3(0.30, 0, 0.95));
			points.push_back(Vector3(0.58, 0, 0.80));
			points.push_back(Vector3(0.80, 0, 0.58));
			points.push_back(Vector3(0.95, 0, 0.30));
			points.push_back(Vector3(1.0, 0, 0.0));

			SweepPath sp;
			Transform t;

			t.setLocalPosition(Vector3(0,0.0,0));
			t.setLocalScale(Vector3(0,1.0,0));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,0.0,0));
			t.setLocalScale(Vector3(0.79,1,0.79));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,0.1,0));
			t.setLocalScale(Vector3(0.8,1,0.8));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,3.0,0));
			t.setLocalScale(Vector3(0.8,1,0.8));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,3.1,0));
			t.setLocalScale(Vector3(0.79,1,0.79));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,3.5,0));
			t.setLocalScale(Vector3(0.31,1.0,0.31));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,3.6,0));
			t.setLocalScale(Vector3(0.3,1.0,0.3));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,5.0,0));
			t.setLocalScale(Vector3(0.3,1.0,0.3));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,5.01,0));
			t.setLocalScale(Vector3(0.36,1.0,0.36));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,5.3,0));
			t.setLocalScale(Vector3(0.33,1.0,0.33));
			sp.addTransform(t);

			t.setLocalPosition(Vector3(0,5.3,0));
			t.setLocalScale(Vector3(0.0,1.0,0.0));
			sp.addTransform(t);

			bottle->setMesh(new Sweep(points,sp,true));
			bottle->setMaterial(color);
			bottle->getTransform()->setLocalPosition(Vector3(-10,0,0));
			bottle->getTransform()->setParent(root);
			bottle->getTransform()->name = "Bottle";
		}

		// task 2 robot
		{
			Material *grey = renderer->createMaterial(Renderer::PR_OPAQUE);
			grey->setDiffuse(0.8,0.8,0.9,1);
			Robot *robot = new Robot(this, grey);
			robot->getTransform()->setLocalPosition(Vector3(0,0,0));
			robot->getTransform()->setParent(root);
		}

		// task 3 key
		{
			GameObject* key = new GameObject(this);
			vector<float> code = { 1.0, 1.0, 1.0, 0.7, 1.0, 0.7, 0.9, 1.0, 0.4 };
			key->setMesh(new Key(40,1,5,2,0.5,2,4,code));
			key->setMaterial(color);
			key->getTransform()->setParent(root);
			key->getTransform()->setLocalPosition(Vector3(10, 0, 0));
			key->getTransform()->name = "Key";
		}

		// task 4 key
		{
			GameObject* fkey = new GameObject(this);
			vector<float> code = { 1.0, 1.0, 1.0, 0.7, 1.0, 0.7, 0.9, 1.0, 0.4 };
			fkey->setMesh(new FancyKey(40,2,4,1,0.5,4,1,code));
			fkey->setMaterial(color);
			fkey->getTransform()->setParent(root);
			fkey->getTransform()->setLocalPosition(Vector3(25, 0, 0));
			fkey->getTransform()->name = "Key";
			
		}

		return true;
	}
}
