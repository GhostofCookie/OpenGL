#include "../inc/App.h"

void display(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
   App(argc, argv, argv[0]);
   App::Init(0.15);
   App::RegisterCallbackFuncs(display, mouse, reshape);
   App::Loop();

   return 0;
}


void display(void)
{
   App::Display([](){
	 App::PrintToScreen("On screen message to be displayed fully.", -0.99f, 0.95f, GL_Colour::GL_Cyan);
   });
}

void reshape(int w, int h)
{

}

void mouse(int button, int state, int x, int y)
{

}

