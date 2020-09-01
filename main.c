# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>

#include "AXL.h"
#include "AX3L.h"



int main(int argc, char** argv){
	
	window* window = createWindow(50, 50, 1, 500, 500);
	ge* game_engine = initialize3Dge(window, 90.0, 1000.0, 0.1);

	float cube[12][12] = {//SOUTH
					{0.0, 0.0, 0.0, 0.0, 	0.0, 1.0, 0.0, 0.0, 	1.0, 1.0, 0.0, 0.0},
					{0.0, 0.0, 0.0, 0.0, 	1.0, 1.0, 0.0, 0.0, 	1.0, 0.0, 0.0, 0.0},

					//EAST
					{1.0, 0.0, 0.0, 0.0, 	1.0, 1.0, 0.0, 0.0, 	1.0, 1.0, 1.0, 0.0},
					{1.0, 0.0, 0.0, 0.0, 	1.0, 1.0, 1.0, 0.0, 	1.0, 0.0, 1.0, 0.0},
					
					//NORTH
					{1.0, 0.0, 1.0, 0.0, 	1.0, 1.0, 1.0, 0.0, 	0.0, 1.0, 1.0, 0.0},
					{1.0, 0.0, 1.0, 0.0, 	0.0, 1.0, 1.0, 0.0, 	0.0, 0.0, 1.0, 0.0},
					
					//WEST
					{0.0, 0.0, 1.0, 0.0, 	0.0, 1.0, 1.0, 0.0, 	0.0, 1.0, 0.0, 0.0},
					{0.0, 0.0, 1.0, 0.0, 	0.0, 1.0, 0.0, 0.0, 	0.0, 0.0, 0.0, 0.0},
					
					//TOP
					{0.0, 1.0, 0.0, 0.0, 	0.0, 1.0, 1.0, 0.0, 	1.0, 1.0, 1.0, 0.0},
					{0.0, 1.0, 0.0, 0.0, 	1.0, 1.0, 1.0, 0.0, 	1.0, 1.0, 0.0, 0.0},
					
					//BOTTOM
					{1.0, 0.0, 1.0, 0.0, 	0.0, 0.0, 1.0, 0.0, 	0.0, 0.0, 0.0, 0.0},
					{1.0, 0.0, 1.0, 0.0, 	0.0, 0.0, 0.0, 0.0, 	1.0, 0.0, 0.0, 0.0}};

	mesh* mshCube = initializeMesh(12);

	initializeCoords(mshCube, cube);


	while(1){
		XEvent e;
	    XNextEvent(window->display, &e); 
		


		switch (e.type){
			case Expose:
				
				break;
			case ButtonPress:
				
				break;
			case KeyPress:
				
				break;
			case ConfigureNotify:
				window->x = e.xconfigure.x;		window->y = e.xconfigure.y;		window->width = e.xconfigure.width;		window->height = e.xconfigure.height;
				update3Dge(window, game_engine, 90.0, 1000.0, 0.1);
			break;

			default : 
				break;
		}
	}

	return 0;
}		