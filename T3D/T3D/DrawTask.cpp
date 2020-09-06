// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// GameObject.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#include <math.h>
#include "DrawTask.h"

namespace T3D
{

	DrawTask::DrawTask(T3DApplication *app, Texture *tex) : Task(app)
	{
		drawArea = tex;
		init();
	}

	DrawTask::~DrawTask(void)
	{
	}

	void DrawTask::init()
	{
		drawArea->clear(Colour(255, 255, 255, 255));
		drawDDALine(100, 100, 200, 200, Colour(0, 0, 0, 255));
		drawDDALine(100, 100, 110, 200, Colour(0, 0, 0, 255));

		DrawTaskTCircle(150, 150, 30, Colour(0, 0, 0, 255));
		DrawTaskPCircle(150, 150, 40, Colour(0, 0, 0, 255));

		vert[0] = Vector3(100, 100, 1);
		vert[1] = Vector3(200, 100, 1);
		vert[2] = Vector3(200, 200, 1);
		vert[3] = Vector3(100, 200, 1);

		T1 = Matrix3x3(
			1, 0, -150,
			0, 1, -150,
			0, 0, 1);

		S = Matrix3x3(
			1.01, 0, 0,
			0, 1.01, 0,
			0, 0, 1);

		T2 = Matrix3x3(
			1, 0, 150,
			0, 1, 150,
			0, 0, 1);

		R = Matrix3x3(
			cos(0.1), -sin(0.1), 0,
			sin(0.1), cos(0.1), 0,
			0, 0, 1);

		P = T2 * S * T1;

		// P = Matrix3x3( // T2 * S * T1
		// 	1.01, 0, -1.5,
		// 	0, 1.01, -1.5,
		// 	0, 0, 1
		// 	);
	}

	void DrawTask::drawDDALine(int x1, int y1, int x2, int y2, Colour c)
	{
		// float ystep = float(y2-y1)/(x2-x1);
		// float y = y1;
		// for (int x = x1; x<x2; x++){
		// 	drawArea->plotPixel(x,int(y),c);
		// 	y += ystep;
		// }
		int deltax = (x2 - x1);
		int deltay = (y2 - y1);

		if (abs(deltay) > abs(deltax))
		{ // slope > 1
			if (y1 > y2)
			{
				swap(x1, x2);
				swap(y1, y2);
			}
			float xstep = float(deltax) / deltay;
			float x = float(x1);
			for (int y = y1; y < y2; y++)
			{
				drawArea->plotPixel((int)x, y, c);
				x += xstep;
			}
		}
		else
		{ // slope <= 1
			if (x1 > x2)
			{
				swap(x1, x2);
				swap(y1, y2);
			}
			float ystep = float(deltay) / deltax;
			float y = float(y1);
			for (int x = x1; x < x2; x++)
			{
				drawArea->plotPixel(x, int(y), c);
				y += ystep;
			}
		}
	}

	void DrawTask::drawBresLine(int x1, int y1, int x2, int y2, Colour c)
	{
	}

	void DrawTask::DrawTaskTCircle(int cx, int cy, int r, Colour c)
	{
		for (float theta = 0; theta < Math::TWO_PI; theta += 0.1)
		{
			int x = cx + r * cos(theta);
			int y = cy + r * sin(theta);
			drawArea->plotPixel(x, y, c);
		}
	}

	void DrawTask::DrawTaskPCircle(int cx, int cy, int r, Colour c)
	{
		for (int y = 0; y <= r / sqrt(2); y++)
		{
			int x = sqrt(r * r - y * y);
			drawArea->plotPixel(cx + x, cy - y, c);
			// drawArea->plotPixel(cx - y, cy + x, c);
			// drawArea->plotPixel(cx - x, cy + y, c);
			drawArea->plotPixel(cx + y, cy - x, c);
			// drawArea->plotPixel(cx + x, cy + y, c);
			// drawArea->plotPixel(cx + y, cy + x, c);
			// drawArea->plotPixel(cx - x, cy - y, c);
			// drawArea->plotPixel(cx - y, cy - x, c);
		}
	}

