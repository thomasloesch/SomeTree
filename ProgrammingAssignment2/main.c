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


//@@***********************************************************************************@@
// Global Variables


//@@***********************************************************************************@@
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	init_setup(WINDOW_XS, WINDOW_YS, WINDOW_NAME);
	
	
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
	
	glColor3f(0.7, 0.7, 0.7);						// set color (grey)
	glLineWidth(1.0);


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

		glutPostRedisplay();
	}

}	// end of mouse_func()

// This is the Bresenham-based linescan function
void loeschLineScan(int x1, int y1, int x2, int y2) {


}

void drawMegaPixel(int x, int y) {

}