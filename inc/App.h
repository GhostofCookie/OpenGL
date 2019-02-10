#pragma once

#include "Constants.h"
#include <cstdarg>

class App
{
public: // Window Setup
	App(int argc, char** argv, const char* name, int w = 720, int h = 480);

	static void Init(float c = 0.15f, GLenum mode = GL_FLAT);

	template<typename ...T>
	static void RegisterCallbackFuncs(void(*funcs)(T...)...);

	static void Display(void(*lambda)());

	static void Reshape(int w, int h);

	static void Loop();

public: // Application Functions
	static void PrintToScreen(const char* str, float x = 0.f, float y = 0.f);

private:
	typedef void(*__gl_void_ii	)(int, int);
	typedef void(*__gl_void_iiii)(int, int, int, int);
	typedef void(*__gl_void_ucii)(unsigned char, int, int);
};

template<typename ...T>
inline void App::RegisterCallbackFuncs(void(*funcs)(T...)...)
{
	va_list vl;
	va_start(vl, funcs);
	glutDisplayFunc	(funcs);
	glutReshapeFunc	(va_arg(vl, __gl_void_ii));
	glutMouseFunc	(va_arg(vl, __gl_void_iiii));
	glutKeyboardFunc(va_arg(vl, __gl_void_ucii));
	va_end(vl);
}
