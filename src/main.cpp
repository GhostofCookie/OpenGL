#include <App.h>
#include <Cube.h>
#include <string>

void display();
void mouse(int button, int state, int x, int y);
void mouse_passive(int x, int y);

Cube cube(300, -100, 300, GL_Colour::GL_Blue);
Cube cube2(0, 100, 0, GL_Colour::GL_Green);
Cube cube3(-200, 100, 0, GL_Colour::GL_Red);

int main(int argc, char** argv)
{
   App(argc, argv, argv[0]);
   App::RegisterCallbackFuncs(display, mouse, mouse_passive);
   App::Init(0.1f, GL_SMOOTH);
   App::Loop();

   return 0;
}

void display(void)
{
   App::Display([](){
	   std::string str = GET_OBJECT_NAME(cube)" : X = ";
	   str.append(std::to_string(cube.GetTransform().x));
	   str.append(", Y = ");
	   str.append(std::to_string(cube.GetTransform().y));
	   str.append(", Z = ");
	   str.append(std::to_string(cube.GetTransform().z));
	   App::PrintToScreen(str.c_str(), -720, 460, GL_Colour::GL_Emerald);


	   str = GET_OBJECT_NAME(cube2)" : X = ";
	   str.append(std::to_string(cube2.GetTransform().x));
	   str.append(", Y = ");
	   str.append(std::to_string(cube2.GetTransform().y));
	   str.append(", Z = ");
	   str.append(std::to_string(cube2.GetTransform().z));
	   App::PrintToScreen(str.c_str(), -720, 430, GL_Colour::GL_Emerald);
	   
	   cube.Render();
	   cube2.Render();
	   cube3.Render();
	   cube.Rotate(1, GL_Transform::GLVector(0, 0, 0), GL_Transform::GLVector(1, 1, 1));
	   cube2.Rotate(-1, GL_Transform::GLVector(0, 0, 0), GL_Transform::GLVector(1, -1, 1));


   });
}

void mouse(int button, int state, int x, int y)
{
   switch (button)
   {
      case  GLUT_LEFT_BUTTON:
	 if (state == GLUT_DOWN)
	 {
	    glutPassiveMotionFunc(mouse_passive);
	    cube.Translate(0.f, 10.f, 0.f);
	    cube3.Rotate(-1, GL_Transform::GLVector(0, 0, 0), GL_Transform::GLVector(1, -1, 1));
	 }
//	 else 
//	    glutPassiveMotionFunc(NULL);
	 break;
      case GLUT_RIGHT_BUTTON:
	 if (state == GLUT_DOWN)
	    cube.Translate(0.f, -10.f, 0.f);
	 break;
   }
}


void mouse_passive(int x, int y)
{
   cube3.Translate(x*2 - 720, -y*2 + 480, 0);
}

