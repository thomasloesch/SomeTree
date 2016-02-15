/*
*** FILE NAME   : main.c
*** DESCRIPTION : This program generates a cosine wave using the opengl libraries
*** DATE        : Jan. 29 2015
*** WRITTEN By  : Thomas Loesch
*** NOTES		: 
*/

#include <stdio.h>              // standard C libraries
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <GL/glut.h>            // GLUT library
#include "cs_graphics_setup.h"  // Header for CS4250/5250/6250 courses

//@@***********************************************************************************@@
// Constants
#define WINDOW_XS 600								// Window size
#define WINDOW_YS 600
#define WINDOW_NAME "Assignment 2 - Christmas Tree"	// Window name

//@@***********************************************************************************@@
// Structure
typedef struct pt2d
{
	GLint x, y;
}My2DPoint;

//@@***********************************************************************************@@
// Function prototypes
void display_func(void);
void keyboard_func(unsigned char c, int x, int y);
void mouse_func(int button, int state, int x, int y);
void loeschLineScan(int x1, int y1, int x2, int y2);
void drawMegaPixel(int x, int y);
void swapInts(int &a, int &b);


//@@***********************************************************************************@@
// Global Variables
int _x = 300;
int _y = 300;
int xAry[44];
int yAry[44];

//@@***********************************************************************************@@
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	init_setup(WINDOW_XS, WINDOW_YS, WINDOW_NAME);
	
	xAry[0] = 175;
	xAry[1] = 425;
	yAry[0] = 175;
	yAry[1] = 425;
	
	glutDisplayFunc(display_func);			// call back for display event
	glutKeyboardFunc(keyboard_func);		// call back for keyboard event
	glutMouseFunc(mouse_func);				// call back for mouse event

	glutMainLoop();							

	return 1;
}	// end of main()

//@@***********************************************************************************@@
void display_func(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);				// background color (white)
	glClear(GL_COLOR_BUFFER_BIT);					// clearing the buffer not to keep the color
	
	glColor3f(1.0, 1.0, 1.0);						// set color (grey)
	glLineWidth(1.0);

	loeschLineScan(xAry[1], yAry[1], xAry[0], yAry[0]);
	drawMegaPixel(200, 400);

	glColor3f(0.0, 0.0, 0.0);		// set color (black)


	glFlush();
}	// end of display_func()


//@@***********************************************************************************@@
void keyboard_func(unsigned char c, int x, int y)
{
	switch(c)
	{
		case 'a' :
		case 'A' :
			
			break;

		// shift right when 'd' key is pressed (Extra credit feature 2)
		case 'd' :
		case 'D' :
		
			break;

		case 'q' :
		case 'Q' :
			exit(1);
			break;

	}  // end of switch
}	// end of keyboard_func()


//@@***********************************************************************************@@
void mouse_func(int button, int state, int x, int y)
{
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		_x = x;
		_y = WINDOW_YS - y;
		
		glutPostRedisplay();
	}

}	// end of mouse_func()

// This is the Bresenham-based linescan function (DOES NOT use mega pixels)
void loeschLineScan(int x1, int y1, int x2, int y2) {
	if (x1 > x2) {
		swapInts(x1, x2);
		swapInts(y1, y2);
	}

	int dY = y2 - y1;
	int dX = x2 - x1;
	int dFa = 2 * (dY - dX);
	int dFb = 2 * dY;
	int p = 2 * dY - dX;
	int currX = 0;
	int currY = 0;

	if(dY >= 0 && dY <= 1) { // standard case
		glBegin(GL_POINTS);
		for (int k = 0; k < dX; k++) {
			if (p < 0) 
				p += dFb;
			else {
				currY++;
				p += dFa;
			}
			glVertex2i(x1 + k, y1 + currY);
		}
		glEnd();
	}
	else if (dY > 1) { // slope greater than 1
		
	}
	else if (dY < 0 && >= -1) { // negative slope
		
	}
	else { // slope must be negative and less than -1
		
	}
}

void drawMegaPixel(int x, int y) {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for (int i = -2; i <= 2; i++) {
		glVertex2i(_x - 2, (_y + i));
		glVertex2i(_x + 3, (_y + i));
	}
	glEnd();
}

void swapInts(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
