/*
 * This is a demo to show off Timers, some of the WM namespace, and some of the "Main"
 * function calls such as LinkedVersion. This also gives an idea of how Event handlers
 * are used, and also how to set the window icon.
 */

#include <iostream>
#include <string>
#include "SDL4Cpp.h"

Uint32 MyTimedCallback(Uint32 interval, void *param)
{
	static int lettercount = 0;
	std::string title;

	switch(lettercount)
	{
		case 0:
			title = "Testing";
			break;
		case 1:
			title = "tEsting";
			break;
		case 2:
			title = "teSting";
			break;
		case 3:
			title = "tesTing";
			break;
		case 4:
			title = "testIng";
			break;
		case 5:
			title = "testiNg";
			break;
		case 6:
			title = "testinG";
			break;
	}
	if(*(bool *)param == 0)
		lettercount++;
	else
		lettercount--;

	SDL::WM::SetCaption(title, title);

	if(*(bool *)param == 0)
	{
		if(lettercount == 7)
			lettercount = 0;
	}
	else
	{
		if(lettercount == -1)
			lettercount = 6;
	}

	return interval;
}

int main(int argv, char *args[])
{
	SDL::Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	atexit(SDL::Quit);
	SDL::Screen screen;
	SDL::Event events;

	class Handler : public SDL::Handle
	{
		private:
			bool m_Stop, m_Direction;
		public:
		Handler() : m_Stop(false), m_Direction(false)
		{
		}
		bool KeyPressed(SDL::KeySym &keysym)
		{
			if(keysym.sym != 0 && keysym.sym != SDLK_SPACE)
				m_Stop = true;

			if(keysym.sym == SDLK_SPACE)
				m_Direction = !m_Direction;

			return true;
		}

		operator bool()
		{
			return m_Stop;
		}
		bool Direction()
		{
			return m_Direction;
		}
	} handler;

	SDL::Timer timer;
	int delay = (250 / 10) * 10;
	bool direction = false;

	screen.SetIcon("icon.bmp", NULL);
	int bpp = SDL::Screen::VideoModeOK(640, 480, 32);
	std::cout << bpp << std::endl;
	screen.SetVideoMode(640, 480, bpp);

	std::string caption, icon;
	SDL::WM::SetCaption("Testing", "testarg2");

	SDL::WM::GetCaption(caption, icon);
	std::cout << "Window Caption: " << caption << std::endl << "Icon: " << icon << std::endl;
	std::cout << "Trying Again with individual functions:" << std::endl;
	std::cout << "\tCaption: " << SDL::WM::GetTitle() << std::endl;
	std::cout << "\tIcon: " << SDL::WM::GetIcon() << std::endl;

	const SDL::Version *version = SDL::LinkedVersion();
	// We must cast the Uint8's as integers
	if(version)
		std::cout << "SDL Version: " << (int)version->major << "." << (int)version->minor
			<< "." << (int)version->patch << std::endl;

	timer.Add(delay, MyTimedCallback, &direction);
	std::cout << "Press space to reverse direction" << std::endl
		<< "Press any other key to exit" << std::endl;
	while(!handler)
	{
		events.Poll(handler);
		// Switch direction
		if(handler.Direction() != direction)
		{
			timer.Remove();
			direction = handler.Direction();
			timer.Add(delay, MyTimedCallback, &direction);
		}
	}

	return 0;
}

