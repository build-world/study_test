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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	//glOrtho(110.0, 118.0, 30.0, 38.0, -1.0, 1.0);
}

void ResetGLWin(int cmd)
{
	static GLdouble
		Left = 106.0,
		Right = 122.0,
		Bottom = 30.0,
		Top = 39.0,
		Near = -1.0,
		Far = 1.0;
	switch (cmd)
	{
	case CMD_ZOOMIN:
		{
			Left += DWIDTH;
			Right -= DWIDTH;
			Bottom += DHEIGHT;
			Top -= DHEIGHT;
		}
		break;
	case CMD_ZOOMOUT:
		{
			Left -= DWIDTH;
			Right += DWIDTH;
			Bottom -= DHEIGHT;
			Top += DHEIGHT;
		}
		break;
	case CMD_NEAR:
		{
			
		}
		break;
	case CMD_FAR:
		{
			
		}
		break;
	case CMD_UP:
		{
			Bottom -= DMOVE;
			Top -= DMOVE;
		}
		break;
	case CMD_DOWN:
		{
			Bottom += DMOVE;
			Top += DMOVE;
		}
		break;
	case CMD_LEFT:
		{
			Left += DMOVE;
			Right += DMOVE;
		}
		break;
	case CMD_RIGHT:
		{
			Left -= DMOVE;
			Right -= DMOVE;
		}
		break;
	default:
		break;
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0f, 1.0f, 1.0f);
	glOrtho(Left, Right, Bottom, Top, Near, Far);
	DrawMap(NULL);
}

void DispScene(mydef::Map *MapData)
{
	using namespace mydef;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0f, 1.0f, 1.0f);
	glOrtho(106.0, 122.0, 30.0, 39.0, -1.0, 1.0);
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), TEXT("Draw Start!\n\n"), 13, NULL, NULL);
	DrawMap(MapData);
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

void DrawMap(mydef::Map *MapData)
{
	using namespace mydef;
	static Map *save;
	if (MapData) save = MapData;
	LinkList<Polygon*> *cur = save->head;
	for (int ctr = 0; ctr < save->TotalPolygon; ctr++)
	{
		DrawPolygon(cur->obj);
		cur = cur->next;
	}
	glFlush();
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
