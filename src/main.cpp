#include <App.h>
#include <Core.h>
#include <Cube.h>

void Setup();
void Display();
void Mouse(int button, int state, int x, int y);
void Keyboard(unsigned char, int, int) {}
void MousePassive(int x, int y);

Cube* cube, *cube2, *cube3;

int main(int argc, char** argv)
{
	App(argc, argv, argv[0], 1280, 720);
	App::RegisterCallbackFuncs(Display, Mouse, NULL, MousePassive);
	App::Init(0.f);

	Setup();

	App::Loop();

	delete cube, cube2, cube3;
	return 0;
}

void Setup()
{
	cube	= new Cube(0.f, 0.f, 0.f, GL_Colour::Cyan);
	cube->SetScale(0.5f, 0.5f, 0.5f);
	cube2	= new Cube(0.f, 100.f, 0.f, GL_Colour::Green);
	cube2->SetScale(GLScale(0.1f, 0.1f, 1.f));
	cube3	= new Cube(GL_Colour(1.f, 0.f, 0.f, .1f));
}

void Display(void)
{
	App::Display([]() {
		App::PrintToScreen("Showing imported FBX mesh",
			-App::Width()+10, App::Height() - 30, GL_Colour::Emerald);

		cube->Rotate(GLRotator(0, 0.5, 0));
		cube2->Rotate(GLRotator(1, 1.f, 0));
	});
}

void Mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case  GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			cube->Translate(0.f, 10.f, 0.f);
			cube3->Rotate(GLRotator(1.f, 1.f, 0.f));
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			cube->Translate(0.f, -10.f, 0.f);
			cube3->Rotate(GLRotator(-1.f, -1.f, 0.f));
		}
		break;
	}
}

void MousePassive(int x, int y)
{
	cube3->SetLocation(GLVector(x * 2 - App::Width(), -y * 2 + App::Height()));
}

