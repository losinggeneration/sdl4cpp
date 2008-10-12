#ifndef BALL_H
#define BALL_H

#include <SDL4Cpp.h>

class Ball
{
	public:
		Ball();
		// setup the inital ball with specified location and velocity
		Ball(int x, int y, int w, int h, int vx, int vy);
		~Ball();

		// Set the location/velocity
		void Set(int x, int y, int w, int h, int vx, int vy);
		// change the velocity
		void SetVel(int vx, int vy);
		//update the logic (check bounds and change velocity if needed)
		void Update();
		// Do the drawing
		SDL::Rect &Draw(SDL::Screen &screen);
		// get the location rect
		SDL::Rect Get(int &vx, int &vy);
	private:
		// The ball surface
		SDL::Surface m_Ball;
		// the ball rect
		SDL::Rect m_Rect;
		// velocity variables
		int vx, vy;
};

#endif

