#ifndef COMPUTER_H
#define COMPUTER_H

#include <SDL4Cpp.h>
#include "paddle.h"
#include "ball.h"

// yes, a computer is a paddle
class Computer : public Paddle
{
	public:
		Computer();
		Computer(int x, int y, int w, int h);
		~Computer();

		// See where the ball is and follow
		void UpdateAI(Ball &ball);
};

#endif

