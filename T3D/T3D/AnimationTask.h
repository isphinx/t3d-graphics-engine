// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// AnimationTask.cpp

#ifndef ANIMATIONTASK_H
#define ANIMATIONTASK_H

#include "Task.h"

namespace T3D{
	class T3DApplication;
	class Transform;
	class GameObject;

	class AnimationTask : public Task
	{
	public:
		AnimationTask(T3DApplication *app,
					  GameObject* box1,
					  GameObject* box2,
					  GameObject* cam
					  );

		~AnimationTask(void);

		void update(float dt);

	private:
		float elapsedTime;

		GameObject* box1;
		GameObject* box2;

		GameObject* cam;

	};

}

#endif
