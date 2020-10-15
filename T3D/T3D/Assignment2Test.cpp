// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// Assignment2Test.cpp

#include "Assignment2Test.h"
#include "Camera.h"
#include "KeyboardController.h"
#include "Case.h"
#include "Robot.h"
#include "RotateBehaviour.h"
#include "GLShader.h"
#include "Animation.h"
#include <vector>

namespace T3D{

	Assignment2Test::Assignment2Test(void)
	{
		drawArea = new Texture(1024,640,false);
		drawArea->clear(Colour(255,255,255,255));
	}


	Assignment2Test::~Assignment2Test(void)
	{
	}

	bool Assignment2Test::init(){
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

		// task 1 robot animation
		{
			Material *grey = renderer->createMaterial(Renderer::PR_OPAQUE);
			grey->setDiffuse(0.8,0.8,0.9,1);
			Robot *robot = new Robot(this, grey);
			robot->getTransform()->setLocalPosition(Vector3(0,0,0));
			robot->getTransform()->setParent(root);

			Animation *anim = new Animation(10.0);
			robot->addComponent(anim);
			anim->addKey("shoulderLeftJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 5.0, Quaternion(Vector3(-Math::HALF_PI, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 7.0, Quaternion(Vector3(Math::HALF_PI, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("elbowLeftJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 5.0, Quaternion(Vector3(0, 0, -Math::HALF_PI)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 7.0, Quaternion(Vector3(0, 0, Math::HALF_PI)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->loop(true);
			anim->play();
		}

		Material *fixedGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		fixedGreen->setDiffuse(0.0,0.6,0,1);
		fixedGreen->setShininess(20);
		Material *gouraudGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		gouraudGreen->setDiffuse(0.0,0.6,0,1);
		// gouraudGreen->setShininess(20);
		Material *phongGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		phongGreen->setDiffuse(0.0,0.6,0,1);
		phongGreen->setShininess(20);

		GLShader *gouraudShader = new GLShader("Resources/vspecular.shader","Resources/frag.shader");
		// GLShader *gouraudShader = new GLShader("Resources/phongVert.shader","Resources/phongFrag.shader");
		gouraudShader->compileShader();
		gouraudGreen->setShader(gouraudShader);
		// task 2 texture
		{
			GameObject* thecase = new GameObject(this);
			thecase->setMesh(new Case());
			thecase->getTransform()->setParent(root);
			thecase->getTransform()->setLocalPosition(Vector3(10, 0, 0));
			thecase->getTransform()->name = "case";

			Texture *cratetex = new Texture("Resources/case.jpg", true, true);
			renderer->loadTexture(cratetex);
			Material *cratemat = renderer->createMaterial(Renderer::PR_OPAQUE);
			cratemat->setTexture(cratetex);

			thecase->setMaterial(cratemat);
		}

		// task 3 shader
		{
			GameObject* shader = new GameObject(this);
			shader->setMesh(new Case());
			shader->getTransform()->setParent(root);
			shader->getTransform()->setLocalPosition(Vector3(20, 0, 0));
			shader->getTransform()->name = "shader";


			shader->setMaterial(gouraudGreen);
		}

		// task 4 toon shader
		{
			GameObject* shader = new GameObject(this);
			shader->setMesh(new Case());
			shader->getTransform()->setParent(root);
			shader->getTransform()->setLocalPosition(Vector3(30, 0, 0));
			shader->getTransform()->name = "toon shader";


			shader->setMaterial(phongGreen);
		}

		return true;
	}
}
