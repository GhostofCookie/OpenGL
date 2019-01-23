#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#include "../inc/App.h"

void display(void);
void init(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
   App* app = new App(argc, argv, "Title", init, display);
   
   app->Reshape(reshape);
   glutMouseFunc(mouse);
   glutMainLoop();

   delete app;
   
   return 0;
}


void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   /* Insert Stuff here */
   glPopMatrix();
   
   glutSwapBuffers();
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

