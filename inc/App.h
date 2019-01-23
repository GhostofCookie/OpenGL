#pragma once

class App
{
  public:
   App(int argc, char** argv, const char* name, void (*f)(void), void(*g)(void));

   void Reshape(void(*f)(int w, int h));
   
};
