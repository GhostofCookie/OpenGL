#pragma once
#include "../Object.h"

class Cube : public Object
{
public:
	Cube(float x, float y, float z);
	Cube(float x, float y, float z, GL_Colour::Colour m);

	virtual void Render() override;

private:
	GL_Colour::Colour material;

private:
	const float vertices[8][3] = {
		{100.f, 100.f, 100.f},
		{100.f, 100.f, -100.f},
		{100.f, -100.f, 100.f},
		{100.f, -100.f, -100.f},
		{-100.f, 100.f, 100.f},
		{-100.f, 100.f, -100.f},
		{-100.f, -100.f, 100.f},
		{-100.f, -100.f, -100.f}
	};

	void GL_Quad(int a, int b, int c, int d);
};
