#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdlib.h>
#include <stdio.h>    
#include <cstring>

#include <App.h>
#include <Core.h>
#include <Object.h>
#include <Engine/EngineUI.h>

int App::_width;
int App::_height;
std::vector<Object*> App::_object_pool;

App::App(int argc, char** argv, const char* name, int w, int h)
{
	_width = w;
	_height = h;
	_object_pool = {};
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(_width, _height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(name);
	glutSetIconTitle("CoffeeEngine.ico");
}

void App::Init(float c, GLenum mode)
{
	glClearColor(c, c, c, 1.0);
	glClearDepth(1.0);
	
	// Enable depth testing.
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Enable transparency.
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Enable Lighting
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);
	glEnable(GL_COLOR_MATERIAL);
	

	glShadeModel(mode);
}

void App::Loop()
{
	glutMainLoop();
}

int App::Width()
{
	return _width;
}

int App::Height()
{
	return _height;
}

void App::Display(void (*lambda)())
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto it = _object_pool.begin(); it != _object_pool.end(); ++it)
		(*it)->Tick();

	(*lambda)();

	UI_Panel panel(0, -App::Height(), App::Width(), 300);
	panel.Render();
	glutSwapBuffers();
}

void App::Reshape(int w, int h)
{
	if (!h) h = 1;

	glViewport(0, 0, _width, _height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-_width, _width, -_height, _height, -1000, 1000);

	glMatrixMode(GL_MODELVIEW);
	_width = w;
	_height = h;
}

void App::PrintToScreen(const char * str, float x, float y, GL_Font font, GL_Colour colour)
{
	glDisable(GL_LIGHTING);
	colour.UseColour();
	glRasterPos2f(x, y);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(font.GetFont(), *str++);
	 glEnable(GL_LIGHTING);
}

void App::PrintToScreen(const char* str, float x, float y, GL_Colour colour)
{
	PrintToScreen(str, x, y, GL_Font::HELVETICA, colour);
}

void App::AddObjectToPool(Object* obj)
{
	_object_pool.push_back(obj);
}

