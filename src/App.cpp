#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "../inc/App.h"

App::App(int argc, char** argv, void (*f)(void))
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(1280, 720);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);

   (*f)();

   /*
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   */

   glutMainLoop();
}
