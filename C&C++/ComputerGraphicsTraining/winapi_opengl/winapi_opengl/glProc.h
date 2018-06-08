#pragma once
#include "stdafx.h"

#define PI 3.141592653589793

//SceneProc cmd def
//exec cmd
//high priority
#define CMD_EXEC_RESIZE 1
#define CMD_EXEC_DISP 2
//medium priority
#define CMD_EXEC_ZOOMIN 4
#define CMD_EXEC_ZOOMOUT 8
#define CMD_EXEC_UP 16
#define CMD_EXEC_DOWN 32
#define CMD_EXEC_LEFT 64
#define CMD_EXEC_RIGHT 128
#define CMD_EXEC_ROLLLEFT 256
#define CMD_EXEC_ROLLRIGHT 512
#define CMD_EXEC_PITCHUP 1024
#define CMD_EXEC_PITCHDOWN 2048
#define CMD_EXEC_YAWLEFT 4096
#define CMD_EXEC_YAWRIGHT 8192
//low priority
#define CMD_EXEC_INIT 16384
#define CMD_EXEC_SET 32768
//#define CMD_EXEC_RESET_ALL 65536
#define CMD_EXEC_INVERSE 131072

//def cmd
#define CMD_DEF_ORTHO 262144
#define CMD_DEF_FRUSTUM 524288


//status def
#define PROJ_ORTHO 1
#define PROJ_FRUSTUM 2

/*
//init values
//view point value
#define INIT_MAP_CENTERX 114.0
#define INIT_MAP_CENTERY 34.0
#define INIT_MAP_CENTERZ 0.0
#define INIT_MAP_EYEX 114.0
#define INIT_MAP_EYEY 34.0
#define INIT_MAP_EYEZ 16.0
#define INIT_MAP_UPX 0.0
#define INIT_MAP_UPY 1.0
#define INIT_MAP_UPZ 0.0

#define INIT_FOV 0.5 //n*PI
#define INIT_SCALE 16.0/9


#define INIT_NEAR -100.0
#define INIT_FAR 100.0

#define INIT_ROLL 0.5 
#define INIT_PITCH 0.5
#define INIT_YAW 0.5



#define INIT_DMOVE -0.1
#define INIT_DZOOM 1.0/180 //n*PI
#define INIT_DROTATE 1.0/180 //n*PI
*/

//ParamInitMode
#define PARAM_INIT_MAP 1
#define PARAM_INIT_TEAPOT 2


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

typedef class SceneParam
{
public:
	GLdouble
		centerx,
		centery,
		centerz,
		eyex,
		eyey,
		eyez,
		upx,
		upy,
		upz,
		//
		Near,
		Far,
		//
		fov,
		//
		roll,
		pitch,
		yaw,
		//
		dmove,
		dzoom,
		drotate;
}SP, *pSP;

typedef class SceneInnerParam :public SceneParam
{
public:
	GLdouble
		Left,
		Right,
		Bottom,
		Top,
		scale,
		distance;
	int projf;
}SIP, *pSIP;

typedef struct CurvePoint
{
	double x;
	double y;
}CP, *pCP;

extern void Init();
extern void SceneProc(int cmd, int width, int height, mydef::Map *MapData, mydef::pSP SetParam);
extern void DrawCircle(GLenum mode, GLfloat x, GLfloat y, GLfloat r, int TotalSample);
extern void DrawPolygon(mydef::Polygon *pg);
extern void DrawMap(mydef::Map *MapData);
extern void BezierCurve0(mydef::pCP CtrlPoint, unsigned int PointNum, double dt);
extern void ParamInit(mydef::pSP Param, int InitMode);

}