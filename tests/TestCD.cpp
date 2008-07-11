#include <iostream>
#include <stdexcept>
#include "SDL4Cpp.h"

void CatchLogicErr()
{
	try
	{
		SDL::CD cd;

		cd.DriveStatus();
		cd.Play(0,0);
	}
	catch(std::logic_error e)
	{
		std::cout << "SDL::CD cd;\ncd.DriveStatus();\ncd.Play(0,0);\n"
				<< "Errors with above code. Check it out." << std::endl << std::endl;
	}
}

void CD_Status(SDL::CD &cd)
{
	std::cout << "The cd drive name is: " << cd.Name() << std::endl
			<< "If there is a CD I will now attempt to play it."
			<< " (note there will be no sound.)" << std::endl;

	if(cd.DriveStatus() == CD_TRAYEMPTY)
	{
		std::cout << "No CD in drive. Ending test now." << std::endl;
		exit(0);
	}
}

void PlayPartial(SDL::CD &cd, SDL::CDtrack *tracks)
{
	if(tracks[0].type != SDL_AUDIO_TRACK)
		exit(0);

	if(tracks[0].length > 100)
	{
		std::cout << "Playing first track, the first 100 frames.\n"
			<< "press 'q' without quotes and enter for next test." << std::endl;
		if(cd.Play(tracks[0].offset, 100) == false)
		{
			std::cout << SDL::GetError() << std::endl;
			exit(-1);
		}
	}

	while(std::cin.get() != 'q');

	if(cd.Stop() == false)
		exit(-1);
}

void PlayTrack2(SDL::CDtrack *tracks)
{
	SDL::CD cd(0);

	std::cout << "Track one now stopped, trying all of track two now.\n"
		<< "press 'q' without quotes and enter to finish up." << std::endl;
	if(tracks[1].type != SDL_AUDIO_TRACK)
		exit(0);

	if(cd.PlayTracks(1, 0, 1, 0) == false)
	{
		std::cout << SDL::GetError() << std::endl;
		exit(-1);
	}

	while(std::cin.get() != 'q');
	std::cin.get(); // catch \n from last while
	std::cout << "Stopping if not done." << std::endl;

	if(cd.Stop() == false)
		exit(-1);
}

int main(int argv, char *args[])
{
	SDL::Init(SDL_INIT_CDROM|SDL_INIT_AUDIO);
	atexit(SDL::Quit);

	if(SDL::CDNumDrives() < 1)
	{
		std::cout << "No CD drives to test." << std::endl;
		exit(0);
	}

	// Example of an SDL::CD logic error
	CatchLogicErr();

	SDL::CD cd(0);

	// Check the drive for an audio cd
	CD_Status(cd);

	// Get the tracks
	SDL::CDtrack *tracks = cd.Tracks();

	// Play a partial track 1
	PlayPartial(cd, tracks);

	// Play a full track 2 and open the CD drive in this function
	PlayTrack2(tracks);

	std::cout << "Eject for fun.\ny or n" << std::endl;
	if(std::cin.get() == 'y')
		cd.Eject();

	std::cout << "Done." << std::endl;
	return 0;
}

