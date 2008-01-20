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

#ifndef SDL4CPP_WM_H
#define SDL4CPP_WM_H

#include "SDL.h"
#include <string>


namespace SDL
{
	/*!
	 * \defgroup WM Window managment.
	 */
	//@{
	/*!
	 * \brief Window Managment.
	 *
	 *  These are in a sub-namespace because they all are functions
	 *  (not classes) that have to do with window management
	 */
	namespace WM
	{
		/*!
		 * \brief Mode of grabbing input
		 *
		 * \b Enum \b Definition
		 * \code
		 * typedef enum
		 * {
		 *	SDL_GRAB_QUERY,
		 *	SDL_GRAB_OFF,
		 *	SDL_GRAB_ON
		 * } SDL_GrabMode;
		 * \endcode
		 */
		typedef SDL_GrabMode GrabMode;

		/*!
		 * \brief Sets the window tile and icon name.
		 *
		 * Sets the title-bar and icon name of the display window.
		 *
		 * \param title is the name you want the window to have
		 * \param icon is the filename of the icon to use.
		 */
		void SetCaption(std::string title = "", std::string icon = "");
		/*!
		 * \brief Gets the window title and icon name.
		 *
		 * \param title is a referance to the name to fill with the name of the
		 * window.
		 * \param icon is a referance to the icon to fill with the file
		 * location of the icon.
		 * \param windownumber the number of the returned string array to use.
		 */
		void GetCaption(std::string &title, std::string &icon);
		/*!
		 * \brief Get just the title of a window.
		 *
		 * \param windownumber the number of the returned string array to use.
		 *
		 * \return A std::string of the window's title.
		 */
		std::string GetTitle(void);
		/*!
		 * \brief Get just the icon of a window.
		 *
		 * \param windownumber the number of the returned string array to use.
		 *
		 * \return A std::string of the icon's filename.
		 */
		std::string GetIcon(void);

		/*!
		 * \brief Iconify/Minimise the window
		 *
		 * If the application is running in a window managed environment SDL
		 * attempts to iconify/minimise it.
		 * If SDL::WM::IconifyWindow() is successful, the application will
		 * receive a SDL_APPACTIVE loss event.
		 *
		 * \return False if iconification is not support or was refused by the
		 * window manager, true on success.
		 */
		bool IconifyWindow(void);
		/*!
		 * \brief Grabs mouse and keyboard input.
		 *
		 * Grabbing means that the mouse is confined to the application window,
		 * and nearly all keyboard input is passed directly to the application,
		 * and not interpreted by a window manager, if any.
		 *
		 * When mode is SDL_GRAB_QUERY the grab mode is not changed, but the
		 * current grab mode is returned.
		 *
		 * \b Enum \b Definition
		 * \code
		 * typedef enum {
		 *	SDL_GRAB_QUERY,
		 *	SDL_GRAB_OFF,
		 *	SDL_GRAB_ON
		 * } SDL_GrabMode;
		 * \endcode
		 *
		 * \return The current/new GrabMode.
		 */
		GrabMode GrabInput(GrabMode mode);
	}
	//@}
}

#endif

