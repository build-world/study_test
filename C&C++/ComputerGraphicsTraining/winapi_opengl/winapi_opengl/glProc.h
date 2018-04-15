#pragma once
#include "stdafx.h"

#define PI 3.141592653589793

namespace mydef
{

extern void Init();
void ReSize(int width, int height);
void DispScene();
extern void DrawCircle(GLenum mode, GLfloat x, GLfloat y, GLfloat r, int TotalSample);

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

}