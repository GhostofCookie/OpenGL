#include <Object.h>

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Object::Object()
	: x_loc{ 0.f }, y_loc{ 0.f }, z_loc{ 0.f }, r_vector(0.f)
{
}

Object::Object(float x, float y, float z)
	: x_loc{ x }, y_loc{ y }, z_loc{ z }, r_vector(0.f)
{
}

void Object::Translate(float x, float y, float z)
{
	x_loc = x; y_loc = y; z_loc = z;
}

void Object::Rotate(float theta, GL_Transform::GLVector v1, GL_Transform::GLVector v2)
{
	angle = (int(angle + theta)) % 361;
	r_vector = GL_Transform::GLRotator(v1, v2);
	glutPostRedisplay();
}

GL_Transform::GLVector Object::GetTransform()
{
	return GL_Transform::GLVector(x_loc, y_loc, z_loc);
}

void Object::StartRender()
{
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x_loc, y_loc, z_loc);
	glRotatef(angle, r_vector.x1 - r_vector.x2, r_vector.y1 - r_vector.y2, r_vector.z1 - r_vector.z2);
	glTranslatef(-x_loc, -y_loc, -z_loc);

	glTranslatef(x_loc, y_loc, z_loc);
}

void Object::EndRender()
{
	glPopMatrix();
}

