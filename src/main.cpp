#include "../inc/App.h"

void display(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
   App(argc, argv, "Title");
   App::Init(0.15, GL_FLAT);
   App::RegisterCallbackFuncs(display, reshape, mouse);
   App::Loop();

   return 0;
}


void display(void)
{
	App::Display([](auto ...args)
	{
		App::PrintToScreen("On screen message to be displayed fully.", GLUT_BITMAP_HELVETICA_12, -0.99f, 0.95f);
	});
}

void reshape(int w, int h)
{

}

void mouse(int button, int state, int x, int y)
{

}

