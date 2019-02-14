#pragma once

#include <GL/glut.h>
#include <cstdarg>
#include <vector>
#include <Constants.h>

class App
{
public: // Window Setup
	/** Constructor which Creates the window and initializes the display.
	@param argc
	@param argv is the command line arguments.
	@param name of the application window.
	@param w is the inital width of the window.
	@param h is the intial height of the window.
	*/
	App(int argc, char** argv, const char* name, int w = 720, int h = 480);

	/** Initalizes several OpenLGL functionalities, and sets up the window environment.
	@param c is the colour of the background when the window colour is cleared.
	@param mode is the shading style.
	*/
	static void Init(float c = 0.15f, GLenum mode = GL_FLAT);

	template<typename ...T>
	static void RegisterCallbackFuncs(void(*funcs)(T...)...);

	/** Displays the give lambda to the screen.
	@param lambda is the lambda function which holds all the visual functionality.
	*/
	static void Display(void(*lambda)());

	/** Callback function when the window is resized.
	@param w is the new width of the window.
	@param h is the new height of the window. 
	*/
	static void Reshape(int w, int h);

	/** OpenGl main loop wrapper method. */
	static void Loop();

public: // Application Functions
	static int Width();

	static int Height();

	/** Prints a message to the screen.
	@param str is the message to be displayed.
	@param x is the x coordinate to be printed at.
	@param y is the y coordinate to be printed at.
	@param font of the given text.
	@param colour of the text. 
	*/
	static void PrintToScreen(const char* str, float x = 0.f, float y = 0.f,
		void* font = GL_Font::HELVETICA,
		GL_Colour colour = GL_Colour::White);
	/** Prints a message to the screen.
	@param str is the message to be displayed.
	@param x is the x coordinate to be printed at.
	@param y is the y coordinate to be printed at.
	@param colour of the text.
	*/
	static void PrintToScreen(const char* str, float x = 0.f, float y = 0.f, 
		GL_Colour colour = GL_Colour::White);


	static void AddObjectToPool(class Object* obj);

private:
	static int w_width;
	static int w_height;
	static std::vector<Object*> _object_pool;

	typedef void(*__gl_void_ii	)(int, int);
	typedef void(*__gl_void_iiii)(int, int, int, int);
	typedef void(*__gl_void_ucii)(unsigned char, int, int);
};

/** Function that sets all functions passed in as callback functions to various
OpenGL methods.
@param funcs is a variadic amount of methods with a variadic amount of arguments. 
*/
template<typename ...T>
inline void App::RegisterCallbackFuncs(void(*funcs)(T...)...)
{
	va_list vl;
	va_start(vl, funcs);
	glutDisplayFunc	(funcs);
	glutReshapeFunc(&Reshape);
	glutMouseFunc			(va_arg(vl, __gl_void_iiii));
	glutKeyboardFunc		(va_arg(vl, __gl_void_ucii));
	glutPassiveMotionFunc	(va_arg(vl, __gl_void_ii));
	glutIdleFunc(funcs);
	va_end(vl);
}
