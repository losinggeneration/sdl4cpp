#include <iostream>
#include <ctime>
#include "ball.h"
#include "paddle.h"
#include "computer.h"
#include "score.h"

#include <SDL4Cpp.h>

class HandleInput : public SDL::Handle
{
	public:
		HandleInput(Paddle &paddle) : m_Paddle(paddle)
		{
			m_Quit = false;
		}

		bool KeyPressed(SDL::KeySym &keysym)
		{
			if(keysym.sym == SDLK_UP ||  keysym.sym == SDLK_q)
				m_Paddle.Move(-3);

			if(keysym.sym == SDLK_DOWN || keysym.sym == SDLK_a)
				m_Paddle.Move(3);

			if(keysym.sym == SDLK_ESCAPE)
				m_Quit = true;

			return true;
		}

		bool KeyReleased(SDL::KeySym &keysym)
		{
			m_Paddle.Move(0);
			return true;
		}

		operator bool()
		{
			return m_Quit;
		}
	private:
		Paddle &m_Paddle;
		bool m_Quit;
};

void Setup()
{
	SDL::Screen screen;

	if(!SDL::Init(SDL_INIT_VIDEO))
	{
		std::cerr <<  "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}

	SDL::WM::SetCaption("Paddle Ball SDL4Cpp example", "");

	if(!screen.SetVideoMode(640, 480, 32, SDL_DOUBLEBUF|SDL_HWSURFACE))
	{
		std::cerr <<  "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}

	// setup  a random number generator
	srand(time(0));
}

// SDL way of making it run the same everywhere
Uint32 PassTime()
{
	static Uint32 nextTime = 0;
	Uint32 now = SDL::GetTicks();

	if(nextTime <= now)
	{
		nextTime = now+30;
		return(0);
	}

	return(nextTime-now);
}

void Delay()
{
	SDL::Delay(PassTime());
}

void Game()
{
	SDL::Screen screen;
	SDL::GetVideoSurface(screen);
	SDL::Event events;
	SDL::Rect updaterects[6];
	SDL::Rect all(0, 0, 640, 480);
	SDL::Rect ballrect, play1rect, comrect;
	int ballvx, ballvy;
	bool playerwon = false;

	Score score;
	Ball ball(309, 229, 11, 11, ((rand() % 4) + 2), -((rand() % 4) + 2));
	Computer computer(629, 187, 11, 106);

	Paddle playerone(0, 187, 11, 106);
	HandleInput handleinput(playerone);

	while(!handleinput)
	{
		// Update everything
		ball.Update();
		playerone.Update();
		computer.UpdateAI(ball);

		// needed for game logic
		ballrect = ball.Get(ballvx, ballvy);
		play1rect = playerone.Get();
		comrect = computer.Get();

		// check if it hit the paddle for player and then the same for computer
		if((ballrect.x <= 11) &&
				(ballrect.y >= play1rect.y) &&
				((ballrect.y+11) <= play1rect.y + 106))
		{
			ball.SetVel(-ballvx, ballvy);
		}

		if(((ballrect.x + 11) >= 629) &&
				(ballrect.y >= comrect.y) &&
				((ballrect.y+11) <= comrect.y + 106))
		{
			ball.SetVel(-ballvx, ballvy);
		}

		// scoring if it goes past either paddle
		if(ballrect.x+10 < 11)
		{
			ball.Set(309, 229, 11, 11, ((rand() % 4) + 2), ((rand() % 4) + 2));
			score.m_Two++;
		}

		if(ballrect.x+10 > 629)
		{
			ball.Set(309, 229, 11, 11, -((rand() % 4) + 2), -((rand() % 4) + 2));
			score.m_One++;
		}

		// somene's won
		if(score.m_One > 9)
		{
			std::cout << "Congrats, you won." << std::endl;
			playerwon = true;
			break;
		}
		if(score.m_Two > 9)
		{
			std::cout << "Sorry, you lost, try again." << std::endl;
			break;
		}

		// drawing code
		screen.FillRect(all, 0);

		updaterects[0] = ball.Draw(screen);
		updaterects[1] = computer.Draw(screen);
		updaterects[2] = playerone.Draw(screen);
		score.Draw(screen, updaterects[3], updaterects[4]);

		if((screen.Get()->flags & SDL_DOUBLEBUF) == SDL_DOUBLEBUF)
			screen.Flip();
		else
		{
			updaterects[5] = all;
			screen.UpdateRects(6, updaterects);
		}

		// Poll for new events, then wait a bit
		events.Poll(handleinput);
		Delay();
	}
}

int main(int argv, char *argc[])
{
	Setup();

	Game();

	return 0;
}

