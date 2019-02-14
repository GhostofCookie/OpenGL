#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdlib.h>
#include <stdio.h>    
#include <string> 
#include <queue>

#include <App.h>
#include <Object.h>

int App::w_width;
int App::w_height;
std::vector<Object*> App::_object_pool;

App::App(int argc, char** argv, const char* name, int w, int h)
{
	w_width = w;
	w_height = h;
	_object_pool = {};
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(w_width, w_height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(name);
	glutSetIconTitle("CoffeeEngine.ico");
}

void App::Init(float c, GLenum mode)
{
	glClearColor(c, c, c, 1.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glShadeModel(mode);
}

void App::Loop()
{
	glutMainLoop();
}

int App::Width()
{
	return w_width;
}

int App::Height()
{
	return w_height;
}

void App::Display(void (*lambda)())
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto it = _object_pool.begin(); it != _object_pool.end(); ++it)
		(*it)->Tick();

	(*lambda)();

	glutSwapBuffers();
}

void App::Reshape(int w, int h)
{
	if (!h) h = 1;

	glViewport(0, 0, w_width, w_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-w_width, w_width, -w_height, w_height, 1000, -1000);

	glMatrixMode(GL_MODELVIEW);
	w_width = w;
	w_height = h;
}

void App::PrintToScreen(const char * str, float x, float y, void * font, GL_Colour colour)
{
	glDisable(GL_LIGHTING);
	colour.UseColour();
	glRasterPos2f(x, y);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(font, *str++);
}

void App::PrintToScreen(const char* str, float x, float y, GL_Colour colour)
{
	PrintToScreen(str, x, y, GL_Font::HELVETICA, colour);
}

void App::AddObjectToPool(Object* obj)
{
	_object_pool.push_back(obj);
}

