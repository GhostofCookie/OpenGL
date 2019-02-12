#include <Object.h>

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Object::Object()
	: transform(GLVector(0.f, 0.f, 0.f), GLRotator(0.f), GLScale(1.f, 1.f, 1.f))
{
}

Object::Object(float x, float y, float z)
	: transform(GLVector(0.f, 0.f, 0.f), GLRotator(0.f), GLScale(1.f, 1.f, 1.f))
{
}

void Object::SetLocation(GLVector loc)
{
	transform.SetLocation(loc);
}

void Object::SetLocation(float x, float y, float z)
{
	transform.SetLocation(GLVector(x, y, z));
}

void Object::Translate(float x, float y, float z)
{
	SetLocation(GLVector(
		transform.GetLocation().x + x,
		transform.GetLocation().y + y,
		transform.GetLocation().z + z));
}

void Object::Rotate(float theta, GLVector v1)
{
}

void Object::Rotate(float theta, GLVector v1, GLVector v2)
{
	angle = (int(angle + theta)) % 361;
	transform.SetRotation(GLRotator(v1, v2));
	glutPostRedisplay();
}

GLVector Object::GetLocation()
{
	return transform.GetLocation();
}

GLRotator Object::GetRotation()
{
	return transform.GetRotation();
}

GLScale Object::GetScale()
{
	return transform.GetScale();
}

GLTransform Object::GetTransform()
{
	return transform;
}

void Object::StartRender()
{
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(transform.GetLocation().x, transform.GetLocation().y, transform.GetLocation().z);
	glRotatef(angle,
		transform.GetRotation().x1 - transform.GetRotation().x2,
		transform.GetRotation().y1 - transform.GetRotation().y2,
		transform.GetRotation().z1 - transform.GetRotation().z2);
	glTranslatef(-transform.GetLocation().x, -transform.GetLocation().y, -transform.GetLocation().z);

	glTranslatef(transform.GetLocation().x, transform.GetLocation().y, transform.GetLocation().z);
}

void Object::EndRender()
{
	glPopMatrix();
}

