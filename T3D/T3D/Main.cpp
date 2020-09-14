// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// main.cpp
//
// Main entry point. Creates and runs a T3DApplication

#include "sdl/SDL.h"
#include "T3DTest.h"
#include "Tutorial4.h"
#include "Assignment1Test.h"
#include "ShaderTest.h"
#include "GLTestApplication.h"

// #ifdef main
// #undef main
// #endif


using namespace T3D;


int main(int argc, char* argv[]){

	// T3DApplication *theApp = new T3DTest();
	// T3DApplication *theApp = new Tutorial1();
	// T3DApplication *theApp = new Tutorial4();
	T3DApplication *theApp = new Assignment1Test();
	// T3DApplication *theApp = new GLTestApplication();
	// T3DApplication *theApp = new ShaderTest();

	theApp->run();
	delete theApp;

	return 0;
}
