#include "../../inc/Objects/Cube.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Cube::Cube(float x, float y, float z)
	: material{ GL_Colour::GL_White }
{
	x_loc = x;
	y_loc = y;
	z_loc = z;
}

Cube::Cube(float x, float y, float z, GL_Colour::Colour m)
	: material{ m }
{
	x_loc = x;
	y_loc = y;
	z_loc = z;
}

void Cube::Render()
{
	StartRender();

	material.GetColour();
	//glutWireCube(100.f);

	GL_Quad(6, 2, 0, 4);
	GL_Quad(0, 2, 3, 1);
	GL_Quad(6, 7, 3, 2);
	GL_Quad(4, 0, 1, 5);
	GL_Quad(7, 5, 1, 3);
	GL_Quad(6, 4, 5, 7);

	glLightf(GL_LIGHT0, GL_POSITION, 0);
	EndRender();
}

void Cube::GL_Quad(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glVertex3fv((GLfloat*)(vertices[a]));
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}
