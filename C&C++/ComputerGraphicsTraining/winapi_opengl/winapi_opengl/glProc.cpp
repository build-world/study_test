#include "stdafx.h"
#include "glProc.h"

namespace mydef
{

void Init()
{
	//glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClearDepth(1.0f);
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(110.0, 118.0, 30.0, 38.0, -1.0, 1.0);
}

void ReSize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(110.0, 118.0, 30.0, 38.0, -1.0, 1.0);
}

void DispScene(mydef::Map *MapData)
{
	using namespace mydef;
	//glViewport(0, 0, 1280, 720);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//glColor3f(1.0f, 1.0f, 1.0f);
	//glRectf(110.0f, 30.0f, 118.0f, 38.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glOrtho(110.0, 118.0, 30.0, 38.0, -1.0, 1.0);
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), TEXT("Draw Start!\n\n"), 13, NULL, NULL);
	LinkList<Polygon*> *cur = MapData->head;
	for (int ctr = 0; ctr < MapData->TotalPolygon; ctr++)
	{
		DrawPolygon(cur->obj);
		cur = cur->next;
	}
	glFlush();
}

void DrawCircle(GLenum mode, GLfloat x, GLfloat y, GLfloat r, int TotalSample)
{
	double dRad, Rad;
	int Sample;
	glBegin(mode);
	dRad = 2 * PI / TotalSample;
	for (Sample = 0, Rad = 0.0f; Sample < TotalSample; Sample++, Rad += dRad)
	{
		glVertex2f(x + r * cos(Rad), y + r * sin(Rad));
		//glFlush();
	}
	glEnd();
}

void DrawPolygon(mydef::Polygon *pg)
{
	using namespace mydef;
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//char strTemp[100];
	//sprintf(strTemp, "%d\n", pg->TotalPoint);
	//WriteConsoleA(hstdout, strTemp, lstrlenA(strTemp), NULL, NULL);
	LinkList<pMP> *cur = pg->head;
	//
	glBegin(GL_LINE_LOOP);
	for (int ctr = 0; ctr < pg->TotalPoint; ctr++)
	{
		//sprintf(strTemp, "%f  %f\n", cur->obj->lon, cur->obj->lat);
		//WriteConsoleA(hstdout, strTemp, lstrlenA(strTemp), NULL, NULL);
		glVertex3f(cur->obj->lon, cur->obj->lat, 0.0);
		cur = cur->next;
	}
	glEnd();
}

Polygon::Polygon(int TotalPoint)
{
	using namespace mydef;
	this->TotalPoint = TotalPoint;
	head = NULL;
	LinkList<pMP> **cur = &head;
	for (int ctr = 0; ctr < TotalPoint; ctr++)
	{
		*cur = new LinkList<pMP>;
		(*cur)->obj = new MP;
		(*cur)->next = NULL;
		cur = &((*cur)->next);
	}
}

Polygon::~Polygon()
{
	using namespace mydef;
	LinkList<pMP> *cur, *prev;
	cur = head;
	for (int ctr = 0; ctr < TotalPoint; ctr++)
	{
		prev = cur;
		cur = cur->next;
		delete prev->obj;
		delete prev;
	}
}

Map::Map()
{
}

Map::~Map()
{
	using namespace mydef;
	LinkList<Polygon*> *cur, *prev;
	cur = head;
	for (int ctr = 0; ctr < TotalPolygon; ctr++)
	{
		prev = cur;
		cur = cur->next;
		delete prev->obj;
		delete prev;
	}
}

}
