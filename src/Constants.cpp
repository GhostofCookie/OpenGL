#include "../inc/Constants.h"

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

namespace GL_Colour
{
	Colour::Colour(Colour * c)
		: r{ c->r }, g{ c->g }, b{ c->b }
	{ 
	}

	Colour::Colour(float r, float g, float b)
		: r{ r }, g{ g }, b{ b }
	{
	}

	Colour::~Colour()
	{
	}
	void Colour::GetColour()
	{
		glColor3f(r, g, b);
	}
	void * Colour(int index)
	{
		return nullptr;
	}
}

namespace GL_Font
{
	void* GL_Font::GetFont(int font)
	{
		switch (font)
		{
		case 0:
			return GLUT_BITMAP_HELVETICA_12;
		case 1:
			return GLUT_BITMAP_TIMES_ROMAN_10;
		}
		return GLUT_BITMAP_HELVETICA_12;
	}
}

namespace GL_Transform
{
	GLVector::GLVector(float x, float y)
		: x{ x }, y{ y }, z{ 0 } {}

	GLVector::GLVector(float x, float y, float z)
		: x{ x }, y{ y }, z{ z } {}

	GLRotator::GLRotator(float d)
		: x1{ d }, y1{ d }, z1{ d }, x2{ d }, y2{ d }, z2{ d } {}

	GLRotator::GLRotator(GLVector v1, GLVector v2)
		: x1{ v1.x }, y1{ v1.y }, z1{ v1.z }, x2{ v2.x }, y2{ v2.y }, z2{ v2.z } {}

	GLRotator::GLRotator(float x1, float y1, float z1, float x2, float y2, float z2)
		: x1{ x1 }, y1{ y1 }, z1{ z1 }, x2{ x2 }, y2{ y2 }, z2{ z2 } {}

	GLScale::GLScale(float x, float y, float z)
	{
	}

	GLTransform::GLTransform(GLVector, GLRotator, GLScale)
	{
	}

}
