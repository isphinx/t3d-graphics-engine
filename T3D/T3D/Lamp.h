// =========================================================================================
// KIT608 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Xin Li
//
// lamp.h
//
// Simple cube mesh with coloured sides

#ifndef LAMP_H
#define LAMP_H

#include "Mesh.h"
#include "GameObject.h"

namespace T3D
{
	class Lamp : public GameObject
	{
	public:
		Lamp(T3DApplication *app);
		virtual ~Lamp(void);

		GameObject *base;
		GameObject *arm1;
		GameObject *arm2;
		GameObject *baseJoint;
		GameObject *elbowJoint;
		GameObject *shadeJoint;
	};
}

#endif

