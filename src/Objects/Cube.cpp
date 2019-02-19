#include <Cube.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <Core.h>

Cube::Cube() :_material { new GL_Colour(GL_Colour::White) } {}

Cube::Cube(const GL_Colour & m)
	: _material{ new GL_Colour(m) } {}

Cube::Cube(float x, float y, float z)
	: _material{ new GL_Colour(GL_Colour::White) }
{
	SetLocation(x, y, z);
}

Cube::Cube(float x, float y, float z, GL_Colour& m)
	: _material{ new GL_Colour(m) }
{
	SetLocation(x, y, z);
}

Cube::Cube(float x, float y, float z, const GL_Colour& m)
	: _material{ new GL_Colour(m) }
{
	SetLocation(x, y, z);
}

void Cube::Tick()
{
	StartRender();

	_material->UseColour();

	GL_Quad(6, 2, 0, 4);
	GL_Quad(0, 2, 3, 1);
	GL_Quad(6, 7, 3, 2);
	GL_Quad(4, 0, 1, 5);
	GL_Quad(7, 5, 1, 3);
	GL_Quad(6, 4, 5, 7);

	GL_Colour c = GL_Colour::Black;
	c.UseColour();
	glutWireCube(2.005f);

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
