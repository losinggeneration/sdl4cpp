#include <iostream>
#include <string>
#include <vector>
#include "SDL4Cpp.h"

/* These two classes do exactly the same thing, one uses the class functions, and the other does it the SDL C way */
class TestHandler : public SDL::Handle
{
	public:
		TestHandler() : m_Quit(false), m_Switch(false), m_Unicode(false), m_Repeat(false) {}

		bool Active(Uint8 gain, Uint8 state)
		{
			std::cout << "Active:" << std::endl
				<< "\tgain: " << gain << std::endl
				<< "\tstate: " << state << std::endl;

			return true;
		}

		bool KeyPressed(SDL::KeySym &keysym)
		{
			int null = NULL;

			std::cout << "KeyPressed:" << std::endl
				<< "\tkeysym.scancode: " << keysym.scancode << std::endl
				<< "\tkeysym.sym: " << keysym.sym << std::endl
				<< "\tkeysym.mod: " << keysym.mod << std::endl
				<< "\tkeysym.unicode: " << keysym.unicode << std::endl;

			if(keysym.sym == SDLK_u)
			{
				m_Unicode = !m_Unicode;
				SDL::EnableUnicode(m_Unicode);
			}

			if(keysym.sym == SDLK_r)
			{
				m_Repeat = !m_Repeat;

				if(m_Repeat)
					SDL::EnableKeyRepeat(25, 5);
				else
					SDL::EnableKeyRepeat(0, 0);
			}

			if(keysym.sym == SDLK_s)
				m_Switch = !m_Switch;

			// This looks dangerous... 
			if(SDL::GetKeyState(null)[SDLK_LCTRL] && SDL::GetKeyState(null)[SDLK_c])
				m_Quit = true;

			return true;
		}

		bool KeyReleased(SDL::KeySym &keysym)
		{
			std::cout << "KeyReleased:" << std::endl
				<< "\tkeysym.scancode: " << keysym.scancode << std::endl
				<< "\tkeysym.sym: " << keysym.sym << std::endl
				<< "\tkeysym.mod: " << keysym.mod << std::endl
				<< "\tkeysym.unicode: " << keysym.unicode << std::endl;
			return true;
		}

		bool MouseMotion(Uint8 state, Uint16 x, Uint16 y, Sint16 xrel, Sint16 yrel)
		{
			std::cout << "MouseMotion: " << std::endl
				<< "\tstate: " << state << std::endl
				<< "\tx: " << x << std::endl
				<< "\ty: " << y << std::endl
				<< "\txrel: " << xrel << std::endl
				<< "\tyrel: " << yrel << std::endl;

			return true;
		}

		bool MouseButtonPressed(Uint8 button, Uint16 x, Uint16 y)
		{
			std::cout << "MouseButtonPressed: " << std::endl
				<< "\tbutton: " << button << std::endl
				<< "\tx: " << x << std::endl
				<< "\ty: " << y << std::endl;

			return true;
		}

		bool MouseButtonReleased(Uint8 button, Uint16 x, Uint16 y)
		{
			std::cout  << "MouseButtonReleased:" << std::endl
				<< "\tbutton: " << button << std::endl
				<< "\tx: " << x << std::endl
				<< "\ty: " << y << std::endl;

			return true;
		}

		bool JoyAxis(Uint8 which, Uint8 axis, Sint16 value)
		{
			std::cout << "JoyAxis:" << std::endl
				<< "\twhich: " << which << std::endl
				<< "\taxis: " << axis << std::endl
				<< "\tvalue: " << value << std::endl;

			return true;
		}

		bool JoyButtonPressed(Uint8 which, Uint8 button)
		{
			std::cout << "JoyButtonPressed" << std::endl
				<< "\twhich: " << which << std::endl
				<< "\tbutton: " << button << std::endl;

			return true;
		}

		bool JoyButtonReleased(Uint8 which, Uint8 button)
		{
			std::cout << "JoyButtonReleased" << std::endl
				<< "\twhich: " << which << std::endl
				<< "\tbutton: " << button << std::endl;

			return true;
		}

		bool JoyHat(Uint8 which, Uint8 hat, Uint8 value)
		{
			std::cout << "JoyHat" << std::endl
				<< "\twhich: " << which << std::endl
				<< "\that: " << hat << std::endl
				<< "\tvalue: " << value << std::endl;

			return true;
		}

		bool JoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
		{
			std::cout << "JoyBall" << std::endl
				<< "\twhich: " << which << std::endl
				<< "\tball: " << ball << std::endl
				<< "\txrel: " << xrel << std::endl
				<< "\tyrel: " << yrel << std::endl;

			return true;
		}

