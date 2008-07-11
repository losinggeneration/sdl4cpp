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

#include "SDL_syswm.h"
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
		 * \brief System-specific window-manager info
		 *
		 * This structure is filled in by SDL_GetWMInfo.
		 *
		 * \sa SDL_GetWMInfo
		 *
		 * \b Structure \b Definition
		 * Generic
		 * \code
		 * typedef struct
		 * {
		 * 	SDL_version version;
		 * 	int data;
		 * } SDL_SysWMinfo;
		 * \endcode
		 * X11
		 * \code
		 * typedef enum
		 * {
		 * 	SDL_SYSWM_X11
		 * } SDL_SYSWM_TYPE;
		 *
		 * typedef struct
		 * {
		 * 	SDL_version version;
		 * 	SDL_SYSWM_TYPE subsystem;
		 * 	union
		 * 	{
		 * 		struct
		 * 		{
		 * 			Display *display;       // The X11 display
		 * 			Window window;          // The X11 display window
		 * 			// These locking functions should be called around
		 * 			// any X11 functions using the display variable.
		 *			// They lock the event thread, so should not be
		 *			// called around event functions or from event filters.
		 *
		 *			void (*lock_func)(void);
		 *			void (*unlock_func)(void);
		 *			// Introduced in SDL 1.0.2
		 *			Window fswindow;        // The X11 fullscreen window
		 *			Window wmwindow;        // The X11 managed input window
		 *		} x11;
		 *	} info;
		 * } SDL_SysWMinfo;
		 * \endcode
		 * 
		 * Windows
		 * \code
		 * typedef struct
		 * {
		 * 	SDL_version version;
		 * 	HWND window;                    // The Win32 display window
		 * 	HGLRC hglrc;                    // The OpenGL context, if any
		 * } SDL_SysWMinfo;
		 * \endcode
		 * 
		 * RISCOS
		 * \code
		 * typedef struct
		 * {
		 * 	SDL_version version;
		 * 	int wimpVersion;    // Wimp version running under
		 * 	int taskHandle;     // The RISCOS task handle
		 * 	int window;         // The RISCOS display window
		 * } SDL_SysWMinfo;
		 * \endcode
		 */
		typedef SDL_SysWMinfo SysWMinfo;

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

		/*!
		 * \brief Gets window-manager specific information, if available.
		 *
		 * This function fills in the structure pointed to by info with window-manager
		 * specific information. The info.version field has to be set to the used SDL
		 * version. Perhaps Windows specific: -1 on failure
		 *
		 * \return true if the function is implemented, false otherwise.
		 * \sa SDL_SysWMInfo
		 *
		 * \code
		 * // ... some code here ...
		 * SDL_VERSION(&info.version); // this is important!
		 * if (SDL_GetWMInfo(&info))
		 * 	// ... structure manipulating code ...
		 * // ... some code here ...
		 * \endcode
		 */
		bool GetWMInfo(SysWMinfo &info);
	}
	//@}
}

#endif

