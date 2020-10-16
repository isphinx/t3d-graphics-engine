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
#include "Sphere.h"
#include "Animation.h"
#include "AnimationTask.h"
#include "Cube.h"
#include "Cube2.h"
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
		camObj->getTransform()->setLocalPosition(Vector3(-25, 25, 20));
		Quaternion camrotat = Quaternion(Vector3(-Math::HALF_PI*2/5, -Math::HALF_PI/2, 0));

		camObj->getTransform()->setLocalRotation(camrotat);
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

			Animation *anim = new Animation(30.0);
			robot->addComponent(anim);
			anim->addKey("Robot", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0, 0));
			anim->addKey("Robot", 1, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0, 0));
			anim->addKey("Robot", 5.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0,-12));
			anim->addKey("Robot", 7.0, Quaternion(Vector3(0, Math::HALF_PI, 0)), Vector3(0, 0, -12));
			anim->addKey("Robot", 10.0, Quaternion(Vector3(0, Math::HALF_PI, 0)), Vector3(-12, 0, -12));
			anim->addKey("Robot", 15.0, Quaternion(Vector3(0, Math::HALF_PI, 0)), Vector3(-12, 0, -12));
			anim->addKey("Robot", 18.0, Quaternion(Vector3(0, -Math::HALF_PI, 0)), Vector3(-12, 0, -12));
			anim->addKey("Robot", 24.0, Quaternion(Vector3(0, -Math::HALF_PI, 0)), Vector3(12, 0, -12));
			anim->addKey("Robot", 30.0, Quaternion(Vector3(0, -Math::HALF_PI, 0)), Vector3(12, 0, -12));

			anim->addKey("shoulderLeftJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 10, Quaternion(Vector3(0, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 14.0, Quaternion(Vector3(0, -Math::HALF_PI/2, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 24.0, Quaternion(Vector3(0, -Math::HALF_PI/2, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 28, Quaternion(Vector3(0, 0, 0)), Vector3(0, 2.0, 0));
			anim->addKey("shoulderLeftJoint", 30, Quaternion(Vector3(0, 0, 0)), Vector3(0, 2.0, 0));

			anim->addKey("shoulderRightJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -2.0, 0));
			anim->addKey("shoulderRightJoint", 10, Quaternion(Vector3(0, 0, 0)), Vector3(0, -2.0, 0));
			anim->addKey("shoulderRightJoint", 14.0, Quaternion(Vector3(0, -Math::HALF_PI/2, 0)), Vector3(0, -2.0, 0));
			anim->addKey("shoulderRightJoint", 24.0, Quaternion(Vector3(0, -Math::HALF_PI/2, 0)), Vector3(0, -2.0, 0));
			anim->addKey("shoulderRightJoint", 28, Quaternion(Vector3(0, 0, 0)), Vector3(0, -2.0, 0));
			anim->addKey("shoulderRightJoint", 30, Quaternion(Vector3(0, 0, 0)), Vector3(0, -2.0, 0));


			anim->addKey("elbowRightJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowRightJoint", 10, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowRightJoint", 14.0, Quaternion(Vector3(0, -Math::HALF_PI/2, -Math::HALF_PI/2)), Vector3(-2, 0, 0));
			anim->addKey("elbowRightJoint", 24.0, Quaternion(Vector3(0, -Math::HALF_PI/2, -Math::HALF_PI/2)), Vector3(-2, 0, 0));
			anim->addKey("elbowRightJoint", 28.0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowRightJoint", 30.0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));

			anim->addKey("elbowLeftJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 10, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 14.0, Quaternion(Vector3(0, -Math::HALF_PI/2, Math::HALF_PI/2)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 24.0, Quaternion(Vector3(0, -Math::HALF_PI/2, Math::HALF_PI/2)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 28.0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));
			anim->addKey("elbowLeftJoint", 30.0, Quaternion(Vector3(0, 0, 0)), Vector3(-2, 0, 0));

			anim->loop(false);
			anim->play();

			
			GameObject* box1 = new GameObject(this);
			box1->setMesh(new Cube(1.0));
			box1->getTransform()->setParent(robot->getTransform());
			box1->getTransform()->setLocalPosition(Vector3(0, 3.0, -3));
			box1->getTransform()->name = "box1";
			box1->setMaterial(color);
			box1->setVisible(false);

			GameObject* box2 = new GameObject(this);
			box2->setMesh(new Cube(1.0));
			box2->getTransform()->setParent(root);
			box2->getTransform()->setLocalPosition(Vector3(-15, 3.0, -12));
			box2->getTransform()->name = "box2";
			box2->setMaterial(color);

			// GameObject* box3 = new GameObject(this);
			// box3->setMesh(new Cube(1.0));
			// box3->getTransform()->setParent(root);
			// box3->getTransform()->setLocalPosition(Vector3(15, 3.0, -12));
			// box3->getTransform()->name = "box3";
			// box3->setMaterial(color);
			// box3->setVisible(false);

			GameObject* box4 = new GameObject(this);
			box4->setMesh(new Cube2(1.0,1.0,12.0));
			box4->getTransform()->setParent(root);
			box4->getTransform()->setLocalPosition(Vector3(-15, 1.0, -6));
			box4->getTransform()->name = "box4";
			box4->setMaterial(color);

			GameObject* box5 = new GameObject(this);
			box5->setMesh(new Cube2(1.0,1.0,12.0));
			box5->getTransform()->setParent(root);
			box5->getTransform()->setLocalPosition(Vector3(15, 1.0, -6));
			box5->getTransform()->name = "box5";
			box5->setMaterial(color);

			AnimationTask *animTask = new AnimationTask(this, box1, box2, camObj);
			addTask(animTask);
		}

		// task 2 texture
		{
			Material *gouraudGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
			gouraudGreen->setDiffuse(0.0,0.6,0,1);
			gouraudGreen->setShininess(20);

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
			Material *task3material = renderer->createMaterial(Renderer::PR_OPAQUE);
			task3material->setDiffuse(0.0,0.6,0,1);
			task3material->setShininess(20);

			GLShader *task3shader = new GLShader("Resources/vstask3.shader","Resources/fragtask3.shader");
			task3shader->compileShader();
			task3material->setShader(task3shader);

			GameObject* shader = new GameObject(this);
			shader->setMesh(new Sphere(2,16));
			shader->getTransform()->setParent(root);
			shader->getTransform()->setLocalPosition(Vector3(-10, 0, 0));
			shader->getTransform()->name = "shader";

			shader->setMaterial(task3material);
		}

		// task 4 toon shader
		{
			Material *task4material = renderer->createMaterial(Renderer::PR_OPAQUE);
			task4material->setDiffuse(0.0,0.6,0,1);
			task4material->setShininess(20);

			GLShader *task4shader = new GLShader("Resources/vstask4.shader","Resources/fragtask4.shader");
			task4shader->compileShader();
			task4material->setShader(task4shader);

			GameObject* shader = new GameObject(this);
			shader->setMesh(new Sphere(2,16));
			shader->getTransform()->setParent(root);
			shader->getTransform()->setLocalPosition(Vector3(0, 0, 0));
			shader->getTransform()->name = "toon shader";


			shader->setMaterial(task4material);
		}

		return true;
	}
}
