#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#include <stdlib.h>
#include <stdio.h>    
#include <string.h> 

#include "../inc/App.h"

App::App(int argc, char** argv, const char* name, void (*f)(void))
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(1280, 720);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(name);

   (*f)();

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

void App::PrintToScreen(const char* str, void * font)
{
	int i, len = strlen(str);

	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, *str++);
}
