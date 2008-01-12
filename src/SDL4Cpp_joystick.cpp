/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with main.c; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include <stdexcept>
#include "SDL4Cpp_main.h"
#include "SDL4Cpp_joystick.h"

namespace SDL
{
	int NumJoysticks(void)
	{
		return SDL_NumJoysticks();
	}

	Joystick::Joystick(void)
	{
		m_Joystick = NULL;
		m_Index = -1;
	}
	
	Joystick::Joystick(int index)
	{
		if(!Open(index))
			throw SDL::RuntimeError(GetError());
	}
	
	Joystick::~Joystick(void)
	{
		if(!Close())
			throw SDL::RuntimeError(GetError());
	}

	bool Joystick::Open(int index)
	{
		m_Joystick = SDL_JoystickOpen(index);

		if(!m_Joystick)
			return false;

		m_Index = index;
		return true;
	}

	bool Joystick::Opened()
	{
		return Opened(m_Index);
	}
	
	bool Joystick::Opened(int index)
	{
		if(SDL_JoystickOpened(index) == 1)
			return true;

		return false;
	}
	
	int Joystick::Index(void)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to Index()");
		
		return SDL_JoystickIndex(m_Joystick);
	}
	
	std::string Joystick::Name()
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to Index()");

		return static_cast<std::string>(SDL_JoystickName(Index()));
	}
	
	void Joystick::Update(void)
	{
		SDL_JoystickUpdate();
	}
	
	int Joystick::NumAxes(void)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to NumAxes()");

		return SDL_JoystickNumAxes(m_Joystick);
	}
	
	int Joystick::NumBalls(void)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to NumBalls()");
		
		return SDL_JoystickNumBalls(m_Joystick);
	}
	
	int Joystick::NumHats(void)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to NumHats()");
		
		return SDL_JoystickNumHats(m_Joystick);
	}
	
	int Joystick::NumButtons(void)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to NumButtons()");
		
		return SDL_JoystickNumButtons(m_Joystick);
	}
	
	Sint16 Joystick::GetAxis(int axis)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to GetAxis()");
		
		return SDL_JoystickGetAxis(m_Joystick, axis);
	}
	
	Uint8 Joystick::GetHat(int hat)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to GetHat()");
		
		return SDL_JoystickGetHat(m_Joystick, hat);
	}
	
	bool Joystick::GetButton(int button)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to GetButton()");
		
		return SDL_JoystickGetButton(m_Joystick, button);
	}
	
	bool Joystick::GetBall(int ball, int &dx, int &dy)
	{
		if(!m_Joystick)
			throw SDL::LogicError("m_Joystick not intialized before call to GetBall()");

		if(SDL_JoystickGetBall(m_Joystick, ball, &dx, &dy) == -1)
			return false;

		return true;
	}
	
	bool Joystick::Close(void)
	{
		if(m_Joystick && Opened())
		{
			SDL_JoystickClose(m_Joystick);
			m_Joystick = NULL;
			m_Index = -1;
			return true;
		}
		
		return false;
	}
}

