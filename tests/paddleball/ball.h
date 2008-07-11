#ifndef BALL_H
#define BALL_H

#include <SDL4Cpp.h>

class Ball
{
	public:
		Ball();
		Ball(int x, int y, int w, int h, int vx, int vy);
		~Ball();

		void Set(int x, int y, int w, int h, int vx, int vy);
		void SetVel(int vx, int vy);
		void Update();
		SDL::Rect &Draw(SDL::Screen &screen);
		SDL::Rect Get(int &vx, int &vy);
	private:
		SDL::Surface m_Ball;
		SDL::Rect m_Rect;
		int vx, vy;
};

#endif

