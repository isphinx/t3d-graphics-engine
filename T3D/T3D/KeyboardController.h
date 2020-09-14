// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// keyboardcontroller.h
//
// Component to add FPS-like controls to a game object

#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "Component.h"

namespace T3D
{

	class KeyboardController :
		public Component
	{
	public:
		KeyboardController(void);
		virtual ~KeyboardController(void);

		virtual void update(float dt);
		void keyDownResolve(float dt);
		void keyUpResolve(float dt);
		void mouseMoveResolve();

	private:
		float keySensitivity;
		float mouseSensitivity;
	};

}

#endif

