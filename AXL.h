#ifndef AXL_H
#define AXL_H


#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>


//......................STRUCTS DEFINITIONS......................//

struct WINDOW{
	Display* display;
	Window window;
	int screen; 
	GC gc;
	unsigned int x, y, border_width, width, height;
	unsigned long border;
    unsigned long background;
	Colormap cmap;
};
typedef struct WINDOW window;


struct POINTS{
	XPoint* points;
	unsigned int nbr;
};
typedef struct POINTS points;


struct LINES{
	XPoint* lines;
	unsigned int nbr;
};
typedef struct LINES lines;




//......................FUNCTIONS PROTOTYPES......................//


//Display stuff
window* createWindow(unsigned int x, unsigned int y, unsigned int border_width, unsigned int width, unsigned int height);
void setColor(window* win, unsigned long color);
unsigned long addColor(window* win, int r, int g, int b);

//Structs creation
points* createPointList(unsigned int nbr, short coords[][2]);


//Drawing functions
void drawPoint(window* win, unsigned int x, unsigned int y);
void drawPoints(window* win, points* pts);

void drawLine(window* win, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void drawLines(window* win, points* pts);

void drawSqare(window* win, unsigned int x, unsigned int y, unsigned int length, bool fill);
void drawRectangle(window* win, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool fill);
void drawTriangle(window* win, unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, bool fill);
void drawCircle(window* win, unsigned int x, unsigned int y, unsigned int radius, bool fill);
void drawElipse(window* win, unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int angle1, unsigned int angle2, bool fill);

void cleanWindow(window* win);

#endif