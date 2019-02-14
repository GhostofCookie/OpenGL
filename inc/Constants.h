#pragma once

#define GET_OBJECT_NAME(n) #n

/** 
* Defines a colour based on RGB values.
*/
struct GL_Colour
{
public:
	__forceinline explicit GL_Colour(float, float, float);
	GL_Colour(const GL_Colour& c);
	GL_Colour(const GL_Colour* c);
	void UseColour();

	static const GL_Colour Black;
	static const GL_Colour White;
	static const GL_Colour Red;
	static const GL_Colour Green;
	static const GL_Colour Blue;
	static const GL_Colour Cyan;
	static const GL_Colour Emerald;
	static const GL_Colour Purple;

private:
	float R, G, B;
};


namespace GL_Font
{
	void* GetFont(int);
	
#define HELVETICA	GetFont(0)
#define TIMES		GetFont(1)
}

struct GLVector
{
public:
	GLVector();
	GLVector(float x, float y);
	GLVector(float x, float y, float z);
		
	float X, Y, Z;
};

struct GLRotator
{
public:
	GLRotator();
	GLRotator(GLRotator* rot);
	GLRotator(float);
	GLRotator(float x, float y, float z);
	GLRotator(float x1, float y1, float z1, float x2, float y2, float z2);
	GLRotator(GLVector v1, GLVector v2);
		
	float X, Y, Z;
	int Angle;
};

struct GLScale
{
	GLScale();
	GLScale(GLScale* scale);
	GLScale(float x, float y, float z);

	float X, Y, Z;
};

struct GLTransform
{
public:
	GLTransform();
	GLTransform(GLVector, GLRotator, GLScale);
	~GLTransform() {}

	GLVector GetLocation();
	GLRotator GetRotation();
	GLScale GetScale();

	void SetLocation(GLVector l);
	void SetRotation(GLRotator r);
	void SetScale(GLScale s);

private:
	GLVector	_location;
	GLRotator	_rotation;
	GLScale		_scale;

};

