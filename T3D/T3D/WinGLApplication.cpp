// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// winglapplication.h
//
// t3d application for windows and OpenGL

// #include <windows.h>
#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "SDL_ttf.h"

#include "WinGLApplication.h"
#include "GLRenderer.h"
#include "Transform.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Vector3.h"
#include "Input.h"
#include "PerfLogTask.h"
#include "DiagMessageTask.h"
// #include "SoundManager.h"


// stdin, stdout, and stderr are defined differently in Visual Studio 2015
// This is required to give backward combatibility with the version of SDL being used.
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}



namespace T3D 
{

	WinGLApplication::WinGLApplication(void)
	{
		surf = NULL;
		running = false;
		renderer = new GLRenderer();		
		root = new Transform(NULL,"Root");
	}


	WinGLApplication::~WinGLApplication(void)
	{
		delete root;
		root = NULL;
		delete renderer;
		renderer = NULL;
	}

	bool WinGLApplication::init(){
		cout << "init\n";
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			return false;
		}
		
		//Initialize SDL_mixer
#ifdef WIN32
		soundManager->init();
#endif

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,         32);

		SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,      8);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,     8);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

		if((surf = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
			return false;
		}
		glewInit();
		glClearColor(1, 1, 1, 0);
		glClearDepth(1.0f);

#ifdef WIN32
		glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
#else
		glViewport(0, 0, WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2);
#endif

		// Initialize SDL_ttf library
		if (TTF_Init() != 0)
		{
			std::cout << "TTF_Init() Failed: " << TTF_GetError() << endl;
			SDL_Quit();
			exit(1);
		}

		SDL_WM_GrabInput(SDL_GRAB_ON);

		SDL_ShowCursor(SDL_DISABLE);

		std::cout<<glGetString(GL_VERSION)<<"\n";

		return true;
	}
		
	int WinGLApplication::run(void){		
		if(init() == false) {
			return -1;
		}
		running = true;

		SDL_Event sdlEvent;
		lastFrame = SDL_GetTicks()/1000.0f;
		while(running) {
#ifdef WIN32
			soundManager->update();
#endif

			float thisFrame = SDL_GetTicks()/1000.0f;
			dt = thisFrame-lastFrame;
			lastFrame = thisFrame;
			
			Input::onMouseMotion(0,0);
			while(SDL_PollEvent(&sdlEvent)) {
				handleEvent(&sdlEvent);
			}


			updateTasks();

			updateComponents(root);

			renderer->prerender();
			renderer->render(root);

			renderer->postrender();
		}

		quit();

		return 0;
	}

	void WinGLApplication::quit(void){	
		SDL_Quit();
	}

	void WinGLApplication::handleEvent(SDL_Event *e){
		switch (e->type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:				
				Input::onKeyDown(e->key.keysym.sym);
				cout<<e->key.keysym.sym;
				if (Input::keyDown[KEY_ESCAPE])
					running = false;
				if (Input::keyDown[KEY_F1] || Input::keyDown[KEY_1])
					renderer->toggleWireframe();
				if (Input::keyDown[KEY_F2] || Input::keyDown[KEY_2])
					renderer->toggleAxes();
				if (Input::keyDown[KEY_F3] || Input::keyDown[KEY_3])
					renderer->toggleGrid();
				if (Input::keyDown[KEY_F4] || Input::keyDown[KEY_4])
					renderer->togglePoints();
				if (Input::keyDown[KEY_F9] || Input::keyDown[KEY_5])
				{
					int line = 0;
					addTask(new DiagMessageTask(this, "ESCAPE     quit", 2, 600-(line++*20), true, 5.0));
					addTask(new DiagMessageTask(this, "F1         wireframe", 2, 600-(line++*20), true, 5.0));
					addTask(new DiagMessageTask(this, "F2         axes", 2, 600-(line++*20), true, 5.0));
					addTask(new DiagMessageTask(this, "F3         grid", 2, 600 - (line++ * 20), true, 5.0));
					addTask(new DiagMessageTask(this, "F4         points", 2, 600 - (line++ * 20), true, 5.0));
					addTask(new DiagMessageTask(this, "F9         show help", 2, 600-(line++*20), true, 5.0));
					addTask(new DiagMessageTask(this, "F10        show stats", 2, 600-(line++*20), true, 5.0));
				}
				if (Input::keyDown[KEY_F10] || Input::keyDown[KEY_6])
				{
					// find log task
					PerfLogTask *task = (PerfLogTask *)findTask("PerfLogTask");
					if (task)
					{
						// toggle on screen diagnostics
						task->setDiagDisplay(!task->getDiagDisplay());
					}
				}
				break;
			case SDL_KEYUP:
				Input::onKeyUp(e->key.keysym.sym);
				break;
			case SDL_MOUSEMOTION:
				Input::onMouseMotion((e->motion).xrel,(e->motion).yrel);
				break;
		}
	}

}
