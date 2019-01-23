#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "../inc/App.h"

App::App(int argc, char** argv, const char* name, void (*f)(void), void(*g)(void))
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(1280, 720);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(name);

   (*f)();
   
   glutDisplayFunc(g);
   

}

void App::Reshape(void(*f)(int w, int h))
{
	glutReshapeFunc(f);
}
