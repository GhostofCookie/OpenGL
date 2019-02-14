#pragma once
#include <Object.h>

struct GL_Colour;

class Cube : public Object
{
public:
	Cube();
	Cube(const GL_Colour& m);
	Cube(float x, float y, float z);
	Cube(float x, float y, float z, GL_Colour& m);
	Cube(float x, float y, float z, const GL_Colour& m);

	virtual void Tick() override;

private:
	GL_Colour* _material;

private:
	float vertices[8][3] = {
		{1, 1, 1},
		{1, 1, -1},
		{1, -1, 1},
		{1, -1, -1},
		{-1, 1, 1},
		{-1, 1, -1},
		{-1, -1, 1},
		{-1, -1, -1}
	};

	void GL_Quad(int a, int b, int c, int d);
};
