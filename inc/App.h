#pragma once

#include <stdarg.h>

class App
{
  public: // Window Setup
   App(int argc, char** argv, const char* name, void (*f)(void));

   static void RegisterCallbackFuncs(
	   void (*f)(void),
	   void (*r)(int w, int h),
	   void (*m)(int button, int state, int x, int y) = NULL);

   template<typename ...T>
   static void RegisterFuncs(void(*funcs)(T...)...)
   {
	   va_list vl;
	   va_start(vl, funcs);
	   glutDisplayFunc(funcs);
		//   glutReshapeFunc(funcs);
		//   if (funcs)
		//	   glutMouseFunc(funcs);
	   
	   va_end(vl);
   }

   static void Display(void(*lambda)());

   static void Reshape(int w, int h);
   
   static void Loop();

public: // Application Functions
   static void PrintToScreen(const char* str, void *font);
   
};
