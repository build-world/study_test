#pragma once
#include "stdafx.h"

#define PI 3.141592653589793

//#define CMD_POLYCMD 1
#define CMD_GLINIT 1
#define CMD_DISP 2
#define CMD_ZOOMIN 4
#define CMD_ZOOMOUT 8
#define CMD_UP 16
#define CMD_DOWN 32
#define CMD_LEFT 64
#define CMD_RIGHT 128
#define CMD_INVERSE 256
#define CMD_RESIZE 512
#define CMD_SET 1024
#define CMD_RESET 2048

#define INIT_X 114.0
#define INIT_Y 34.0
#define INIT_FOV 4.0
#define INIT_SCALE 16.0/9
#define INIT_DMOVE -0.1
#define INIT_DZOOM 0.1
#define INIT_NEAR -1.0
#define INIT_FAR 1.0


namespace mydef
{

template<class Elem> class LinkList
{
public:
	class LinkList<Elem> *next;
	Elem obj;
};

typedef class MapPoint
{
public:
	double lon;
	double lat;
}MP, *pMP;

class Polygon
{
public:
	int TotalPoint;
	LinkList<pMP> *head;
	Polygon(int TotalPoint);
	~Polygon();
};

class Map
{
public:
	int TotalPolygon;
	LinkList<Polygon*> *head;
	Map();
	~Map();
};

typedef struct SceneParam
{
	GLdouble
		x,
		y,
		fov,
		scale,
		dmove,
		dzoom,
		Near,
		Far,
		//
		Left,
		Right,
		Bottom,
		Top;
}SP, *pSP;

extern void Init();
extern void SceneProc(int cmd, int width, int height, mydef::Map *MapData, mydef::pSP SetParam);
extern void DrawCircle(GLenum mode, GLfloat x, GLfloat y, GLfloat r, int TotalSample);
extern void DrawPolygon(mydef::Polygon *pg);
extern void DrawMap(mydef::Map *MapData);

}