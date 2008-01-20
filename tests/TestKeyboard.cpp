#include <iostream>
#include <string>
#include <vector>
#include "SDL4Cpp.h"

class EvHandler : public SDL::Handle
{
	public:
		EvHandler() : m_Quit(false) {}
		bool KeyPressed(SDL::KeySym &keysym)
		{
			std::cout << "KeyPressed:" << std::endl
				<< "\tkeysym.scancode: " << static_cast<int>(keysym.scancode) << std::endl
				<< "\tkeysym.sym: " << keysym.sym << std::endl
				<< "\tkeysym.mod: " << keysym.mod << std::endl
				<< "\tkeysym.unicode: " << keysym.unicode << std::endl;

			Uint8 *keys = SDL::GetKeyState(NULL);
			if(keys[SDLK_LCTRL] && keys[SDLK_c])
				m_Quit = true;

			return true;
		}

		bool KeyReleased(SDL::KeySym &keysym)
		{
			std::cout << "KeyReleased:" << std::endl
				<< "\tkeysym.scancode: " << static_cast<int>(keysym.scancode) << std::endl
				<< "\tkeysym.sym: " << keysym.sym << std::endl
				<< "\tkeysym.mod: " << keysym.mod << std::endl
				<< "\tkeysym.unicode: " << keysym.unicode << std::endl;

			return true;
		}

		operator bool()
		{
			return m_Quit;
		}
	private:
		bool m_Quit;
};

int main(int argv, char *args[])
{
	SDL::Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK);
	SDL::Event events;
	EvHandler eventhandler;

	SDL::Screen screen;
	screen.SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	while(!eventhandler)
		events.Poll(eventhandler);

	SDL::Quit();
	return 0;
}

