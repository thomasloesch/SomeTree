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
void drawMegaTree();
void drawGrid();
void drawPoints();
void lineTest();


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
	pointAry[12].x = 302;
	pointAry[12].y = 177;
	pointAry[13].x = 72;
	pointAry[13].y = 127;
	pointAry[14].x = 142;
	pointAry[14].y = 142;
	pointAry[15].x = 72;
	pointAry[15].y = 157;
	pointAry[16].x = 302;
	pointAry[16].y = 177;
	pointAry[17].x = 527;
	pointAry[17].y = 127;
	pointAry[18].x = 457;
	pointAry[18].y = 142;
	pointAry[19].x = 527;
	pointAry[19].y = 157;
	pointAry[20].x = 302;
	pointAry[20].y = 337;
	pointAry[21].x = 152;
	pointAry[21].y = 187;
	pointAry[22].x = 202;
	pointAry[22].y = 237;
	pointAry[23].x = 152;
	pointAry[23].y = 287;
	pointAry[24].x = 302;
	pointAry[24].y = 337;
	pointAry[25].x = 452;
	pointAry[25].y = 187;
	pointAry[26].x = 402;
	pointAry[26].y = 237;
	pointAry[27].x = 452;
	pointAry[27].y = 287;
	pointAry[28].x = 302;
	pointAry[28].y = 487;
	pointAry[29].x = 207;
	pointAry[29].y = 307;
	pointAry[30].x = 237;
	pointAry[30].y = 362;
	pointAry[31].x = 207;
	pointAry[31].y = 417;
	pointAry[32].x = 302;
	pointAry[32].y = 487;
	pointAry[33].x = 387;
	pointAry[33].y = 307;
	pointAry[34].x = 362;
	pointAry[34].y = 362;
	pointAry[35].x = 387;
	pointAry[35].y = 417;
	pointAry[36].x = 302;
	pointAry[36].y = 587;
	pointAry[37].x = 237;
	pointAry[37].y = 487;
	pointAry[38].x = 257;
	pointAry[38].y = 517;
	pointAry[39].x = 237;
	pointAry[39].y = 547;
	pointAry[40].x = 302;
	pointAry[40].y = 587;
	pointAry[41].x = 367;
	pointAry[41].y = 487;
	pointAry[42].x = 347;
	pointAry[42].y = 517;
	pointAry[43].x = 367;
	pointAry[43].y = 547;
	
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
	
	glColor3f(1.0, 1.0, 1.0); // white
	drawMegaTree();

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

	if (dX == 0) { // vertical line
		if (p1.y < p2.y) {
			glBegin(GL_POINTS);
			for (int i = 0; i < dY; i++)
				glVertex2i(p1.x, p1.y + i);
			glEnd();
		}
		else
		{
			glBegin(GL_POINTS);
			for (int i = 0; i < dY; i++)
				glVertex2i(p2.x, p2.y + i);
			glEnd();
		}
	}
	else if(m >= 0.0 && m <= 1.0) { // standard case
		dFa = 2 * (dY - dX);
		dFb = 2 * dY;
		p = 2 * dY - dX;

		glBegin(GL_POINTS);
		glVertex2i(p1.x, p1.y);
		for (int k = 1; k <= dX; k++) {
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
		glVertex2i(p1.x, p1.y);
		for (int k = 1; k <= dY; k++) {
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
		glVertex2i(p1.x, p1.y);
		for (int k = 1; k <= dX; k++) {
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
		dY *= -1;
		dFa = 2 * (dX - dY);
		dFb = 2 * dX;
		p = dX * 2 - dY;

		glBegin(GL_POINTS);
		glVertex2i(p1.x, p1.y);
		for (int k = 1; k <= dY; k++) {
			if (p < 0)
				p += dFb;
			else {
				currX++;
				p += dFa;
			}
			glVertex2i(p1.x + currX, p1.y - k);
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


	if (dX == 0) { // vertical line
		if (p1.y < p2.y) {
			for (int i = 0; i < dY - (dY % 5); i += 5)
				drawMegaPixel(p1.x, p1.y + i);
		}
		else
		{
			for (int i = 0; i < dY - (dY % 5); i += 5)
				drawMegaPixel(p2.x, p2.y + i);
		}
	}
	else if (m >= 0.0 && m <= 1.0) { // standard case
		dFa = 10 * dY - 10 * dX;
		dFb = 10 * dY;
		p = 10 * dY - 5 * dX;

		drawMegaPixel(p1.x, p1.y);
		for (int k = 5; k <= dX - (dX % 5); k += 5) {
			if (p < 0)
				p += dFb;
			else {
				currY += 5;
				p += dFa;
			}
			drawMegaPixel(p1.x + k, p1.y + currY);
		}
	}
	else if (m > 1.0) { // slope greater than 1
		dFa = 10 * (dX - dY);
		dFb = 10 * dX;
		p = 10 * dX - 5 * dY;

		drawMegaPixel(p1.x, p1.y);
		for (int k = 5; k <= dY - (dY % 5); k += 5) {
			if (p < 0)
				p += dFb;
			else {
				currX += 5;
				p += dFa;
			}
			drawMegaPixel(p1.x + currX, p1.y + k);
		}
	}
	else if (m < 0.0 && m >= -1.0) { // negative slope
		dFa = 10 * (dY + dX);
		dFb = 10 * dY;
		p = 10 * dY + 5 * dX;

		drawMegaPixel(p1.x, p1.y);
		for (int k = 5; k <= dX - (dX % 5); k += 5) {
			if (p > 0)
				p += dFb;
			else {
				currY += 5;
				p += dFa;
			}
			drawMegaPixel(p1.x + k, p1.y - currY);
		}
	}
	else { // slope must be negative and less than -1
		dY *= -1;
		dFa = 10 * (dX - dY);
		dFb = 10 * dX;
		p = 10 * dX - 5 * dY;

		drawMegaPixel(p1.x, p1.y);
		for (int k = 5; k <= dY - (dY % 5); k += 5) {
			if (p < 0)
				p += dFb;
			else {
				currX += 5;
				p += dFa;
			}
			drawMegaPixel(p1.x + currX, p1.y - k);
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

void drawMegaTree() {
	for (int i = 0; i < POINT_ARY_SIZE; i += 2)
		loeschLineScanMega(pointAry[i], pointAry[i + 1]);
}

void drawGrid() {
	glBegin(GL_LINES);
	for (int i = 5; i < WINDOW_YS; i += 5) {
		glVertex2i(0, i);
		glVertex2i(WINDOW_XS, i);
		glVertex2i(i, 0);
		glVertex2i(i, WINDOW_YS);
	}
	glEnd();
}

void drawPoints() {
	glBegin(GL_POINTS);
	for (int i = 0; i < POINT_ARY_SIZE; i++)
		glVertex2i(pointAry[i].x, pointAry[i].y);
	glEnd();
}

void lineTest() {
	My2DPoint testPoint1, testPoint2;

	testPoint1.x = 33;
	testPoint1.y = 101;
	testPoint2.x = 33;
	testPoint2.y = 400;
	loeschLineScanMega(testPoint1, testPoint2); // vert
	testPoint1.x = 40;
	testPoint1.y = 500;
	testPoint2.x = 270;
	testPoint2.y = 100;
	loeschLineScanMega(testPoint1, testPoint2); // -60
	testPoint1.x = 100;
	testPoint1.y = 500;
	testPoint2.x = 500;
	testPoint2.y = 100;
	loeschLineScanMega(testPoint1, testPoint2); // -45
	testPoint1.x = 150;
	testPoint1.y = 500;
	testPoint2.x = 500;
	testPoint2.y = 350;
	loeschLineScanMega(testPoint1, testPoint2); // -30
	testPoint1.x = 100;
	testPoint1.y = 550;
	testPoint2.x = 500;
	testPoint2.y = 550;
	loeschLineScanMega(testPoint1, testPoint2); // horiz
}
