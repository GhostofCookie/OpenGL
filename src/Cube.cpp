#include "../inc/Cube.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Cube::Cube(float x, float y, float z)
	: material{ GL_Colour::GL_White }, scale(1.f, 1.f, 1.f)
{
	x_loc = x;
	y_loc = y;
	z_loc = z;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 3; j++)
			vertices[i][j] *= 100.f;
}

Cube::Cube(float x, float y, float z, GL_Colour::Colour m)
	: material{ m }, scale(100.f, 100.f, 100.f)
{
	x_loc = x;
	y_loc = y;
	z_loc = z;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 3; j++)
			vertices[i][j] *= 100.f;
}

void Cube::Render()
{
	StartRender();

	material.GetColour();

	GL_Quad(6, 2, 0, 4);
	GL_Quad(0, 2, 3, 1);
	GL_Quad(6, 7, 3, 2);
	GL_Quad(4, 0, 1, 5);
	GL_Quad(7, 5, 1, 3);
	GL_Quad(6, 4, 5, 7);

	GL_Colour::GL_Black.GetColour();
	glutWireCube(201.f);

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
