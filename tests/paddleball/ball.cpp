#include <iostream>
#include "ball.h"

Ball::Ball()
{
	if(!m_Ball.LoadBMP("ball.bmp"))
	{
		std::cerr << "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}
}

Ball::Ball(int x, int y, int w, int h, int vx, int vy)
{
	if(!m_Ball.LoadBMP("ball.bmp"))
	{
		std::cerr << "Encountered the following error: " << SDL::GetError() << std::endl;
		exit(1);
	}

	Set(x, y, w, h, vx, vy);
}

Ball::~Ball()
{
}

void Ball::Set(int x, int y, int w, int h, int vx, int vy)
{
	m_Rect.x = x;
	m_Rect.y = y;
	m_Rect.w = w;
	m_Rect.h = h;
	this->vx = vx;
	this->vy = vy;
}

void Ball::SetVel(int vx, int vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Ball::Update()
{
	// check bounds
	if(m_Rect.x > 0 || m_Rect.x < 640)
		m_Rect.x += vx;
	if(m_Rect.y > 0 || m_Rect.y < 480)
		m_Rect.y += vy;

	// if the ball hits the bottom  or top, inverse the velocity;
	if((m_Rect.x + 11) >= 640 || m_Rect.x <= 0)
		vx *= -1;
	if((m_Rect.y + 11) >= 480 || m_Rect.y <= 0)
		vy *= -1;
}

SDL::Rect &Ball::Draw(SDL::Screen &screen)
{
	screen.Blit(m_Ball, m_Rect);
	return m_Rect;
}

SDL::Rect Ball::Get(int &vx, int &vy)
{
	vx = this->vx;
	vy = this->vy;

	return m_Rect;
}

