// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <Commdlg.h>//
#include <gl\GL.h>
#include <gl\GLU.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <math.h>

//C++
#include <iostream>
#include <fstream>
#include <cstdlib>

//Linker lib dependence
//#pragma comment (lib, "opengl32.lib")  /* link with Microsoft OpenGL lib */
//#pragma comment (lib, "glu32.lib")     /* link with OpenGL Utility lib */

#include <glut.h>
#pragma comment (lib, "glut32.lib")
#pragma comment (lib, "glut.lib")