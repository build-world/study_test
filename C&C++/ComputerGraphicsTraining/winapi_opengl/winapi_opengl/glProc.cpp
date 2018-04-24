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
void SceneProc(int cmd, int width, int height, mydef::Map *MapData, mydef::pSP SetParam)
{
	using namespace mydef;
	static Map *save = NULL;
	static SP Param;
	int ReDrawFlag = NULL;
	int PolyCmdFlag = NULL;
	int cmdmax;
	if (MapData) save = MapData;
	//
	for (cmdmax = 1; cmdmax < cmd; cmdmax <<= 1);
	if (cmdmax != cmd)
	{
		PolyCmdFlag = 1;
		cmdmax >>= 1;
	}
	for (int ctr = 1; ctr <= cmdmax; ctr <<= 1)
	{
		int temp = cmd;
		if (PolyCmdFlag)
			temp &= ctr;
		switch (temp)
		{
		case CMD_GLINIT:
			{
				glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
			}
			break;
		case CMD_DISP:
			{
				ReDrawFlag = 1;
			}
			break;
		case CMD_ZOOMIN:
			{
				Param.fov -= Param.dzoom;
				ReDrawFlag = 1;
			}
			break;
		case CMD_ZOOMOUT:
			{
				Param.fov += Param.dzoom;
				ReDrawFlag = 1;
			}
			break;
		case CMD_UP:
			{
				Param.y += Param.dmove;
				ReDrawFlag = 1;
			}
			break;
		case CMD_DOWN:
			{
				Param.y -= Param.dmove;
				ReDrawFlag = 1;
			}
			break;
		case CMD_LEFT:
			{
				Param.x -= Param.dmove;
				ReDrawFlag = 1;
			}
			break;
		case CMD_RIGHT:
			{
				Param.x += Param.dmove;
				ReDrawFlag = 1;
			}
			break;
		case CMD_INVERSE:
			{
				Param.dmove *= -1.0;
			}
			break;
		case CMD_RESIZE:
			{
				if (width && height)
					Param.scale = width * 1.0 / height;
				glViewport(0, 0, width, height);
				ReDrawFlag = 1;
			}
			break;
		case CMD_SET:
			{
				Param.x = SetParam->x;
				Param.y = SetParam->y;
				Param.fov = SetParam->fov;
				//
				Param.dmove = SetParam->dmove;
				Param.dzoom = SetParam->dzoom;
				Param.Near = SetParam->Near;
				Param.Far = SetParam->Far;
			}
			break;
		case CMD_RESET:
			{
				Param.x = INIT_X;
				Param.y = INIT_Y;
				Param.fov = INIT_FOV;
				Param.scale = INIT_SCALE;
				Param.dmove = INIT_DMOVE;
				Param.dzoom = INIT_DZOOM;
				Param.Near = INIT_NEAR;
				Param.Far = INIT_FAR;
			}
			break;
		default:
			break;
		}
		if (!PolyCmdFlag)
			break;
	}
	if (ReDrawFlag)
	{
		/*
		GLdouble temp;
		temp = Param.scale * Param.fov;
		Param.Left = Param.x - temp;
		Param.Right = Param.x + temp;
		Param.Bottom = Param.y - Param.fov;
		Param.Top = Param.y + Param.fov;
		*/
		GLdouble tempx, tempy;
		tempy = std::sqrt((Param.fov * Param.fov) / (Param.scale * Param.scale + 1));
		tempx = Param.scale * tempy;
		Param.Left = Param.x - tempx;
		Param.Right = Param.x + tempx;
		Param.Bottom = Param.y - tempy;
		Param.Top = Param.y + tempy;
		//
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glColor3f(0.0f, 1.0f, 1.0f);
		glOrtho(Param.Left, Param.Right, Param.Bottom, Param.Top, Param.Near, Param.Far);
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
