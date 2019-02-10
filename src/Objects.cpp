#include "../inc/Objects.h"

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Object::Object()
	: x_loc{ 0.f }, y_loc{ 0.f }, z_loc{ 0.f }
{
}

void Object::Render()
{
	glTranslatef(x_loc, y_loc, z_loc);
}

void Object::Move(float x, float y, float z)
{
	x_loc += x; y_loc += y; z_loc += z;
}

void Object::Rotate(float)
{
}
