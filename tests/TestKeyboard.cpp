#include <iostream>
#include <string>
#include <vector>
#include "SDL4Cpp.h"

int main(int argv, char *args[])
{
	SDL::Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK);
	atexit(SDL::Quit);
	
	SDL::Surface One, Two;
	SDL::Surface Three = One;

	SDL::Surface Four;
	Four = One;

	if(Four == Two)
		std::cout << "Four and Two are equal"  << std::endl;

	SDL::Surface icon;
	icon.LoadBMP("icon.bmp");
	
	
	SDL::Screen screen(icon, NULL);
	screen.SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	
//	while(events.Poll(handler) == false);
	return 0;
}

