// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// Assignment1.cpp
//
// Base application for Assigment 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.

#ifndef ASSIGMENT1TEST_H
#define ASSIGMENT1TEST_H

#include "WinGLApplication.h"
#include "Texture.h"
#include "DrawTask.h"

namespace T3D{

	class Assignment1Test : public WinGLApplication
	{
	public:
		Assignment1Test(void);
		~Assignment1Test(void);

		bool init();

	private:
		Texture *drawArea;
		DrawTask *drawTask;

	};

}

#endif
