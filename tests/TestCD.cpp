#include <iostream>
#include <stdexcept>
#include "SDL4Cpp.h"

int main(int argv, char *args[])
{
	SDL::Init(SDL_INIT_CDROM|SDL_INIT_AUDIO);
	atexit(SDL::Quit);

	if(SDL::CDNumDrives() < 1)
	{
		std::cout << "No CD drives to test." << std::endl;
		exit(0);
	}

	try
	{
		SDL::CD cd;

		cd.Status();

		cd.Play(0,0);
	}
	catch(std::logic_error e)
	{
		std::cout << "SDL::CD cd;\ncd.Status();\ncd.Play(0,0);\n";

		std::cout << "Errors with above code. Check it out." << std::endl << std::endl;
	}

	SDL::CD cd(0);

	std::cout << "The cd drive name is: " << cd.Name() << std::endl;

	std::cout << "If there is a CD I will now attempt to play it. (note there will be no sound.)" << std::endl;

	if(cd.Status() == CD_TRAYEMPTY)
	{
		std::cout << "No CD in drive. Ending test now." << std::endl;
		exit(0);
	}

	SDL::CDtrack *tracks = cd.GetTracks();
	if(tracks[0].type != SDL_AUDIO_TRACK)
		exit(0);

	if(tracks[0].length > 100)
	{
		std::cout << "Playing first track, the first 100 frames.\npress 'q' without quotes and enter for next test." << std::endl;
		if(cd.Play(tracks[0].offset, 100) == false)
		{
			std::cout << SDL::GetError() << std::endl;
			exit(-1);
		}
	}

	while(std::cin.get() != 'q');

	cd.Stop();

	std::cout << "Track one now stopped, trying all of track two now.\npress 'q' without quotes and enter to finish up." << std::endl;
	if(tracks[1].type != SDL_AUDIO_TRACK)
		exit(0);

	if(cd.PlayTracks(1, 0, 1, 0) == false)
	{
		std::cout << SDL::GetError() << std::endl;
		exit(-1);
	}

	while(std::cin.get() != 'q');
	std::cout << "Stopping if not done." << std::endl;

	if(cd.Stop() == false)
		exit(-1);

	// catch \n from last while
	std::cin.get();
	std::cout << "Eject for fun.\ny or n" << std::endl;
	if(std::cin.get() == 'y')
		cd.Eject();

	std::cout << "Done." << std::endl;
	return 0;
}

