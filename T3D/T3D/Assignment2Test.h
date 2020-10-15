// =========================================================================================
// KIT608 - Advanced Games Programming, 2020
// =========================================================================================
//
// Author: Xin Li
//
// Assignment2.cpp

#ifndef ASSIGMENT2TEST_H
#define ASSIGMENT2TEST_H

#include "WinGLApplication.h"
#include "Texture.h"
#include "DrawTask.h"

namespace T3D{

	class Assignment2Test : public WinGLApplication
	{
	public:
		Assignment2Test(void);

		~Assignment2Test(void);

		bool init();

	private:
		Texture *drawArea;
		DrawTask *drawTask;

	};

}

#endif
