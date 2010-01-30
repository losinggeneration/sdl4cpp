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

#ifndef SDL4CPP_IMAGE_H
#define SDL4CPP_IMAGE_H

#include "SDL.h"
#include <string>

namespace SDL
{
	/*!
	 * Documention not written yet.
	 */
	class Image : public Surface
	{
		public:
			Image();
			~Image();

			/*!
			 * Documention not written yet.
			 */
			static const SDL_version *Linked_Version();

			/*!
			 * old LoadTyped_RW
			 * Documention not written yet.
			 */
			bool Load(SDL_RWops *src, int freesrc, char *type);
			/* Convenience functions */
			/*!
			 * Documention not written yet.
			 */
			bool Load(std::string file);
			/*!
			 * old Load_RW
			 * Documention not written yet.
			 */
			bool Load(SDL_RWops *src, int freesrc);

			/*!
			 * Invert the alpha of a surface for use with OpenGL
			 * This function is now a no-op, and only provided for backwards compatibility.
			 */
			int InvertAlpha(int on);

			/* Functions to detect a file type, given a seekable source */
			/*!
			 * Documention not written yet.
			 */
			bool isBMP(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isPNM(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isXPM(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isXCF(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isPCX(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isGIF(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isJPG(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isTIF(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isPNG(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool isLBM(SDL_RWops *src);

			/* Individual loading functions */
			/*!
			 * Documention not written yet.
			 */
			bool LoadBMP_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadPNM_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadXPM_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadXCF_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadPCX_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadGIF_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadJPG_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadTIF_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadPNG_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadTGA_RW(SDL_RWops *src);
			/*!
			 * Documention not written yet.
			 */
			bool LoadLBM_RW(SDL_RWops *src);

			/*!
			 * Documention not written yet.
			 */
			bool ReadXPMFromArray(char **xpm);
	};
}

#endif
