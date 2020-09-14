// =================================================
// KIT608 - Advanced Games Programming, 2020
// =================================================
//
// Author: Xin Li
//
// Robot.h

#ifndef ROBOT_H
#define ROBOT_H

#include "Mesh.h"
#include "GameObject.h"

namespace T3D
{
	class Robot : public GameObject
	{
	public:
		Robot(T3DApplication *app, Material *color);
		virtual ~Robot (void);

		GameObject *head;
		GameObject *shoulder;
		GameObject *arm1;
		GameObject *arm2;
		GameObject *forearm1;
		GameObject *forearm2;
		GameObject *leg;
		GameObject *wheel;

		GameObject *shoulderLeftJoint;
		GameObject *shoulderRightJoint;
		GameObject *elbowLeftJoint;
		GameObject *elbowRightJoint;
	};
}

#endif

