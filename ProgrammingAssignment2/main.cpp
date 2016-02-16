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
void loeschLineScanMega(My2DPoint p1, My2DPoint p2);
void drawMegaPixel(int x, int y);
void swapInts(int &a, int &b);
void swapPoints(My2DPoint &a, My2DPoint &b);
void drawTree();


//@@***********************************************************************************@@
// Global Variables
int _x = 425;
int _y = 425;
const int POINT_ARY_SIZE = 44;
My2DPoint pointAry[POINT_ARY_SIZE];

//@@***********************************************************************************@@
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	init_setup(WINDOW_XS, WINDOW_YS, WINDOW_NAME);
	
	pointAry[0].x = 237;
	pointAry[0].y = 12;
	pointAry[1].x = 362;
	pointAry[1].y = 12;
	pointAry[2].x = 302;
	pointAry[2].y = 12;
	pointAry[3].x = 302;
	pointAry[3].y = 587;
	pointAry[4].x = 302;
	pointAry[4].y = 92;
	pointAry[5].x = 12;
	pointAry[5].y = 62;
	pointAry[6].x = 12;
	pointAry[6].y = 82;
	pointAry[7].x = 107;
	pointAry[7].y = 72;
	pointAry[8].x = 302;
	pointAry[8].y = 92;
	pointAry[9].x = 587;
	pointAry[9].y = 62;
	pointAry[10].x = 587;
	pointAry[10].y = 82;
	pointAry[11].x = 492;
	pointAry[11].y = 72;
	pointAry[12].x = 0;
	pointAry[12].y = 0;
	pointAry[13].x = 0;
	pointAry[13].y = 0;
	pointAry[14].x = 0;
	pointAry[14].y = 0;
	pointAry[15].x = 0;
	pointAry[15].y = 0;
	pointAry[16].x = 0;
	pointAry[16].y = 0;
	pointAry[17].x = 0;
	pointAry[17].y = 0;
	pointAry[18].x = 0;
	pointAry[18].y = 0;
	pointAry[19].x = 0;
	pointAry[19].y = 0;
	pointAry[20].x = 0;
	pointAry[20].y = 0;
	pointAry[21].x = 0;
	pointAry[21].y = 0;
	pointAry[22].x = 0;
	pointAry[22].y = 0;
	pointAry[23].x = 0;
	pointAry[23].y = 0;
	pointAry[24].x = 0;
	pointAry[24].y = 0;
	pointAry[25].x = 0;
	pointAry[25].y = 0;
	pointAry[26].x = 0;
	pointAry[26].y = 0;
	pointAry[27].x = 0;
	pointAry[27].y = 0;
	pointAry[28].x = 0;
	pointAry[28].y = 0;
	pointAry[29].x = 0;
	pointAry[29].y = 0;
	pointAry[30].x = 0;
	pointAry[30].y = 0;
	pointAry[31].x = 0;
	pointAry[31].y = 0;
	pointAry[32].x = 0;
	pointAry[32].y = 0;
	pointAry[33].x = 0;
	pointAry[33].y = 0;
	pointAry[34].x = 0;
	pointAry[34].y = 0;
	pointAry[35].x = 0;
	pointAry[35].y = 0;
	pointAry[36].x = 0;
	pointAry[36].y = 0;
	pointAry[37].x = 0;
	pointAry[37].y = 0;
	pointAry[38].x = 0;
	pointAry[38].y = 0;
	pointAry[39].x = 0;
	pointAry[39].y = 0;
	pointAry[40].x = 0;
	pointAry[40].y = 0;
	pointAry[41].x = 0;
	pointAry[41].y = 0;
	pointAry[42].x = 0;
	pointAry[42].y = 0;
	
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
	//loeschLineScanMega(pointAry[0], pointAry[1]);
	//loeschLineScan(pointAry[0], pointAry[5]);
	//loeschLineScan(pointAry[0], pointAry[1]);
	//loeschLineScan(pointAry[1], pointAry[5]);
//	drawMegaPixel(200, 400);

	drawTree();

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

void loeschLineScanMega(My2DPoint p1, My2DPoint p2) {
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

	if (m >= 0.0 && m <= 1.0) { // standard case
		dFa = 10 * dY - 10 * dX;
		dFb = 10 * dY;
		p = 10 * dY - 5 * dX;

		for (int k = 0; k <= dX; k += 5) {
			if (p < 0)
				p += dFb;
			else {
				currY += 5;
				p += dFa;
			}
			drawMegaPixel(p1.x + k, p1.y + currY);
		}
	}
	else if (m > 1.0) { // slope greater than 1 NYI
		dFa = 2 * (dX - dY);
		dFb = 2 * dX;
		p = 2 * dX - dY;

		for (int k = 0; k <= dY; k++) {
			if (p < 0)
				p += dFb;
			else {
				currX++;
				p += dFa;
			}
			drawMegaPixel(p1.x + currX, p1.y + k);
		}
	}
	else if (m < 0.0 && m >= -1.0) { // negative slope NYI
		dFa = 2 * (dY + dX);
		dFb = 2 * dY;
		p = 2 * dY + dX;

		for (int k = 0; k <= dX; k++) {
			if (p > 0)
				p += dFb;
			else {
				currY++;
				p += dFa;
			}
			drawMegaPixel(p1.x + k, p1.y - currY);
		}
	}
	else { // slope must be negative and less than -1 NYI
		dFa = 2 * (dY + dX);
		dFb = 2 * dX;
		p = dY - 2 * dX;

		for (int k = 0; k >= dY; k--) {
			if (p < 0)
				p += dFb;
			else {
				currX++;
				p += dFa;
			}
			if (k % 5 == 0)
				drawMegaPixel(p1.x + currX, p1.y + k);
		}
	}
}

void drawMegaPixel(int x, int y) {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for (int i = -2; i <= 2; i++) {
		glVertex2i(x - 2, (y + i));
		glVertex2i(x + 3, (y + i));
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

void drawTree() {
	for (int i = 0; i < POINT_ARY_SIZE; i += 2)
		loeschLineScan(pointAry[i], pointAry[i + 1]);
}