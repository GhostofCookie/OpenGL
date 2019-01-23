#pragma once

#include <stdarg.h>


class App
{
  public: // Window Setup
   App(int argc, char** argv, const char* name, void (*f)(void));

   template<typename ...T>
   static void RegisterFuncs(void(*funcs)(T...)...)
   {
	   va_list vl;
	   va_start(vl, funcs);
	   glutDisplayFunc(funcs);
	   {
	      auto f = va_arg(vl, void(*)(int, int));
	      glutReshapeFunc(f);
	   }
	   {
	      auto f = va_arg(vl, void(*)(int, int, int, int));
	      glutMouseFunc(f);
	   }
	   
	   va_end(vl);
   }

   static void Display(void(*lambda)());

   static void Reshape(int w, int h);
   
   static void Loop();

public: // Application Functions
   static void PrintToScreen(const char* str, void *font);
   
};
