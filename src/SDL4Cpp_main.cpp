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

#include "SDL4Cpp_main.h"

namespace SDL
{
	bool Init(Uint32 flags)
	{
		if(SDL_Init(flags) == -1)
			return false;

		return true;
	}
	
	bool InitSubSystem(Uint32 flags)
	{
		if(SDL_InitSubSystem(flags) == -1)
			return false;

		return true;
	}

	void QuitSubSystem(Uint32 flags)
	{
		SDL_QuitSubSystem(flags);
	}
	
	void Quit(void)
	{
		SDL_Quit();
	}
	
	Uint32 WasInit(Uint32 flags)
	{
		return SDL_WasInit(flags);
	}
	
	std::string GetError(void)
	{
		return static_cast<std::string>(SDL_GetError());
	}
	
	void ClearError(void)
	{
		SDL_ClearError();
	}
	
	void *LoadObject(const std::string sofile)
	{
		return SDL_LoadObject(sofile.c_str());
	}
	
	void *LoadFunction(void *handle, const std::string name)
	{
		return SDL_LoadFunction(handle, name.c_str());
	}
	
	void UnloadObject(void *handle)
	{
		SDL_UnloadObject(handle);
	}
	
	const Version *LinkedVersion(void)
	{
		return SDL_Linked_Version();
	}
}

