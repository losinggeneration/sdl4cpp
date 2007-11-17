#include <iostream>
// Needed for execeptions.
// Just thought I'd note that for any beginners
#include <stdexcept>
#include "SDL4Cpp.h"

// This is a pretty simple test that uses most the functions for Joysticks
// I don't use the default constructor because it just makes a NULL Joystick
// I don't use Close because it's used by the destructor
// I don't use Index because it's used by Name() internally so it works
// Every other function (member or not) for joysticks is tested here
// Note though I don't use any events. Joysticks can be handled seperately as shown here
int main(int argv, char *args[])
{
	// Init SDL but we only need Joystick to be initialized
	SDL::Init(SDL_INIT_JOYSTICK);
	atexit(SDL::Quit);
	
	// first see if any Joysticks are there
	if(SDL::NumJoysticks() == 0)
	{
		// Note to beginners that because the constructors/funtions throw errors, you can't just comment this out to try it.
		std::cout << "No joysticks available, so I'm not going to run the tests." << std::endl;
		exit(0);
	}

	// if so get the first one @ 0 which will exist because there is at least one on this system (tested above)
	// I'll go ahead at check if it's opened, if it is there's probably something messed up with my lib code
	if(SDL::Joystick::Opened(0) == true)
	{
		std::cout << "This shouldn't happen... but the joystick at 0 is already opened so I'm quitting." << std::endl;
		exit(0);
	}

	// This could throw...
	SDL::Joystick *joystick0 = new  SDL::Joystick(0);
	// have some more fun with Opened() and then Name()
	if(SDL::Joystick::Opened(0) == true)
		std::cout << "Joystick: " << joystick0->Name() << " now opened" << std::endl;

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
	int hats = joystick0->NumHats(), buttons = joystick0->NumButtons(), axes = joystick0->NumAxes(), balls = joystick0->NumBalls();

	std::cout << "This joystick has: " << std::endl
		<< hats << " hats," << std::endl
		<< buttons << " buttons," << std::endl
		<< axes << " axes, and" << std::endl
		<< balls << " balls." << std::endl;
	
	// to loop until it's true
	bool something = false;
	// to account for jitter it the joystick axes
	int jitterpos = 1000, jitterneg = -10000;
	// for the ball possition, needs an array for each possitons' change in x and y and make them all 0
	int dx[balls], dy[balls];
	for(int x = 0; x < balls; x++)
		dx[x] = dy[x] = 0;

	if(buttons < 2)
	{
		std::cout << "Joystick must have more than one button to really test it" << std::endl;
		return 0;
	}
	
	bool ret = false;
	// Now loop till something is pressed or moved
	while(something == false)
	{
		SDL::Joystick::Update();

		// check for hat movement, I assume the hats are centered
		for(int x = 0; x < hats; x++)
			if(joystick0->GetHat(x) != SDL_HAT_CENTERED)
			{
				std::cout << "Hat: " << x << "'s vaule: " << joystick0->GetHat(x) << "\t";
				ret = true;
			}
		
		// Check if any buttons are pressed
		for(int x = 0; x < buttons; x++)
			if(joystick0->GetButton(x) == true)
			{
				std::cout << "Button: " << x << "'s vaule: " << joystick0->GetButton(x) << "\t";
				ret = true;
			}
		
		// Check the Axes for any movement beyond -100 to 100, which are just numbers I chose
		// to account for jittering. These may need to be higher or lower.
		for(int x = 0; x < axes; x++)
			if(joystick0->GetAxis(x) > jitterpos || joystick0->GetAxis(x) < jitterneg)
			{
				std::cout << "Axis: " << x << "'s vaule: " << joystick0->GetAxis(x) << "\t";
				ret = true;
			}

		// Finally check for movement from the balls, each ball has its own dx and dy.
		// To do this we send its dx and dy to GetBall and check if it's no longer 0
		for(int x = 0; x < balls; x++)
		{
			joystick0->GetBall(x, dx[x], dy[x]);
			if(dx[x] != 0 || dy[x] != 0)
			{
				std::cout << "Ball: " << x << "'s value dx: " << dx[x] << "dy: " << dy[x] << "\t";
				ret = true;
			}
		}
		
		if(ret)
		{
			std::cout << std::endl;
			ret = false;
		}
	}

	delete joystick0;
	

	return 0;
}

