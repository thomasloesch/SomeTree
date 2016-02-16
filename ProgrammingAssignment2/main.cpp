/*
*** FILE NAME   : main.cpp
*** DESCRIPTION : This program generates a tree using a self-made implementation of a Bresenham line scan.
*** DATE        : Jan. 29 2015
*** WRITTEN By  : Thomas Loesch
*** NOTES		: 
*/

#include <stdio.h>              // standard libraries
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
void loeschLineScan(My2DPoint p1, My2DPoint p2);
void drawMegaPixel(int x, int y);
void swapInts(int &a, int &b);
void swapPoints(My2DPoint &a, My2DPoint &b);


//@@***********************************************************************************@@
// Global Variables
int _x = 300;
int _y = 300;
My2DPoint pointAry[22];

//@@***********************************************************************************@@
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	init_setup(WINDOW_XS, WINDOW_YS, WINDOW_NAME);
	
	pointAry[0].x = 175;
	pointAry[0].y = 425;
	pointAry[1].x = 200;
	pointAry[1].y = 200;
	
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

	My2DPoint mousePt;
	mousePt.x = _x;
	mousePt.y = _y;
	loeschLineScan(pointAry[0], mousePt);
//	drawMegaPixel(200, 400);

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
void loeschLineScan(My2DPoint p1, My2DPoint p2) {
	if (p1.x > p2.x)		// if the points are in the wrong order, swap them first
		swapPoints(p1, p2);

	int dY = p2.y - p1.y;
	int dX = p2.x - p1.x;
	float m = (float)dY / (float)dX; // slope
	int dFa;
	int dFb;
	int p;
	int currX = 0;
	int currY = 0;

	if(m >= 0.0 && m <= 1.0) { // standard case
		dFa = 2 * (dY - dX);
		dFb = 2 * dY;
		p = 2 * dY - dX;

		glBegin(GL_POINTS);
		for (int k = 0; k <= dX; k++) {
			if (p < 0) 
				p += dFb;
			else {
				currY++;
				p += dFa;
			}
			glVertex2i(p1.x + k, p1.y + currY);
		}
		glEnd();
	}
	else if (m > 1.0) { // slope greater than 1
		dFa = 2 * (dX - dY);
		dFb = 2 * dX;
		p = 2 * dX - dY;

		glBegin(GL_POINTS);
		for (int k = 0; k <= dY; k++) {
			if (p < 0)
				p += dFb;
			else {
				currX++;
				p += dFa;
			}
			glVertex2i(p1.x + currX, p1.y + k);
		}
		glEnd();
	}
	else if (m < 0.0 && m >= -1.0) { // negative slope
		dFa = 2 * (dY + dX);
		dFb = 2 * dY;
		p = 2 * dY + dX;

		glBegin(GL_POINTS);
		for (int k = 0; k <= dX; k++) {
			if (p > 0)
				p += dFb;
			else {
				currY++;
				p += dFa;
			}
			glVertex2i(p1.x + k, p1.y - currY);
		}
		glEnd();
	}
	else { // slope must be negative and less than -1
		dFa = 2 * (dY + dX);
		dFb = 2 * dX;
		p = dY - 2 * dX;

		glBegin(GL_POINTS);
		for (int k = 0; k >= dY; k--) {
			if (p < 0)
				p += dFb;
			else {
				currX++;
				p += dFa;
			}
			glVertex2i(p1.x + currX, p1.y + k);
		}
		glEnd();
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

void swapPoints(My2DPoint &a, My2DPoint &b) {
	My2DPoint temp = a;
	a = b;
	b = temp;
}