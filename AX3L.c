#include "AX3L.h"



ge* initialize3Dge(window* win, float FOV, float Zfar, float Znear){
    ge* game_engine = malloc(sizeof(ge));

    game_engine->a = (float)win->height/win->width;
    game_engine->FOV = FOV;
    game_engine->f = 1/tanf(FOV/(360.0*3.14159));	
	game_engine->Zfar = Zfar;
    game_engine->Znear = Znear;
	game_engine->q = Zfar/(Zfar-Znear);			//	Zfar/(Zfar-Znear)


    //PROJECTION MATRIX
    /*
                game_engine->a*game_engine->f    0.0                     0.0                                        0.0 
                0.0                              game_engine->f          0.0                                        0.0 
                0.0                              0.0                     game_engine->q                             1.0 
                0.0                              0.0                     -1*game_engine->Znear*game_engine->q       0.0
    */

	game_engine->projectionMatrix = initializeMatrix(4, 4);
    game_engine->projectionMatrix->data[0][0] = game_engine->a*game_engine->f;
    game_engine->projectionMatrix->data[1][1] = game_engine->f;
    game_engine->projectionMatrix->data[2][2] = game_engine->q;  game_engine->projectionMatrix->data[2][3] = 1.0;
    game_engine->projectionMatrix->data[3][2] = -1*game_engine->Znear*game_engine->q;


    return game_engine;
}


void update3Dge(window* win, ge* game_engine, float FOV, float Zfar, float Znear){
    game_engine->a = (float)win->height/win->width;
    game_engine->FOV = FOV;
    game_engine->f = 1/tan(FOV/2);	
	game_engine->Zfar = Zfar;
    game_engine->Znear = Znear;
	game_engine->q = Zfar/(Zfar-Znear);			//	Zfar/(Zfar-Znear)


    game_engine->projectionMatrix->data[0][0] = game_engine->a*game_engine->f;
    game_engine->projectionMatrix->data[1][1] = game_engine->f;
    game_engine->projectionMatrix->data[2][2] = game_engine->q;  game_engine->projectionMatrix->data[2][3] = 1.0;
    game_engine->projectionMatrix->data[3][2] = -1*game_engine->Znear*game_engine->q;
}



vect3d initializeVect3d(){
    vect3d vec;
    vec.coord = initializeMatrix(1, 4);  

    return vec;
}

triangle initializeTriangle(){
    triangle tri;
    tri.nbr = 3;
    tri.p = malloc(3*sizeof(vect3d));
    for(int i=0; i<3; i++){
        tri.p[i] = initializeVect3d();
    }

    return tri;
}

mesh* initializeMesh(int n){
    mesh* msh = malloc(sizeof(mesh));
    msh->nbr = n;
    msh->tris = malloc(n*sizeof(triangle));
    for(int i=0; i<n; i++){
        msh->tris[i] = initializeTriangle();
    } 
    
    return msh;
}


void initializeCoords(mesh* msh, float coords[][12]){
    for(int i=0; i<msh->nbr; i++){
        msh->tris[i].p[0].coord->data[0][0] = coords[i][0];
        msh->tris[i].p[0].coord->data[0][1] = coords[i][1];
        msh->tris[i].p[0].coord->data[0][2] = coords[i][2];
        msh->tris[i].p[0].coord->data[0][3] = coords[i][3];

        msh->tris[i].p[1].coord->data[0][0] = coords[i][4];
        msh->tris[i].p[1].coord->data[0][1] = coords[i][5];
        msh->tris[i].p[1].coord->data[0][2] = coords[i][6];
        msh->tris[i].p[1].coord->data[0][3] = coords[i][7];

        msh->tris[i].p[2].coord->data[0][0] = coords[i][8];
        msh->tris[i].p[2].coord->data[0][1] = coords[i][9];
        msh->tris[i].p[2].coord->data[0][2] = coords[i][10];
        msh->tris[i].p[2].coord->data[0][3] = coords[i][11];
    }
}



void projection(mesh* obj, window* win, ge* ge){
    for(int i=0; i<obj->nbr; i++){
        triangle triProj = initializeTriangle();
        triProj.p[0].coord = mulMatrix(obj->tris[i].p[0].coord, ge->projectionMatrix, true);
        triProj.p[1].coord = mulMatrix(obj->tris[i].p[1].coord, ge->projectionMatrix, true);
        triProj.p[2].coord = mulMatrix(obj->tris[i].p[2].coord, ge->projectionMatrix, true);
    }
}