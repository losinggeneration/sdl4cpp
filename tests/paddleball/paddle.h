#ifndef PADDLE_H
#define PADDLE_H

#include <SDL4Cpp.h>

class Paddle
{
	public:
		// setup the paddle
		Paddle();
		Paddle(int x, int y, int w, int h);
		~Paddle();

		void Set(int x, int y, int w, int h);
		// Move the paddle
		void Move(int vy);
		// update paddle position
		void Update();
		// draw and return paddles rect
		SDL::Rect &Draw(SDL::Screen &screen);
		// Get the paddle's dimenitions
		SDL::Rect Get();
	protected:
		// paddle image
		SDL::Surface m_Paddle;
		// paddle rect
		SDL::Rect m_Rect;
		// velocity
		int vy;
};

#endif

