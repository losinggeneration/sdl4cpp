#ifndef COMPUTER_H
#define COMPUTER_H

#include <SDL4Cpp.h>
#include "paddle.h"
#include "ball.h"

class Computer : public Paddle
{
	public:
		Computer();
		Computer(int x, int y, int w, int h);
		~Computer();

		void UpdateAI(Ball &ball);
};

#endif

