#pragma once

#define GET_OBJECT_NAME(n) #n

namespace GL_Colour
{
	struct Colour
	{
	public:
		Colour(Colour* c);
		Colour(float, float, float);
		~Colour();
		void GetColour();
	private:
		float r, g, b;
	};

#define GL_Black	Colour(0.f, 0.f, 0.f)
#define GL_White	Colour(1.f, 1.f, 1.f)
#define GL_Red		Colour(1.f, 0.f, 0.f)
#define GL_Green	Colour(0.f, 1.f, 0.f)
#define GL_Blue		Colour(0.f, 0.f, 1.f)
#define GL_Cyan		Colour(0.f, 0.8f, 1.f)
#define GL_Emerald	Colour(0.f, 1.f, 0.5f)
}

namespace GL_Font
{
	void* GetFont(int);
	
#define HELVETICA	GetFont(0)
#define TIMES		GetFont(1)
}

namespace GL_Transform
{
	struct GLVector
	{
	public:
		GLVector();
		GLVector(float x, float y);
		GLVector(float x, float y, float z);
		
		float x, y, z;
	};

	struct GLRotator
	{
	public:
		GLRotator();
		GLRotator(float);
		GLRotator(GLVector v);
		GLRotator(GLVector v1, GLVector v2);
		GLRotator(float x1, float y1, float z1, float x2, float y2, float z2);
		
		float x1, y1, z1;
		float x2, y2, z2;
	};

	struct GLScale
	{
		GLScale();
		GLScale(float x, float y, float z);
		float x, y, z;
	};

	struct GLTransform
	{
	public:
		GLTransform(GLVector, GLRotator, GLScale);

		GLVector GetLocation();
		GLRotator GetRotation();
		GLScale GetScale();

		void SetLocation(GLVector l);
		void SetRotation(GLRotator r);
		void SetScale(GLScale s);

	private:
		GLVector location;
		GLRotator rotation;
		GLScale scale;

	};
}

