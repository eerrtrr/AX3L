#ifndef AX3L_H
#define AX3L_H

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "AXL.h"
#include "matrix.h"


//......................STRUCTS DEFINITIONS......................//

struct GAME_ENGINE{
	float a;			//	aspect ratio
	float FOV;
	float f;			//	1/tan(FOV/2)
	float Zfar, Znear;
	float q;			//	Zfar/(Zfar-Znear)
	matrix* projectionMatrix;
};
typedef struct GAME_ENGINE ge;

struct VECT_3D{
	matrix* coord;
};
typedef struct VECT_3D vect3d;

struct TRIANGLE{
	vect3d* p;
	unsigned char nbr;
};
typedef struct TRIANGLE triangle;

struct MESH{
	triangle* tris;
	triangle* projTris;
	int nbr;
};
typedef struct MESH mesh;


ge* initialize3Dge(window* win, float FOV, float Zfar, float Znear); 
void update3Dge(window* win, ge* game_engine, float FOV, float Zfar, float Znear);

vect3d initializeVect3d();
triangle initializeTriangle();
mesh* initializeMesh(int n);

void initializeCoords(mesh* msh, float coords[][12]);

void projection(mesh* obj, window* win, ge* ge);


void drawTriangles(mesh* obj, window* win, ge* ge);


#endif
