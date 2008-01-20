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

#include <cassert>
#include <iostream>
#include "SDL4Cpp_main.h"
#include "SDL4Cpp_wm.h"
#include "SDL4Cpp_video.h"

// Will need modifications when Video is written
namespace SDL
{

	namespace WM
	{
		void SetCaption(std::string title, std::string icon)
		{
			SDL_WM_SetCaption(title.c_str(), icon.c_str());
		}

		void GetCaption(std::string &title, std::string &icon)
		{
			char *ctitle = 0, *cicon = 0;
			SDL_WM_GetCaption(&ctitle, &cicon);

			if(ctitle != NULL)
				title = static_cast<std::string>(ctitle);

			if(cicon != NULL)
				icon = static_cast<std::string>(cicon);
		}

		std::string GetTitle(void)
		{
			char *title = 0;
			SDL_WM_GetCaption(&title, NULL);

			if(title != NULL)
				return static_cast<std::string>(title);

			return "";
		}

		std::string GetIcon(void)
		{
			char *icon = 0;
			SDL_WM_GetCaption(NULL, &icon);

			if(icon != NULL)
				return static_cast<std::string>(icon);

			return "";
		}

		bool IconifyWindow(void)
		{
			if(SDL_WM_IconifyWindow() == 0)
				return false;

			return true;
		}

		GrabMode GrabInput(GrabMode mode)
		{
			return
					static_cast<GrabMode>(SDL_WM_GrabInput(
										  static_cast<SDL_GrabMode>(mode)));
		}
	}
}

