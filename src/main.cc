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
   App* app = new App(argc, argv, init);

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);

   glutMainLoop();
   
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
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{

}

void mouse(int button, int state, int x, int y)
{

}

