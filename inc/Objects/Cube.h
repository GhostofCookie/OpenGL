#pragma once
#include <Object.h>
class GLMeshComponent;

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
	GLMeshComponent* mesh;
};
