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

#include "SDL4Cpp_video.h"
#include "SDL4Cpp_mouse.h"

namespace SDL
{

	void WarpMouse(Uint16 x, Uint16 y)
	{
		SDL_WarpMouse(x, y);
	}

	int ShowCursor(int toggle)
	{
		return SDL_ShowCursor(toggle);
	}

	Cursor::Cursor() : m_Cursor(NULL)
	{
	}

	Cursor::Cursor(const Cursor &cursor) : m_Cursor(NULL)
	{
		// XXX TODO no error checking here to make sure area is valid
		memcpy(&m_Cursor->area, &cursor.m_Cursor->area, sizeof(SDL_Rect));

		m_Cursor->hot_x = cursor.m_Cursor->hot_x;
		m_Cursor->hot_y = cursor.m_Cursor->hot_y;

		// XXX TODO should there be some sanity checks here too?
		memcpy(m_Cursor->data, cursor.m_Cursor->data, sizeof(cursor.m_Cursor->data));
		memcpy(m_Cursor->mask, cursor.m_Cursor->mask, sizeof(cursor.m_Cursor->mask));
		memcpy(m_Cursor->save, cursor.m_Cursor->save, sizeof(cursor.m_Cursor->save));

	}

	Cursor::Cursor(const char *image[]) : m_Cursor(NULL)
	{
		Set(image);
	}

	Cursor::~Cursor()
	{
	}

	Cursor &Cursor::operator =(const Cursor &cursor)
	{
		// XXX TODO could probably copy the copy constructor and use = in there
	}

	bool Cursor::Create(Uint8 &data, Uint8 &mask, int w, int h, int hot_x, int hot_y)
	{
		m_Cursor = SDL_CreateCursor(&data, &mask, w, h, hot_x, hot_y);

		if(m_Cursor)
			return true;

		return false;
	}

	void Cursor::Set()
	{
		SetCursor(*this);
	}

	void Cursor::Set(const char *image[])
	{
		// Taken from SDL manual
		int i, row, col;
		Uint8 data[4*32];
		Uint8 mask[4*32];
		int hot_x, hot_y;

		i = -1;

		for(row=0; row<32; ++row)
		{
			for(col=0; col<32; ++col)
			{
				if(col % 8)
				{
					data[i] <<= 1;
					mask[i] <<= 1;
				}
				else
				{
					++i;
					data[i] = mask[i] = 0;
				}

				switch (image[4+row][col])
				{
					case 'X':
						data[i] |= 0x01;
						mask[i] |= 0x01;
						break;
					case '.':
						mask[i] |= 0x01;
						break;
					case ' ':
						break;
				}
			}
		}

		sscanf(image[4+row], "%d,%d", &hot_x, &hot_y);

		m_Cursor = SDL_CreateCursor(data, mask, 32, 32, hot_x, hot_y);
		Set();
	}

	void SetCursor(Cursor &cursor)
	{
		SDL_SetCursor(cursor.m_Cursor);
	}

	Cursor GetCursor()
	{
		Cursor temp;
		temp.m_Cursor = SDL_GetCursor();

		return temp;
	}
}

