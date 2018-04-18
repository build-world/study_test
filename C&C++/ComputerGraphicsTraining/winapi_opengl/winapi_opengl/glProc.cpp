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
void SceneProc(int cmd, int width, int height, mydef::Map *MapData)
{
	static Map *save = NULL;
	static GLdouble
		x = INIT_X,
		y = INIT_Y,
		fov = INIT_FOV,
		scale = INIT_SCALE,
		dmove = INIT_DMOVE,
		dzoom = INIT_DZOOM,
		//
		Near = INIT_NEAR,
		Far = INIT_FAR,
		//
		Left = 0.0,
		Right = 0.0,
		Bottom = 0.0,
		Top = 0.0;
	int ReDrawFlag = NULL;
	if (MapData) save = MapData;
	//
	switch (cmd)
	{
	case CMD_DISP:
		{
			ReDrawFlag = 1;
		}
		break;
	case CMD_ZOOMIN:
		{
			fov -= dzoom;
			ReDrawFlag = 1;
		}
		break;
	case CMD_ZOOMOUT:
		{
			fov += dzoom;
			ReDrawFlag = 1;
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
			y += dmove;
			ReDrawFlag = 1;
		}
		break;
	case CMD_DOWN:
		{
			y -= dmove;
			ReDrawFlag = 1;
		}
		break;
	case CMD_LEFT:
		{
			x -= dmove;
			ReDrawFlag = 1;
		}
		break;
	case CMD_RIGHT:
		{
			x += dmove;
			ReDrawFlag = 1;
		}
		break;
	case CMD_INVERSE:
		{
			dmove *= -1.0;
		}
		break;
	case CMD_RESIZE:
		{
			if (width && height)
				scale = width * 1.0 / height;
			glViewport(0, 0, width, height);
			ReDrawFlag = 1;
		}
		break;
	default:
		break;
	}
	if (ReDrawFlag)
	{
		GLdouble temp;
		temp = scale * fov;
		Left = x - temp;
		Right = x + temp;
		Bottom = y - fov;
		Top = y + fov;
		//
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glColor3f(0.0f, 1.0f, 1.0f);
		glOrtho(Left, Right, Bottom, Top, Near, Far);
		if (save) DrawMap(save);
	}
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
	//HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
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
	LinkList<Polygon*> *cur = MapData->head;
	for (int ctr = 0; ctr < MapData->TotalPolygon; ctr++)
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
