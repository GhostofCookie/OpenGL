#include "Constants.h"

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

namespace GL_Colour
{
	Colour::Colour(float r, float g, float b)
	{
		glColor3f(r, g, b);
	}
}

namespace GL_Font
{
	void* GL_Font::Font::GetFont(int font)
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

