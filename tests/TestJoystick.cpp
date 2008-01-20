#include <iostream>
#include <vector>
#include "SDL4Cpp.h"

/*
 * This is a pretty simple test that uses most the functions for Joysticks
 * I don't use the default constructor because it just makes a NULL Joystick
 * I don't use Close because it's used by the destructor
 * I don't use Index because it's used by Name() internally so it works
 * Every other function (member or not) for joysticks is tested here
 *
 * Note though I don't use any events. Joysticks can be handled seperately as shown here
 *
 * Also note, never assume that the values for hats, balls, buttons, etc are
 * true since some joysticks may not accurately report the maximum they truely
 * have, but rather the Maximum they might have. For example, a universal USB
 * console gamepad adapter may report the maximum one of the compatible pads
 * could have. (This was how I found it out. This particular unit also posts
 * multiple inputs regardless of what's actually available. Thus the extra code
 * to allow for this type of behavior.)
 */
int main(int argv, char *args[])
{
	// Init SDL but we only need Joystick to be initialized
	SDL::Init(SDL_INIT_JOYSTICK);
	atexit(SDL::Quit);

	std::vector<SDL::Joystick *> joysticks;

	// first see if any Joysticks are there
	if(SDL::NumJoysticks() == 0)
	{
		// Note to beginners that because the constructors/funtions throw
		// errors, you can't just comment this out to try it.
		std::cout << "No joysticks available, so I'm not going to run the tests." << std::endl;
		exit(EXIT_FAILURE);
	}

	// if so get the first one @ 0 which will exist because there is at least one on this system (tested above)
	// I'll go ahead at check if it's opened, if it is there's probably something messed up with my lib code
	if(SDL::Joystick::Opened(0) == true)
	{
		std::cout << "This shouldn't happen... but the joystick at 0 is already opened so I'm quitting." << std::endl;
		exit(EXIT_FAILURE);
	}

	try
	{
		for(int i = 0; i < SDL::NumJoysticks(); i++)
			joysticks.push_back(new SDL::Joystick(i)); // This could throw...
	}
	catch(SDL::LogicError e)
	{
		std::cerr << "Error opening a joystick that should be available: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	// have some more fun with Opened() and then Name()
	for(int i = 0; i < SDL::NumJoysticks(); i++)
	{
		if(SDL::Joystick::Opened(i) == true)
			std::cout << "Joystick: " << joysticks.at(i)->Name() << " now opened" << std::endl;
	}

	// and try an unusually high number that shouldn't exist
	// this shows how to test for errors
	try
	{
		SDL::Joystick joystick(244);
	}
	catch(std::runtime_error e)
	{
		std::cout << "No joystick at 244" << std::endl;
	}

	// Ok, now print out some info about the joystick
	std::vector<int> hats, buttons, axes, balls;

	for(int i = 0; i < SDL::NumJoysticks(); i++)
	{
		hats.push_back(joysticks.at(i)->NumHats());
		buttons.push_back(joysticks.at(i)->NumButtons());
		axes.push_back(joysticks.at(i)->NumAxes());
		balls.push_back(joysticks.at(i)->NumBalls());

		std::cout << "This joystick " << i << " has: " << std::endl
			<< hats.at(i) << " hats," << std::endl
			<< buttons.at(i) << " buttons," << std::endl
			<< axes.at(i) << " axes, and" << std::endl
			<< balls.at(i) << " balls." << std::endl;
	}

	// to loop until it's true
	bool something = false;
	// to account for jitter it the joystick axes
	int jitterpos = 1000, jitterneg = -10000;
	// for the ball possition, needs an array for each possitons' change in x and y and make them all 0
	/*
	int dx[balls], dy[balls];
	for(int x = 0; x < balls; x++)
		dx[x] = dy[x] = 0;
	*/
	for(int i = 0; i < SDL::NumJoysticks(); i++)
	{
		if(buttons.at(i) < 2)
		{
			std::cout << "Joystick must have more than one button to really test it" << std::endl;
			return 0;
		}
	}

	bool ret = false;
	// Now loop till something is pressed or moved
	while(something == false)
	{
		// Update the joysticks
		SDL::Joystick::Update();

		// We need to check every available joystick
		for(int i = 0; i < SDL::NumJoysticks(); i++)
		{
			// check for hat movement, I assume the hats are centered
			for(int x = 0; x < hats.at(i); x++)
			{
				if(joysticks.at(i)->GetHat(x) != SDL_HAT_CENTERED)
				{
					std::cout << "Hat: " << x << "'s vaule: " << joysticks.at(i)->GetHat(x) << "\t";
					ret = true;
				}
			}

			// Check if any buttons are pressed
			for(int x = 0; x < buttons.at(i); x++)
			{
				if(joysticks.at(i)->GetButton(x) == true)
				{
					std::cout << "Button: " << x << "'s vaule: " << joysticks.at(i)->GetButton(x) << "\t";
					ret = true;
				}
			}

			// Check the Axes for any movement beyond -100 to 100, which are just numbers I chose
			// to account for jittering. These may need to be higher or lower.
			for(int x = 0; x < axes.at(i); x++)
			{
				if(joysticks.at(i)->GetAxis(x) > jitterpos || joysticks.at(i)->GetAxis(x) < jitterneg)
				{
					std::cout << "Axis: " << x << "'s vaule: " << joysticks.at(i)->GetAxis(x) << "\t";
					ret = true;
				}
			}
			/*
			// Finally check for movement from the balls, each ball has its own dx and dy.
			// To do this we send its dx and dy to GetBall and check if it's no longer 0
			for(int x = 0; x < balls; x++)
			{
				joystick->GetBall(x, dx[x], dy[x]);
				if(dx[x] != 0 || dy[x] != 0)
				{
					std::cout << "Ball: " << x << "'s value dx: " << dx[x] << "dy: " << dy[x] << "\t";
					ret = true;
				}
			}
			*/
			if(ret)
			{
				std::cout << std::endl;
				ret = false;
			}
		}
	}

	for(int i = 0; i < SDL::NumJoysticks(); i++)
		delete joysticks.at(i);

	return 0;
}

