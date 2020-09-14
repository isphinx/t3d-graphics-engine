// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// ShaderTest.cpp
//
// A simple application used for testing lighting shaders

#pragma once
#include "WinGLApplication.h"

namespace T3D{

	class ShaderTest :
		public WinGLApplication
	{
	public:
		ShaderTest(void);
		~ShaderTest(void);
	
		bool init();
	};

}

