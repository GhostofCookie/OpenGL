#pragma once
#include <Constants.h>

class Object
{
public:
	Object();
	Object(float x, float y, float z);

	virtual void Render() = 0;

	virtual void Translate(float, float, float);

	virtual void Rotate(float theta,
		GL_Transform::GLVector v1 = GL_Transform::GLVector(0.f, 0.f, 0.f), 
		GL_Transform::GLVector v2 = GL_Transform::GLVector(0.f, 0.f, 0.f));

	GL_Transform::GLVector GetTransform();

protected:
	virtual void StartRender();

	virtual void EndRender();

protected:
	float x_loc, y_loc, z_loc;
	float angle;
	GL_Transform::GLRotator r_vector;
	

};