		bool VideoResize(int w, int h)
		{
			SDL::Screen screen;
			SDL::GetVideoSurface(screen);
			std::cout << "VideoResize" << std::endl
				<< "\tw: " << w << std::endl
				<< "\th: " << h << std::endl;

			screen.SetVideoMode(w, h, 8, SDL_SWSURFACE | SDL_RESIZABLE);

			return true;
		}

		bool VideoExpose()
		{
			std::cout << "VideoExpose" << std::endl;

			return true;
		}

		bool SysWM(SDL::SysWMmsg *msg)
		{
			std::cout << "SysWM" << std::endl
				<< "\tmsg: " << msg << std::endl;

			return true;
		}

		bool User(int code, void *data1, void *data2)
		{
			std::cout << "User" << std::endl
				<< "\tcode: " << code << std::endl;

			return true;
		}
		
		bool Quit()
		{
			std::cout << "Quit" << std::endl;

			m_Quit = true;

			return true;
		}

		// This actually shouldn't ever get here
		bool All(SDL_Event &m_Event)
		{
			std::cout << "This shoudln't happen: All";

			return true;
		}

		operator bool()
		{
			return m_Quit;
		}

		bool Switch()
		{
			return m_Switch;
		}

		void SetSwitch(bool makeswitch)
		{
			m_Switch = makeswitch;
		}
	private:
		bool m_Quit, m_Switch, m_Unicode, m_Repeat;
}; // 211 lines of code

class AllHandler : public SDL::Handle
{
	public:
		AllHandler() : m_Quit(false), m_Switch(false), m_Unicode(false), m_Repeat(false) {};

