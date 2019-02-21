#include <Engine/EngineUI.h>

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <Core.h>

UI_Base::UI_Base()
{
}

void UI_Base::Render()
{

}

bool UI_Base::GetCursorHovered()
{
	return false;
}

UI_Panel::UI_Panel(float x, float y, float w, float h)
	: _x_coord{ x }, _y_coord{ y }, _width{ w }, _height{ h }
{
}

void UI_Panel::Render()
{
	glPushMatrix();

	GL_Colour c = GL_Colour(0.08f, 0.09f, 0.1f);
	glBegin(GL_POLYGON);

	glTranslatef(0, 0, 1000);

	c.UseColour();
	glVertex2f(_x_coord - _width, _y_coord);
	glVertex2f(_x_coord - _width, _y_coord + _height);
	glVertex2f(_x_coord + _width, _y_coord + _height);
	glVertex2f(_x_coord + _width, _y_coord);

	glEnd();

	glPopMatrix();
}
