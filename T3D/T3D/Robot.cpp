// =========================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================
//
// Author: Xin Li
//
// Robot.cpp

#include "Robot.h"
#include "Cylinder.h"
#include "Transform.h"
#include "Sweep.h"
#include "SweepPath.h"
#include "Sphere.h"

using namespace std;

namespace T3D
{
	Robot::Robot(T3DApplication *app, Material *color) : GameObject(app){
		this->setMaterial(color);

		vector<Vector3> bodyProfile;
		bodyProfile.push_back(Vector3(-1.0f,0.0f,-0.5f));
		bodyProfile.push_back(Vector3(-0.8f,0.0f,-0.6f));
		bodyProfile.push_back(Vector3(0.8f,0.0f,-0.6f));
		bodyProfile.push_back(Vector3(1.0f,0.0f,-0.5f));
		bodyProfile.push_back(Vector3(1.0f,0.0f,0.5f));
		bodyProfile.push_back(Vector3(0.8f,0.0f,0.6f));
		bodyProfile.push_back(Vector3(-0.8f,0.0f,0.6f));
		bodyProfile.push_back(Vector3(-1.0f,0.0f,0.5f));

		SweepPath bodysp;
		Transform t;
		t.setLocalPosition(Vector3(0.0,5.0,0));
		t.setLocalScale(Vector3(0.0,1.0,0.0));
		bodysp.addTransform(t);
		
		t.setLocalPosition(Vector3(0.0,5.0,0));
		t.setLocalScale(Vector3(0.6,1.0,0.6));
		bodysp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,4.9,0));
		t.setLocalScale(Vector3(0.8,1.0,0.8));
		bodysp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,4.2,0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		bodysp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.0,0));
		t.setLocalScale(Vector3(0.8,1.0,0.8));
		bodysp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.0,0));
		t.setLocalScale(Vector3(0.0,1.0,0.0));
		bodysp.addTransform(t);

		setMesh(new Sweep(bodyProfile, bodysp, false));
		getTransform()->name = "Robot";

		shoulder = new GameObject(app);
		shoulder->setMesh(new Cylinder(0.3,2.0,16));
		Quaternion sr = Quaternion(Vector3(0,0,Math::PI/2));
		shoulder->getTransform()->setLocalRotation(sr);
		shoulder->getTransform()->setParent(getTransform());
		shoulder->getTransform()->setLocalPosition(Vector3(0,4.6,0));
		shoulder->getTransform()->name = "Shoulder";
		shoulder->setMaterial(color);


		vector<Vector3> armProfile;
		armProfile.push_back(Vector3(0.0f,-12.0f,0.0f));
		armProfile.push_back(Vector3(1.14f,-11.4f,0.0f));
		armProfile.push_back(Vector3(2.0f,-10.0f,0.0f));
		armProfile.push_back(Vector3(2.0f,10.0f,0.0f));
		armProfile.push_back(Vector3(1.4f,11.4f,0.0f));
		armProfile.push_back(Vector3(0.0f,12.0f,0.0f));
		armProfile.push_back(Vector3(-1.4f,11.4f,0.0f));
		armProfile.push_back(Vector3(-2.0f,10.0f,0.0f));
		armProfile.push_back(Vector3(-2.0f,-10.0f,0.0f));
		armProfile.push_back(Vector3(-1.4f,-11.4f,0.0f));


		shoulderLeftJoint = new GameObject(app);
		shoulderLeftJoint->setMesh(new Sphere(0.5,8));
		shoulderLeftJoint->setMaterial(color);
		shoulderLeftJoint->getTransform()->setLocalPosition(Vector3(0,2.0,0));
		shoulderLeftJoint->getTransform()->setParent(shoulder->getTransform());
		shoulderLeftJoint->getTransform()->name = "shoulderLeftJoint";
		// Quaternion s2q = Quaternion(Vector3(0,0,-Math::PI/4));
		// shoulderLeftJoint->getTransform()->setLocalRotation(s2q);

		Cylinder *armmesh = new Cylinder(0.3,1.0,16);
		arm1 = new GameObject(app);	
		arm1->setMesh(armmesh);
		arm1->setMaterial(color);
		Quaternion a1q = Quaternion(Vector3(0,0,Math::PI/2));
		arm1->getTransform()->setLocalRotation(a1q);
		arm1->getTransform()->setLocalPosition(Vector3(-1.0,0.0,0));
		arm1->getTransform()->setParent(shoulderLeftJoint->getTransform());
		arm1->getTransform()->name = "Arm1";

		shoulderRightJoint = new GameObject(app);
		shoulderRightJoint->setMesh(new Sphere(0.5,8));
		shoulderRightJoint->setMaterial(color);
		shoulderRightJoint->getTransform()->setLocalPosition(Vector3(0,-2.0,0));
		shoulderRightJoint->getTransform()->setParent(shoulder->getTransform());
		shoulderRightJoint->getTransform()->name = "shoulderRightJoint";

		arm2 = new GameObject(app);	
		arm2->setMesh(armmesh);
		arm2->setMaterial(color);
		Quaternion a2q = Quaternion(Vector3(0,0,Math::PI/2));
		arm2->getTransform()->setLocalRotation(a2q);
		arm2->getTransform()->setLocalPosition(Vector3(-1.0,0.0,0));
		arm2->getTransform()->setParent(shoulderRightJoint->getTransform());
		arm2->getTransform()->name = "Arm2";

		elbowLeftJoint = new GameObject(app);
		elbowLeftJoint->setMesh(new Sphere(0.5,8));
		elbowLeftJoint->setMaterial(color);
		Quaternion elq = Quaternion(Vector3(Math::PI/4,Math::PI/4,-Math::PI/4));
		elbowLeftJoint->getTransform()->setLocalRotation(elq);
		elbowLeftJoint->getTransform()->setLocalPosition(Vector3(-2.0,0.0,0));
		elbowLeftJoint->getTransform()->setParent(shoulderLeftJoint->getTransform());
		elbowLeftJoint->getTransform()->name = "elbowLeftJoint";

		// forearm1
		forearm1 = new GameObject(app);	
		forearm1->setMesh(armmesh);
		forearm1->setMaterial(color);
		Quaternion f1q = Quaternion(Vector3(0,0,Math::PI/2));
		forearm1->getTransform()->setLocalRotation(f1q);
		forearm1->getTransform()->setLocalPosition(Vector3(-1.0,0.0,0));
		forearm1->getTransform()->setParent(elbowLeftJoint->getTransform());
		forearm1->getTransform()->name = "Forearm1";

		elbowRightJoint = new GameObject(app);
		elbowRightJoint->setMesh(new Sphere(0.5,8));
		elbowRightJoint->setMaterial(color);
		Quaternion erq = Quaternion(Vector3(Math::PI/4,Math::PI/4,0));
		elbowRightJoint->getTransform()->setLocalRotation(erq);
		elbowRightJoint->getTransform()->setLocalPosition(Vector3(-2.0,0.0,0));
		elbowRightJoint->getTransform()->setParent(shoulderRightJoint->getTransform());
		elbowRightJoint->getTransform()->name = "elbowRightJoint";

		// forearm2
		forearm2 = new GameObject(app);	
		forearm2->setMesh(armmesh);
		forearm2->setMaterial(color);
		Quaternion f2q = Quaternion(Vector3(0,0,Math::PI/2));
		forearm2->getTransform()->setLocalRotation(f2q);
		forearm2->getTransform()->setLocalPosition(Vector3(-1.0,0.0,0));
		forearm2->getTransform()->setParent(elbowRightJoint->getTransform());
		forearm2->getTransform()->name = "Forearm2";

		// leg
		leg = new GameObject(app);	
		leg->setMesh(new Cylinder(0.4,2.5,16));
		leg->setMaterial(color);
		// Quaternion lq = Quaternion(Vector3(0,0,Math::PI/2));
		// leg->getTransform()->setLocalRotation(lq);
		leg->getTransform()->setLocalPosition(Vector3(0.0,3.2,0));
		leg->getTransform()->setParent(getTransform());
		leg->getTransform()->name = "leg";

		vector<Vector3> wheelProfile;
		wheelProfile.push_back(Vector3(0.95, 0, -0.30));
		wheelProfile.push_back(Vector3(0.80, 0, -0.58));
		wheelProfile.push_back(Vector3(0.58, 0, -0.80));
		wheelProfile.push_back(Vector3(0.30, 0, -0.95));
		wheelProfile.push_back(Vector3(0.0, 0, -1.0));
		wheelProfile.push_back(Vector3(-0.30, 0, -0.95));
		wheelProfile.push_back(Vector3(-0.58, 0, -0.80));
		wheelProfile.push_back(Vector3(-0.80, 0, -0.58));
		wheelProfile.push_back(Vector3(-0.95, 0, -0.30));
		wheelProfile.push_back(Vector3(-1.00, 0, -0.0));
		wheelProfile.push_back(Vector3(-0.95, 0, 0.30));
		wheelProfile.push_back(Vector3(-0.80, 0, 0.58));
		wheelProfile.push_back(Vector3(-0.58, 0, 0.80));
		wheelProfile.push_back(Vector3(-0.30, 0, 0.95));
		wheelProfile.push_back(Vector3(-0.0, 0, 1.0));
		wheelProfile.push_back(Vector3(0.30, 0, 0.95));
		wheelProfile.push_back(Vector3(0.58, 0, 0.80));
		wheelProfile.push_back(Vector3(0.80, 0, 0.58));
		wheelProfile.push_back(Vector3(0.95, 0, 0.30));
		wheelProfile.push_back(Vector3(1.0, 0, 0.0));

		SweepPath wheelsp;
		Quaternion q = Quaternion(Vector3(0,Math::PI/2,0));
		t.setLocalRotation(q);
		t.setLocalPosition(Vector3(0.0,0.0,0.0));
		t.setLocalScale(Vector3(0.0,1.0,0.0));
		wheelsp.addTransform(t);


		t.setLocalPosition(Vector3(0.0,0.0,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);


		t.setLocalPosition(Vector3(0.0,0.1,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.1,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.2,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.2,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.3,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.3,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.4,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.4,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.5,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.5,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.6,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.6,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.7,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.7,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.8,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.8,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,0.9,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);
		
		t.setLocalPosition(Vector3(0.0,1.0,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,1.0,0.0));
		t.setLocalScale(Vector3(0.5,1.0,0.5));
		wheelsp.addTransform(t);
		
		t.setLocalPosition(Vector3(0.0,2.0,0.0));
		t.setLocalScale(Vector3(0.5,1.0,0.5));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.0,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.1,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.2,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.2,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.3,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.3,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.4,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.4,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.5,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.5,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.6,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.6,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.7,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.7,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.8,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.8,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.9,0.0));
		t.setLocalScale(Vector3(1.0,1.0,1.0));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,2.9,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,3.0,0.0));
		t.setLocalScale(Vector3(0.9,1.0,0.9));
		wheelsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0,3.0,0.0));
		t.setLocalScale(Vector3(0.0,1.0,0.0));
		wheelsp.addTransform(t);

		wheel = new GameObject(app);	
		wheel->setMesh(new Sweep(wheelProfile, wheelsp, false));
		wheel->setMaterial(color);
		Quaternion lq = Quaternion(Vector3(0,0,Math::PI/2));
		wheel->getTransform()->setLocalRotation(lq);
		wheel->getTransform()->setLocalPosition(Vector3(1.5,-2.3,0));
		wheel->getTransform()->setParent(leg->getTransform());
		wheel->getTransform()->name = "wheel";
	}

	Robot::~Robot(void)
	{
	}
}
