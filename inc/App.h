#pragma once

class App
{
  public:
   App(int argc, char** argv, const char* name, void (*f)(void));

   static void Loop();

   static void Display(void (*lambda)());

   static void RegisterCallbackFuncs(void(*f)(void), void(*r)(int w, int h), void (*m)(int button, int state, int x, int y) = NULL);

   static void Reshape(int w, int h);

   static void PrintToScreen(const char* str, void *font);
   
};
