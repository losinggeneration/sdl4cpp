#ifndef PADDLE_H
#define PADDLE_H

#include <SDL4Cpp.h>

class Paddle
{
	public:
		Paddle();
		Paddle(int x, int y, int w, int h);
		~Paddle();

		void Set(int x, int y, int w, int h);
		// Move the paddle
		void Move(int vy);
		void Update();
		SDL::Rect &Draw(SDL::Screen &screen);
		// Get the paddle's dimenitions
		SDL::Rect Get();
	protected:
		SDL::Surface m_Paddle;
		SDL::Rect m_Rect;
		int vy;
};

#endif