	void DrawTask::drawLines(vector<Vector3> points, Vector3 offset)
	{
		static float theta = 0.1;
		R = Matrix3x3(
			cos(theta), -sin(theta), 0,
			sin(theta), cos(theta), 0,
			0, 0, 1);
		theta += 0.01;
		T1 = Matrix3x3(
			1, 0, offset[0],
			0, 1, offset[1],
			0, 0, 1);
		T2 = Matrix3x3(
			1, 0, -offset[0],
			0, 1, -offset[1],
			0, 0, 1);

		P = T1 * R * T2;

		// transform vertices
		for (auto iter = points.begin(); iter != points.end(); iter++)
		{
			*iter = P * (*iter);
		}

		// draw shape
		for (int i = 0; i < points.size(); i += 2)
		{
			drawDDALine(points[i].x, points[i].y, points[(i + 1) % 4].x, points[(i + 1) % 4].y, Colour(0, 0, 0, 255));
		}
	}

	void DrawTask::drawPie(int cx, int cy, int r, float theta)
	{
		int xtop = r * cos(theta);				 // plus use some trig to get top point
		int ytop = r * sin(theta);				 // plus use some trig to get top point
		float xstep = float(xtop) / float(ytop); // float(deltax) / deltay; need to calculate

		float x1 = cx;
		for (int y = 0; y < ytop; y++)
		{ // might have to reverse this for coord system
			x1 = cy + xstep * y;

			int x2 = sqrt(r * r - y * y); // not quite right

			// drawArea->plotPixel(x2 + cx, y - cy, Colour(0, 0, 0, 255));
			drawDDALine(x2 + cx, cy - y, x1, cy - y, Colour(0, 0, 0, 255));
		}
	}
	void DrawTask::drawArrow1(int x1, int y1, int x2, int y2, int r, int d)
	{
		int dx1 = x2;
		int xstep = float(abs(x1-x2))/float(abs(y1-y2));
		for (int y = y2; y<=y1; y++)
		{
			dx1 -= xstep;
			int dx2 = x1 + d + sqrt(r * r - (y - y1) * (y - y1));
			drawDDALine(dx1, y, dx2, y, Colour(0, 0, 0, 255));
		}
		for (int y = y1; y<=y1 + (y1 - y2); y++)
		{
			dx1 += xstep;
			int dx2 = x1 + d + sqrt(r * r - (y - y1) * (y - y1));
			drawDDALine(dx1, y, dx2, y, Colour(0, 0, 0, 255));
		}
	}
	void DrawTask::drawLineStrip(vector<Vector3> points)
	{
		for(int i = 0; i < points.size()-1; i++)
		{
			drawDDALine(points[i].x, points[i].y, points[i+1].x, points[i+1].y, Colour(0, 0, 0, 255));
		}
	}

	void DrawTask::update(float dt)
	{
		drawArea->clear(Colour(255, 255, 255, 255));

		vector<Vector3> points;
		points.push_back(Vector3(100, 100, 1));
		points.push_back(Vector3(200, 100, 1));
		points.push_back(Vector3(200, 200, 1));
		points.push_back(Vector3(100, 200, 1));

		drawLines(points, Vector3(200, 200, 1));
		// drawArea->plotPixel(200, 200, Colour(0, 0, 0, 255));

		DrawTaskTCircle(150, 150, 30, Colour(0, 0, 0, 255));
		DrawTaskPCircle(150, 150, 40, Colour(0, 0, 0, 255));
		drawPie(150, 150, 100, 45);

		drawArrow1(250, 250, 350, 200, 100, 200);
		drawLineStrip(points);
		// static float theta = 0.1;
		// R = Matrix3x3(
		// 	cos(theta), -sin(theta), 0,
		// 	sin(theta), cos(theta), 0,
		// 	0, 0, 1);
		// theta += 0.001;

		// Vector3 lines[4];

		// // transform vertices
		// for (auto iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
		// {
		// 	// vert[i].x =+ 1.0;

		// 	lines[i] = R * vert[i];
		// }

		// // draw shape
		// for (int i = 0; i < 4; i++)
		// {
		// 	drawDDALine(lines[i].x, lines[i].y, lines[(i + 1) % 4].x, lines[(i + 1) % 4].y, Colour(0, 0, 0, 255));
		// }

		app->getRenderer()->reloadTexture(drawArea);
	}

} // namespace T3D
