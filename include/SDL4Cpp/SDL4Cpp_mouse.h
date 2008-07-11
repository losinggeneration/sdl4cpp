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

#ifndef SDL4CPP_MOUSE_H
#define SDL4CPP_MOUSE_H

#include <string>
#include "SDL_mouse.h"


namespace SDL
{
	/*!
	 * \defgroup Cursor Cursor related functions and class.
	 */
	//@{

	/*!
	 * \brief Toggle whether or not the cursor is shown on the screen.
	 *
	 */
	int ShowCursor(int toggle);

	/*!
	 * \brief Set the position of the mouse cursor.
	 *
	 */
	void WarpMouse(Uint16 x, Uint16 y);

	/*!
	 * \brief SDL_Cursor wrapper.
	 *
	 * \todo Finish Documentation.
	 */
	class Cursor
	{
		public:
			/*!
			 * \brief Default Constructor.
			 *
			 */
			Cursor();
			/*!
			 * \brief Copy constructor.
			 *
			 */
			Cursor(const Cursor &cursor);
			/*!
			 * \brief Sets cursor to this image.
			 *
			 */
			Cursor(const char *image[]);
			/*!
			 * \brief Destructor.
			 *
			 */
			~Cursor();

			/*!
			 * \brief Creates a new mouse cursor.
			 *
			 */
			bool Create(Uint8 &data, Uint8 &mask, int w, int h, int hot_x,
						int hot_y);
			/*!
			 * \brief Set this Cursor to the currently active mouse cursor.
			 *
			 */
			void Set();
			/*!
			 * \brief Sets the Cursor from the data in image.
			 *
			 * \code
			 * // Stolen from the mailing list.
			 * // Then stolen from SDL's documentation.
			 * // Creates a new mouse cursor from an XPM
			 *
			 * Cursor cursor;
			 *
			 * // XPM
			 * static const char *arrow[] =
			 * {
			 *	// width height num_colors chars_per_pixel
			 *	"    32    32        3            1",
			 *	// colors
			 *	"X c #000000",
			 *	". c #ffffff",
			 *	"  c None",
			 *	// pixels
			 *	"X                               ",
			 *	"XX                              ",
			 *	"X.X                             ",
			 *	"X..X                            ",
			 *	"X...X                           ",
			 *	"X....X                          ",
			 *	"X.....X                         ",
			 *	"X......X                        ",
			 *	"X.......X                       ",
			 *	"X........X                      ",
			 *	"X.....XXXXX                     ",
			 *	"X..X..X                         ",
			 *	"X.X X..X                        ",
			 *	"XX  X..X                        ",
			 *	"X    X..X                       ",
			 *	"     X..X                       ",
			 *	"      X..X                      ",
			 *	"      X..X                      ",
			 *	"       XX                       ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"                                ",
			 *	"0,0"
			 * };
			 * cursor.Set(arrow);
			 * \endcode
			 */
			void Set(const char *image[]);
			/*!
			 * \brief Set the currently active mouse cursor.
			 *
			 */
			friend void SetCursor(Cursor &cursor);
			/*!
			 * \brief Get the currently active mouse cursor.
			 *
			 */
			friend Cursor GetCursor();

		protected:
			/*!
			 * \brief The cursor for this class
			 *
			 * This is the variable that most all the work is done to.
			 *
			 * \b Structure \b Definition
			 * \code
			 * typedef struct SDL_Cursor
			 * {
			 *	SDL_Rect area;			// The area of the mouse cursor
			 *	Sint16 hot_x, hot_y;		// The "tip" of the cursor
			 *	Uint8 *data;			// B/W cursor data
			 *	Uint8 *mask;			// B/W cursor mask
			 *	Uint8 *save[2];			// Place to save cursor area
			 *	WMcursor *wm_cursor;		// Window-manager cursor, implementation dependant
			 * } SDL_Cursor;
			 * \endcode
			 */
			SDL_Cursor *m_Cursor;
	};
	/*!
	 * Documentation not written
	 */
	void SetCursor(Cursor &cursor);

	/*!
	 * Documentation not written
	 */
	Cursor GetCursor();

	//@}
}

#endif

