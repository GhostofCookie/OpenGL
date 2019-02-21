#include <Cube.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <Core.h>
#include <Components/MeshComponent.h>


Cube::Cube() :_material { new GL_Colour(GL_Colour::White) } 
{
	mesh = new GLMeshComponent();
	mesh->SetMesh(new GLMesh("Meshes/cube.fbx"));
}

Cube::Cube(const GL_Colour & m)
	: _material{ new GL_Colour(m) } 
{
	mesh = new GLMeshComponent();
	mesh->SetMesh(new GLMesh("Meshes/cube.fbx"));
}

Cube::Cube(float x, float y, float z)
	: _material{ new GL_Colour(GL_Colour::White) }
{
	mesh = new GLMeshComponent();
	mesh->SetMesh(new GLMesh("Meshes/cube.fbx"));
	SetLocation(x, y, z);
}

Cube::Cube(float x, float y, float z, GL_Colour& m)
	: _material{ new GL_Colour(m) }
{
	mesh = new GLMeshComponent();
	mesh->SetMesh(new GLMesh("Meshes/cube.fbx"));
	SetLocation(x, y, z);
}

Cube::Cube(float x, float y, float z, const GL_Colour& m)
	: _material{ new GL_Colour(m) }
{
	mesh = new GLMeshComponent();
	mesh->SetMesh(new GLMesh("Meshes/cube.fbx"));
	SetLocation(x, y, z);
}

void Cube::Tick()
{
	if (mesh)
	{
		StartRender();

		_material->UseColour();

		mesh->Tick();
		EndRender();
	}
}
