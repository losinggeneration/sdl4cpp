/*
 * This is a demo to show off GL goodnees
 */

#include <iostream>
#include <string>

#include "SDL4Cpp.h"
#include <GL/gl.h>
#include <GL/glu.h>

void Extensions()
{
	char *extensions = (char *)glGetString(GL_EXTENSIONS);

	if(!extensions)
	{
		std::cout << "No Extensions" << std::endl;
		return;
	}

	std::cout << "Extensions: " << std::endl;
	while(*extensions)
	{
		unsigned int len = strcspn(extensions, " ");
		char *temp = new char[len + 30];
		strncpy(temp, extensions, len);
		std::cout << "\t" << temp << std::endl;
		delete [] temp;
		extensions += len + 1;
	}
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
	try
	{
		void *test;
		test = SDL::GL::GetProcAddress("glNormalPointer");
	}
	catch(SDL::LogicError e)
	{
		std::cout << "Caught a throw: " << e.what() << std::endl;
	}

	try
	{
		int x;
		SDL::GL::GetAttribute(SDL_GL_DOUBLEBUFFER, x);
	}
	catch(SDL::LogicError e)
	{
		std::cout  << "I'm on a roll: " << e.what() << std::endl;
	}

	// And that's (almost) it for the illegal GL function calls, cool huh?
	// These aren't actually needed, but we'll set them anyways
	// Just like SDL these have to be set before the SetVideoMode to have an effect
	// Unlike SDL, SDL4Cpp will check if SetVideoMode has been called and throw if it has
	SDL::GL::SetAttribute(SDL_GL_RED_SIZE,   1);
	SDL::GL::SetAttribute(SDL_GL_GREEN_SIZE, 1);
	SDL::GL::SetAttribute(SDL_GL_BLUE_SIZE,  1);
	SDL::GL::SetAttribute(SDL_GL_DOUBLEBUFFER, true);
	screen.SetVideoMode(640, 480, 32, SDL_OPENGL);

	// Query some OpenGL version info
	std::cout << "----------------------------------" << std::endl
			<< "GL_VENDOR: " << glGetString(GL_VENDOR) << std::endl
			<< "GL_RENDERER: " << glGetString(GL_RENDERER) << std::endl
			<< "GL_VERSION: " << glGetString(GL_VERSION) << std::endl;
	Extensions();
	std::cout  << "---------------------------------" << std::endl;

	// Couple more
	try
	{
		SDL::GL::LoadLibrary("libglib.so");
	}
	catch(SDL::LogicError e)
	{
		std::cout << "Not loading an external GL Library: " << e.what()
				<< std::endl;
	}

	// SetAttribute throws if the video mode is already setup
	try
	{
		SDL::GL::SetAttribute(SDL_GL_DOUBLEBUFFER, true);
	}
	// Here we'll use the standard logic_error
	catch(std::logic_error e)
	{
		std::cout  << "Caught a throw using std::logic_error instead: "
				<< e.what() << std::endl;
	}

	// Ok, let's do a little bit of OpenGL fun
	// How about a rotating triangle (ok, not as fun, but it'll
	// give beginers an idea how to do it.
	int now, ticks = 0;
	GLfloat angle = 0;
	while(!handler)
	{
		now = SDL::GetTicks();
		if((now - ticks) < 10)
			SDL::Delay(5);

		ticks = now;

		events.Poll(handler);
		DisplayTriangle(angle);
		angle += 0.2f;
	}

	return 0;
}

