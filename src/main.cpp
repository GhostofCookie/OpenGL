#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include "../inc/App.h"

void display(void);
void init(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
   App(argc, argv, "Title", init);
   //App::RegisterCallbackFuncs(display, reshape, mouse);
   App::RegisterFuncs(display, reshape, mouse);
   App::Loop();

   return 0;
}


void display(void)
{
	App::Display([](auto ...args)
	{
		App::PrintToScreen("This is text!", GLUT_BITMAP_HELVETICA_12);
	});
}

void init(void)
{
   glClearColor(0.25, 0.25, 0.25, 0.0);
   glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{

}

void mouse(int button, int state, int x, int y)
{

}

