#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdlib.h>
#include <stdio.h>    
#include <string.h> 

#include <queue>

#include "../inc/App.h"

App::App(int argc, char** argv, const char* name, int w, int h)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(w, h);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(name);
}

void App::Init(float c, GLenum mode)
{
	glClearColor(c, c, c, 1.0);
	glShadeModel(mode);
}

void App::Loop()
{
	glutMainLoop();
}

void App::Display(void (*lambda)())
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	(*lambda)();
	glPopMatrix();
	glutSwapBuffers();
}

void App::Reshape(int w, int h)
{
	glutReshapeWindow(w, h);
}

void App::PrintToScreen(const char * str, float x, float y, void * font, GL_Colour::Colour colour)
{
	glDisable(GL_LIGHTING);
	colour;
	glRasterPos2f(x, y);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(font, *str++);
	glEnable(GL_LIGHTING);
}

void App::PrintToScreen(const char* str, float x, float y, GL_Colour::Colour colour)
{
	PrintToScreen(str, x, y, GL_Font::HELVETICA, colour);
}

