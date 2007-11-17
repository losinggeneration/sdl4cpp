/*
 * This is a demo to show off Timers, some of the WM namespace, and some of the "Main" 
 * function calls such as LinkedVersion. This also gives an idea of how Event handlers
 * are used, and also how to set the window icon.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "SDL4Cpp.h"
#include <GL/gl.h>
#include <GL/glu.h>

std::string Extensions()
{
	char *extensions = (char *)glGetString(GL_EXTENSIONS);

	if(!extensions)
		return "No Extensions";
	
	while(*extensions)
	{
		unsigned int len = strcspn(extensions, " ");
		char *temp = new char[len + 30];
		strncpy(temp, extensions, len);
		std::cout << temp << std::endl;
		delete [] temp;
		extensions += len + 1;
	}
	
	return "Hope that helped";
}

void DisplayTriangle(GLfloat angle)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5f,  -0.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
	glEnd();

	SDL::GL::SwapBuffers();
}

int main(int argv, char *args[])
{
	SDL::Init(SDL_INIT_VIDEO);
	atexit(SDL::Quit);
	SDL::Screen screen;
	SDL::Event events;
	SDL::Timer timer;

	class Handler : public SDL::Handle
	{
		private:
			bool m_Stop;
		public:
			Handler() { m_Stop = false; }
			bool KeyPressed(SDL::KeySym &keysym)
			{
				if(keysym.sym != 0)
					m_Stop = true;
	
				return true;
			}
			
			operator bool() { return m_Stop; }
	} handler;

	SDL::WM::SetCaption("OpenGL Test");

	// Lets do some illegal things first and catch the errors
	try {
		void *test = SDL::GL::GetProcAddress("glNormalPointer");
	}
	catch(std::logic_error e) {
		std::cout << "Caught a throw: " << e.what() << std::endl;
	}
	
	try {
		int x;
		SDL::GL::GetAttribute(SDL_GL_DOUBLEBUFFER, x);
	}
	catch(std::logic_error e) {
		std::cout  << "I'm on a roll: " << e.what() << std::endl;
	}
	
	// And that's (almost) it for the illegal GL function calls, pretty cool huh?
	SDL::GL::SetAttribute(SDL_GL_RED_SIZE,   1);
	SDL::GL::SetAttribute(SDL_GL_GREEN_SIZE, 1);
	SDL::GL::SetAttribute(SDL_GL_BLUE_SIZE,  1);
	SDL::GL::SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	screen.SetVideoMode(640, 480, 32, SDL_OPENGL);
	
	std::cout << Extensions() << std::endl;
	// Couple more
	try {
		SDL::GL::LoadLibrary("libglib.so");
	}
	catch(std::logic_error e) {
		std::cout << "Not loading an external GL Library: " << e.what() <<std::endl;
	}
	
	try {
		SDL::GL::SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	}
	catch(std::logic_error e) {
		std::cout  << "Caught another throw: " << e.what() << std::endl;
	}
	
	// Ok, let's do a little bit of OpenGL fun
	// How about a rotating triangle (ok, not as fun, but it'll
	// give beginers an idea how to do it.
	int now, ticks;
	GLfloat angle = 0;
	while(!handler)
	{
		now = SDL_GetTicks();
		if((now - ticks) < 10)
			SDL_Delay(5);

		ticks = now;

		events.Poll(handler);
		DisplayTriangle(angle);
		angle += 0.2f;
	}
	
	return 0;
}

