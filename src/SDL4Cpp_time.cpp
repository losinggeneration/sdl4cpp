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
#include "SDL4Cpp_time.h"

namespace SDL
{
	Uint32 GetTicks(void)
	{
		return SDL_GetTicks();
	}
	
	void Delay(Uint32 ms)
	{
		SDL_Delay(ms);
	}
	
	TimerID AddTimer(Uint32 interval, SDL_NewTimerCallback callback, void *param)
	{
		return SDL_AddTimer(interval, callback, param);
	}
	
	bool RemoveTimer(TimerID id)
	{
		return SDL_RemoveTimer(id);
	}
	
	int SetTimer(Uint32 interval, SDL_TimerCallback callback)
	{
		return SDL_SetTimer(interval, callback);
	}

	Timer::Timer()
	{
	}
	
	Timer::~Timer()
	{
		while(Remove() != false);
	}

	bool Timer::Add(Uint32 interval, SDL_NewTimerCallback callback, void *param)
	{
		TimerID ID = SDL_AddTimer(interval, callback, param);

		if(ID == 0)
			return false;
		
		m_ID.push_back(ID);

		return true;
	}
	
	bool Timer::Remove()
	{
		bool returner = false;
		
		if(m_ID.size() != 0)
		{
			returner = SDL_RemoveTimer(m_ID.back());
			m_ID.pop_back();
		}

		return returner;
	}
	
}

