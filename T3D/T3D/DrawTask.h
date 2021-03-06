// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// DrawTask.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#pragma once
#include "Task.h"
#include "T3DApplication.h"
#include "Texture.h"

namespace T3D
{

	class DrawTask : public Task
	{
	public:
		DrawTask(T3DApplication *app, Texture *tex);
		~DrawTask(void);

		void init();
		void drawDDALine(int x1, int y1, int x2, int y2, Colour c);
		void drawBresLine(int x1, int y1, int x2, int y2, Colour c);

		void DrawTaskTCircle(int cx, int cy, int r, Colour c);
		void DrawTaskPCircle(int cx, int cy, int r, Colour c);

		virtual void update(float dt);

		void drawLines(vector<Vector3> points, Vector3 offset);
		void drawPie(int cx, int cy, int r, float theta);
		void drawArrow1(int x1, int y1, int x2, int y2, int r, int d);
		void drawLineStrip(vector<Vector3> points);

	private:
		Texture *drawArea;
		Vector3 vert[4];
		Matrix3x3 T1;
		Matrix3x3 S;
		Matrix3x3 T2;
		Matrix3x3 P;
		Matrix3x3 R;
	};

} // namespace T3D
