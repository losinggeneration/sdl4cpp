#include <iostream>
#include <string>
#include <vector>
#include "SDL4Cpp.h"

// SDL way of making it run the same everywhere
Uint32 PassTime()
{
	static Uint32 nextTime = 0;
	Uint32 now = SDL_GetTicks();

	if(nextTime <= now)
	{
		nextTime = now+30;
		return 0;
	}

	return nextTime - now;
}

// Make sure it runs the same everywhere
void Delay()
{
	SDL_Delay(PassTime());
}

int main(int argv, char *args[])
{
	// The events for SDL
	SDL::Event events;
	// and the handler to handle the events
	class handler : public SDL::Handle
	{
		public:
			handler()
			{
				stop = false;
			}

			bool KeyPressed(SDL::KeySym &keysym)
			{
				if(keysym.sym == SDLK_ESCAPE)
					stop = true;

				// Returns true so a call to SDL::Handle::All() isn't tried
				// Only to avoid an extra call that would do nothing
				return true;
			}

			// If the class is used as a boolean such as if(handler) do something
			operator bool()
			{
				return stop;
			}
		private:
			bool stop;
	} handle;

	SDL::Init(SDL_INIT_VIDEO);
	atexit(SDL::Quit);
	// Check to show that the overloaded operators work first
	SDL::Surface One, Two;
	One.LoadBMP("bitmap.bmp");
	Two = One;

	SDL::Surface Three = One;

	SDL::Surface Four;
	Four = One;
	SDL::Surface temp(SDL_LoadBMP("icon.bmp"));

	// Should be equal
	if(Four == Two)
		std::cout << "Good: Four and Two are equal"  << std::endl;
	else
	{
		std::cerr << "Bad: Four and Two are not equal"  << std::endl;
		exit(EXIT_FAILURE);
	}

	SDL::Surface icon;
	icon.LoadBMP("icon.bmp");

	//  Should not be equal
	if(icon == Four)
	{
		std::cerr << "Bad: icon and Four are equal" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "Good: icon and Four not equal" << std::endl;

	// Should be equal
	if(temp == icon)
		std::cout << "Good: temp now has a copy of icon and they're equal" << std::endl;
	else
	{
		std::cerr << "Bad: temp and icon aren't equal" << std::endl;
		exit(EXIT_FAILURE);
	}

	One = icon;

	// Should be equal
	if(icon == One)
		std::cout << "Good: One now has a copy of icon and they're equal" << std::endl;
	else
	{
		std::cerr << "Bad: One and icon aren't equal" << std::endl;
		exit(EXIT_FAILURE);
	}

	if(Two != One)
		std::cout << "Good: Two does NOT equal One." << std::endl;
	else
	{
		std::cerr << "Bad: Two DOES equal One." << std::endl;
		exit(EXIT_FAILURE);
	}

	// Now set setup screen with this icon to continue some basic tests.
	SDL::Screen screen(icon, NULL);
	screen.SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	// Setup a rectangle to move the sprite
	int vx = 1, vy = 1;
	int width = icon.GetRect().w, height = icon.GetRect().h;

	// Three rects, One for current position, one for pevious position, and one to store the two prior rects to update
	SDL::Rect moveit(0, 0, width, height);
	SDL::Rect previous = moveit;
	SDL::Rect rect[2] = { moveit, previous };

	while(!handle)
	{
		// Fill the previous location with black
		screen.FillRect(previous, 0);
		// Move the position to draw the rect out of the just draw area
		moveit.x += vx;
		moveit.y += vy;
		// Try to blit the image to the screen
		if(!screen.Blit(icon, moveit))
			std::cout << "Not blitted: " << SDL::GetError() << std::endl;

		// If the image is over the bounds of the screen, reverse the velocity of the object
		if(moveit.x+width >= 640)
			vx = -1;
		if(moveit.x <= 0)
			vx = 1;

		if(moveit.y+height >= 486)
			vy = -1;
		if(moveit.y <= 0)
			vy = 1;

		// Update the two rects in the array to update on the screen
		rect[0] = moveit;
		rect[1] = previous;
		// Finally update the screen
		screen.UpdateRects(2, rect);

		// Now set previous to the previous location of the sprite (current but that will be moved before blitted
		previous = moveit;
		// Try for events
		events.Poll(handle);
		// Delay the execution so it runs  more uniform everywhere
		Delay();
	}

	return 0;
}

