#include "computer.h"

Computer::Computer() : Paddle()
{
}

Computer::Computer(int x, int y, int w, int h) : Paddle(x, y, w, h)
{
}

Computer::~Computer()
{
}

void Computer::UpdateAI(Ball &ball)
{
	int x, y;

	// Paddle goes up
	if(ball.Get(x, y).y < (m_Rect.y + 53))
		Move(-2);

	// Paddle goes down
	if(ball.Get(x, y).y >= (m_Rect.y + 53))
		Move(2);

	Update();
}

