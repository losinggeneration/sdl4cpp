#include <iostream>
#include <stdexcept>
#include "paddle.h"

Paddle::Paddle()
{
	if(!m_Paddle.LoadBMP("paddle.bmp"))
	{
		std::cerr <<  "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}
	vy = 0;
}

Paddle::Paddle(int x, int y, int w, int h)
{
	if(!m_Paddle.LoadBMP("paddle.bmp"))
	{
		std::cerr <<  "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}

	Set(x, y, w, h);
	vy = 0;
}

Paddle::~Paddle()
{
}

void Paddle::Set(int x, int y, int w, int h)
{
	m_Rect.x = x;
	m_Rect.y = y;
	m_Rect.w = w;
	m_Rect.h = h;
}

// Move the paddle
// set vy to 0 to stop
// Negative numbers moves it up
// and positive moves it down
void Paddle::Move(int vy)
{
	this->vy = vy;
}

void Paddle::Update()
{
	// bad practice using a constant for the screen....
	if(m_Rect.y >= 0 && (m_Rect.y + 106) <= 480)
		m_Rect.y += vy;

	if(m_Rect.y < 0 || (m_Rect.y + 106) > 480)
		m_Rect.y += -vy;

}

SDL::Rect &Paddle::Draw(SDL::Screen &screen)
{
	if(!screen.Blit(m_Paddle, m_Rect))
	{
		std::cerr <<  "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}

	return m_Rect;
}

// Get the paddle's dimenitions
SDL::Rect Paddle::Get()
{
	return m_Rect;
}

