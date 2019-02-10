#pragma once

namespace GL_Colour
{
	struct Colour
	{
		Colour(float, float, float);
	};

#define GL_Blue	 Colour(0.f, 0.f, 1.f)
#define GL_Cyan	 Colour(0.f, 0.8f, 1.f)
#define GL_Red	 Colour(1.f, 0.f, 0.f)
#define GL_White Colour(1.f, 1.f, 1.f)
}

namespace GL_Font
{
	struct Font
	{
		static void* GetFont(int);

	};
	
#define HELVETICA	Font::GetFont(0)
#define TIMES		Font::GetFont(1)
}