		bool All(SDL_Event &event)
		{
			std::cout << "All" << std::endl;
			int null = NULL;
			SDL::Screen screen;
			switch(event.type)
			{
				case SDL_ACTIVEEVENT:
					std::cout << "SDL_ACTIVEEVENT:" << std::endl
						<< "\tevent.active.gain: " << event.active.gain << std::endl
						<< "\tevent.active.state: " << event.active.state << std::endl;
					break;

				case SDL_KEYDOWN:
					std::cout << "SDL_KEYDOWN:" << std::endl
						<< "\tevent.key.keysym.scancode: " << event.key.keysym.scancode << std::endl
						<< "\tevent.key.keysym.sym: " << event.key.keysym.sym << std::endl
						<< "\tevent.key.keysym.mod: " << event.key.keysym.mod << std::endl
						<< "\tevent.key.keysym.unicode: " << event.key.keysym.unicode << std::endl;

					if(event.key.keysym.sym == SDLK_u)
					{
						m_Unicode = !m_Unicode;
						SDL::EnableUnicode(m_Unicode);
					}

					if(event.key.keysym.sym == SDLK_r)
					{
						m_Repeat = !m_Repeat;

						if(m_Repeat)
							SDL::EnableKeyRepeat(25, 5);
						else
							SDL::EnableKeyRepeat(0, 0);
					}
			
					if(event.key.keysym.sym == SDLK_s)
						m_Switch = !m_Switch;

					// This looks dangerous... 
					if(SDL::GetKeyState(null)[SDLK_LCTRL] && SDL::GetKeyState(null)[SDLK_c])
						m_Quit = true;
					break;

				case SDL_KEYUP:
					std::cout << "SDL_KEYUP:" << std::endl
						<< "\tevent.key.keysym.scancode: " << event.key.keysym.scancode << std::endl
						<< "\tevent.key.keysym.sym: " << event.key.keysym.sym << std::endl
						<< "\tevent.key.keysym.mod: " << event.key.keysym.mod << std::endl
						<< "\tevent.key.keysym.unicode: " << event.key.keysym.unicode << std::endl;
					break;

				case SDL_MOUSEMOTION:
					std::cout << "SDL_MOUSEMOTION: " << std::endl
						<< "\tevent.motion.state: " << event.motion.state << std::endl
						<< "\tevent.motion.x: " << event.motion.x << std::endl
						<< "\tevent.motion.y: " << event.motion.y << std::endl
						<< "\tevent.motion.xrel: " << event.motion.xrel << std::endl
						<< "\tevent.motion.yrel: " << event.motion.yrel << std::endl;
					break;

				case SDL_MOUSEBUTTONDOWN:
					std::cout << "SDL_MOUSEBUTTONUDOWN: " << std::endl
						<< "\tevent.button.button: " << event.button.button << std::endl
						<< "\tevent.button.x: " << event.button.x << std::endl
						<< "\tevent.button.y: " << event.button.y << std::endl;
					break;

				case SDL_MOUSEBUTTONUP:
					std::cout  << "SDL_MOUSEBUTTONUP:" << std::endl
						<< "\tevent.button.button: " << event.button.button << std::endl
						<< "\tevent.button.x: " << event.button.x << std::endl
						<< "\tevent.button.y: " << event.button.y << std::endl;
					break;

				case SDL_JOYAXISMOTION:
					std::cout << "SDL_JOYAXIS:" << std::endl
						<< "\tevent.jaxis.which: " << event.jaxis.which << std::endl
						<< "\tevent.jaxis.axis: " << event.jaxis.axis << std::endl
						<< "\tevent.jaxis.value: " << event.jaxis.value << std::endl;
					break;

				case SDL_JOYBALLMOTION:
					std::cout << "SDL_JOYBALL" << std::endl
						<< "\tevent.jball.which: " << event.jball.which << std::endl
						<< "\tevent.jball.ball: " << event.jball.ball << std::endl
						<< "\tevent.jball.xrel: " << event.jball.xrel << std::endl
						<< "\tevent.jball.yrel: " << event.jball.yrel << std::endl;
					break;

				case SDL_JOYHATMOTION:
					std::cout << "SDL_JOYHAT" << std::endl
						<< "\tevent.jhat.which: " << event.jhat.which << std::endl
						<< "\tevent.jhat.hat: " << event.jhat.hat << std::endl
						<< "\tevent.jhat.value: " << event.jhat.value << std::endl;
					break;

				case SDL_JOYBUTTONDOWN:
					std::cout << "SDL_JOYBUTTONDOWN" << std::endl
						<< "\tevent.jbutton.which: " << event.jbutton.which << std::endl
						<< "\tevent.jbutton.button: " << event.jbutton.button << std::endl;
					break;

				case SDL_JOYBUTTONUP:
					std::cout << "SDL_JOYBUTTONUP" << std::endl
						<< "\tevent.jbutton.which: " << event.jbutton.which << std::endl
						<< "\tevent.jbutton.button: " << event.jbutton.button << std::endl;
					break;

				case SDL_VIDEORESIZE:
					std::cout << "SDL_VIDEORESIZE" << std::endl
						<< "\tevent.resize.w: " << event.resize.w << std::endl
						<< "\tevent.resize.h: " << event.resize.h << std::endl;
			
					SDL::GetVideoSurface(screen);
					screen.SetVideoMode(event.resize.w, event.resize.h, 8, SDL_SWSURFACE | SDL_RESIZABLE);
					break;

				case SDL_VIDEOEXPOSE:
					std::cout << "SDL_VIDEOEXPOSE" << std::endl;
					break;

				case SDL_QUIT:
					std::cout << "SDL_QUIT" << std::endl;
					m_Quit = true;
					break;

				case SDL_SYSWMEVENT:
					std::cout << "SDL_SYSWMEVENT" << std::endl
						<< "\tevent.syswm.msg: " << event.syswm.msg << std::endl;
					break;
			}

			return true;
		}

		operator bool()
		{
			return m_Quit;
		}

		bool Switch()
		{
			return m_Switch;
		}

		void SetSwitch(bool makeswitch)
		{
			m_Switch = makeswitch;
		}
	private:
		bool m_Quit, m_Switch, m_Unicode, m_Repeat;
}; // 158 lines of code

int main(int argv, char *args[])
{
	SDL::Screen screen;
	SDL::Event events;
	TestHandler testhandler;
	AllHandler allhandler;
	bool useallhandler = false;

	SDL::Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
	atexit(SDL::Quit);
	std::vector<SDL::Joystick *> joysticks;
	
	if(SDL::NumJoysticks() < 1)
		std::cout << "No joysticks to poll." << std::endl;
	else
	{
		for(int i = 0; i < SDL::NumJoysticks(); i++)
		{
			joysticks.push_back(new SDL::Joystick);
			joysticks.at(i)->Open(i);
		}
	}

	screen.SetVideoMode(320,240, 8, SDL_SWSURFACE | SDL_RESIZABLE);

	while(!testhandler && !allhandler)
	{
		if(useallhandler)
			events.Poll(allhandler);
		else
			events.Poll(testhandler);

		if(allhandler.Switch() || testhandler.Switch())
		{
			useallhandler = !useallhandler;

			allhandler.SetSwitch(false);
			testhandler.SetSwitch(false);
		}
	}

	for(int i = 0; i < joysticks.size(); i++)
		delete joysticks.at(i);

	return 0;
}

