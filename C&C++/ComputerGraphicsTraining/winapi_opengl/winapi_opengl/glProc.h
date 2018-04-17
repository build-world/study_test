#pragma once
#include "stdafx.h"

#define PI 3.141592653589793

#define CMD_ZOOMIN 1
#define CMD_ZOOMOUT 2
#define CMD_NEAR 4
#define CMD_FAR 8
#define CMD_UP 16
#define CMD_DOWN 32
#define CMD_LEFT 64
#define CMD_RIGHT 128

#define DWIDTH 0.16
#define DHEIGHT 0.09
#define DMOVE 0.1

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

extern void Init();
extern void ReSize(int width, int height);
extern void ResetGLWin(int cmd);
extern void DispScene(mydef::Map *MapData);
extern void DrawCircle(GLenum mode, GLfloat x, GLfloat y, GLfloat r, int TotalSample);
extern void DrawPolygon(mydef::Polygon *pg);
extern void DrawMap(mydef::Map *MapData);

}