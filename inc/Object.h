#pragma once
#include <Constants.h>
using namespace GL_Transform;

class Object
{
public:
	Object();
	Object(float x, float y, float z);

	virtual void Render() = 0;

	virtual void SetLocation(GLVector location);
	virtual void SetLocation(float x, float y, float z);

	virtual void Translate(float, float, float);

	virtual void Rotate(float theta, GLVector v1 = GLVector(0.f, 0.f, 0.f));
	virtual void Rotate(float theta,
		GLVector v1 = GLVector(0.f, 0.f, 0.f), 
		GLVector v2 = GLVector(0.f, 0.f, 0.f));

	GLVector GetLocation();
	GLRotator GetRotation();
	GLScale GetScale();
	GLTransform GetTransform();

protected:
	virtual void StartRender();

	virtual void EndRender();

protected:
	GLTransform transform;
	float angle;
	

};
