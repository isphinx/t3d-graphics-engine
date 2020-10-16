// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// AnimationTask.cpp

#include "AnimationTask.h"
#include "T3DApplication.h"
#include "Transform.h"
#include "KeyboardController.h"

namespace T3D{

	AnimationTask::AnimationTask(T3DApplication *app,
					  GameObject* box1, GameObject* box2,
					  GameObject* cam) : Task(app) {
		elapsedTime = 0;
		this->box1 = box1;
		this->box2 = box2;
		this->cam = cam;
	}

	AnimationTask::~AnimationTask(void) {
	}

	void AnimationTask::update(float dt) {
		elapsedTime += dt;
		if (elapsedTime > 14) {
			box1->setVisible(true);
			box2->setVisible(false);
		}
		// if (elapsedTime > 30) {
		// 	cam->addComponent(new KeyboardController());
		// }
		// lamp->setLocalPosition(Vector3::lerp(Vector3(0,0,0),Vector3(1,0,0),elapsedTime/10.0));
		// lamp->setLocalPosition(Vector3(Math::smoothedLerp(0,1,elapsedTime/5.0,0.2),0,0));
	}

}
