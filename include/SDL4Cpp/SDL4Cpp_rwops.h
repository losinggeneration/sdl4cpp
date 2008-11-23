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

#ifndef SDL4CPP_RWOPS_H
#define SDL4CPP_RWOPS_H

#include <string>
#include "SDL_rwops.h"

namespace SDL
{
	/*!
	 * \defgroup Cursor Cursor related functions and class.
	 */
	//@{

	/*!
	 * \brief
	 */
	class RWops
	{
		public:
			RWops();
			RWops(const std::string file, const std::string mode);
			RWops(const RWops &copy);
			~RWops();

			RWops &operator =(const RWops &copy);

			bool FromFile(const std::string file, const std::string mode);

#ifdef HAVE_STDIO_H
			bool FromFP(FILE *fp, int autoclose);
#endif

			bool FromMem(void *mem, int size);
			bool FromConstMem(const void *mem, int size);

			bool Alloc(void);
			void Free();

/* Macros to easily read and write from an RWops structure */
			int seek(int offset, int whence);
			int tell();
			int read(void *ptr, int size, int blocks);
			int write(void *ptr, int size, int blocks);
			bool close();


/* Read an item of the specified endianness and return in native format */
			Uint16 ReadLE16();
			Uint16 ReadBE16();
			Uint32 ReadLE32();
			Uint32 ReadBE32();
			Uint64 ReadLE64();
			Uint64 ReadBE64();

/* Write an item of native format to the specified endianness */
			int WriteLE16(Uint16 value);
			int WriteBE16(Uint16 value);
			int WriteLE32(Uint32 value);
			int WriteBE32(Uint32 value);
			int WriteLE64(Uint64 value);
			int WriteBE64(Uint64 value);

			SDL_RWops *Get();
		private:
			SDL_RWops *m_RWops;
	};

	//@}
}

#endif

