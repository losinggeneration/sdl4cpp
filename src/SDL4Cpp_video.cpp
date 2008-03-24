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
#include "SDL4Cpp_video.h"

namespace SDL
{
	Uint32 MapRGB(PixelFormat &fmt, Uint8 r, Uint8 g, Uint8 b)
	{
		return SDL_MapRGB(&fmt, r, g, b);
	}

	Uint32 MapRGBA(PixelFormat &fmt, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		return SDL_MapRGBA(&fmt, r, g, b, a);
	}

	void GetRGB(Uint32 pixel, PixelFormat &fmt, Uint8 &r, Uint8 &g, Uint8 &b)
	{
		SDL_GetRGB(pixel, &fmt, &r, &g, &b);
	}

	void GetRGBA(Uint32 pixel, PixelFormat &fmt, Uint8 &r, Uint8 &g, Uint8 &b, Uint8 &a)
	{
		SDL_GetRGBA(pixel, &fmt, &r, &g, &b, &a);
	}

	/*!
	 * \brief Private SDL4Cpp_video function used for comparison
	 * Taken from the SDL manual
	 * Needed for comparison, but copy uses blit instead
	 * Return the pixel value at (x, y)
	 * NOTE: The surface must be locked before calling this!
	 */
	Uint32 getpixel(SDL_Surface *surface, int x, int y)
	{
		int bpp = surface->format->BytesPerPixel;
		/* Here p is the address to the pixel we want to retrieve */
		Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
		switch(bpp)
		{
			case 1:
				return *p;
			case 2:
				return *(Uint16 *)p;
			case 3:
				if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
					return p[0] << 16 | p[1] << 8 | p[2];
				else
					return p[0] | p[1] << 8 | p[2] << 16;
			case 4:
				return *(Uint32 *)p;
			default:
				return 0;
		}
	}

	Rect::Rect()
	{
		x = y = h = w = 0;
	}

	Rect::Rect(const Rect &rect)
	{
		(*this) = rect;
	}

	Rect::Rect(int x, int y, int w, int h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	Rect::Rect(const SDL_Rect &rect)
	{
		(*this) = rect;
	}

	Rect::~Rect()
	{
	}

	bool Rect::operator ==(const SDL_Rect &rect)
	{
		 return (x == rect.x) && (y == rect.y) && (w == rect.w) &&
			                         (h == rect.h);
	}

	bool Rect::operator !=(const SDL_Rect &rect)
	{
		if((*this) == rect)
			return false;

		return true;
	}

	Rect &Rect::operator =(const SDL_Rect &rect)
	{
		x = rect.x;
		y = rect.y;
		h = rect.h;
		w = rect.w;

		return *this;
	}

	Rect &Rect::operator +(const SDL_Rect &rect)
	{
		x += rect.x;
		y += rect.y;
		h += rect.h;
		w += rect.w;

		return *this;
	}

	Rect &Rect::operator -(const SDL_Rect &rect)
	{
		x -= rect.x;
		y -= rect.y;
		h -= rect.h;
		w -= rect.w;

		return *this;
	}

	// Compare two Rect's
	bool Rect::operator ==(const Rect &rect)
	{
		return (x == rect.x) && (y == rect.y) && (w == rect.w) &&
			(h == rect.h);
	}

	bool Rect::operator !=(const Rect &rect)
	{
		if((*this) == rect)
			return false;

		return true;
	}

	Rect &Rect::operator =(const Rect &rect)
	{
		x = rect.x;
		y = rect.y;
		h = rect.h;
		w = rect.w;

		return *this;
	}

	Rect &Rect::operator ++()
	{
		x++;
		y++;
		h++;
		w++;

		return *this;
	}

	Rect &Rect::operator --()
	{
		x--;
		y--;
		h--;
		w--;

		return *this;
	}

	Rect &Rect::operator +(const Rect &rect)
	{
		x += rect.x;
		y += rect.y;
		h += rect.h;
		w += rect.w;

		return *this;
	}

	Rect &Rect::operator -(const Rect &rect)
	{
		x -= rect.x;
		y -= rect.y;
		h -= rect.h;
		w -= rect.w;

		return *this;
	}

	/*!
	 * \brief Private SDL4Cpp_video function
	 *
	 * Compare two SDL_PixelFormat's
	 */
	bool operator ==(const PixelFormat &one, const PixelFormat &two)
	{
		if(one.palette == NULL && two.palette == NULL)
			return true;

		if((one.BitsPerPixel == two.BitsPerPixel) &&
			(one.BytesPerPixel == two.BytesPerPixel) &&
			(one.Rmask == two.Rmask) &&
			(one.Gmask == two.Gmask) &&
			(one.Bmask == two.Bmask) &&
			(one.Amask == two.Amask) &&
			(one.Rshift == two.Rshift) &&
			(one.Gshift == two.Gshift) &&
			(one.Bshift == two.Bshift) &&
			(one.Ashift == two.Ashift) &&
			(one.Rloss == two.Rloss) &&
			(one.Gloss == two.Gloss) &&
			(one.Bloss == two.Bloss) &&
			(one.Aloss ==  two.Aloss) &&
			(one.colorkey ==  two.colorkey) &&
			(one.alpha == two.alpha))
		{
			if(one.palette != NULL && two.palette != NULL)
				return	(one.palette->ncolors == two.palette->ncolors) &&
					(one.palette->colors->r == two.palette->colors->r) &&
					(one.palette->colors->g == two.palette->colors->g) &&
					(one.palette->colors->b == two.palette->colors->b) &&
					(one.palette->colors->unused == two.palette->colors->unused);
		}

		return false;
	}

	Surface::Surface()
	{
		m_Surface = NULL;
		m_DeleteSurface = true;
	}

	Surface::Surface(const Surface &copy)
	{
		m_DeleteSurface = true;
		if(copy.m_Surface != NULL)
		{
			// get the surface information from this
			m_Surface = SDL_ConvertSurface(copy.m_Surface, copy.m_Surface->format, copy.m_Surface->flags);
			// then copy the data here
			if(!Blit(copy))
				throw RuntimeError("Error copying surface in constructor: " + GetError());
		}
		else
			throw LogicError("Surface's m_Surface passed to constructor was NULL");
	}

	Surface::Surface(SDL_Surface *surface)
	{
		m_DeleteSurface = true;
		m_Surface = surface;

		if(m_Surface == NULL)
			throw LogicError("SDL_Surface passed to constructor was NULL");
	}

	Surface::Surface(int w, int h, int bpp, Uint32 flags)
	{
		m_DeleteSurface = true;
		m_Surface = NULL;

		Uint32 Rmask, Gmask, Bmask, Amask;

		/* SDL interprets each pixel as a 32-bit number, so our masks must depend
		   on the endianness (byte order) of the machine */
		#if SDL_BYTEORDER == SDL_BIG_ENDIAN
			Rmask = 0xff000000;
			Gmask = 0x00ff0000;
			Bmask = 0x0000ff00;
			Amask = 0x000000ff;
		#else
			Rmask = 0x000000ff;
			Gmask = 0x0000ff00;
			Bmask = 0x00ff0000;
			Amask = 0xff000000;
		#endif

		if(!CreateRGB(flags, w, h, bpp, Rmask, Gmask, Bmask, Amask))
			throw RuntimeError("Error creating surface with CreateRGB: " + GetError());
	}

	Surface::Surface(bool deletesurface)
	{
		m_DeleteSurface = deletesurface;
		m_Surface = NULL;
	}

	Surface::~Surface()
	{
		if(m_DeleteSurface == true)
			Free();
	}

	void Surface::Free()
	{
		if(m_Surface)
		{
			SDL_FreeSurface(m_Surface);
			m_Surface = NULL;
		}
	}

	Surface &Surface::operator =(const Surface &copy)
	{
		// Make sure it's not being assigned to itself
		if(this != &copy)
		{
			// don't try blitting if the surface from copy is NULL
			if(copy.m_Surface)
			{
				// Free the current surface if needed
				if(m_Surface)
					Free();

				// get the surface information from the copy
				m_Surface = SDL_ConvertSurface(copy.m_Surface, copy.m_Surface->format, copy.m_Surface->flags);
				// then copy the data here
				if(!Blit(copy))
					throw RuntimeError("Error copying a surface" + GetError());
			}
		}

		return *this;
	}

	Surface &Surface::operator =(SDL_Surface *surface)
	{
		if(m_Surface)
			Free();

		m_Surface = surface;

		if(m_Surface == NULL)
			throw RuntimeError(GetError());

		return *this;
	}

	bool Surface::operator ==(Surface &compare)
	{
		if((m_Surface == NULL && compare.m_Surface != NULL) ||
				(m_Surface != NULL && compare.m_Surface == NULL))
			return false;

		// if both surfaces are NULL it's true and it skips down to the return
		if(m_Surface != NULL && compare.m_Surface != NULL && this != &compare)
		{
			if(m_Surface->format != NULL && compare.m_Surface->format != NULL)
			{
				if((*m_Surface->format) == (*compare.m_Surface->format))
				{
					if(m_Surface->w == compare.m_Surface->w &&
						m_Surface->h == compare.m_Surface->h &&
						m_Surface->flags == compare.m_Surface->flags &&
						m_Surface->pitch == compare.m_Surface->pitch &&
						static_cast<Rect>(m_Surface->clip_rect) == static_cast<Rect>(compare.m_Surface->clip_rect))
					{
						// Check pixel by pixel
						Lock();
						compare.Lock();
						for(int x = 0; x < m_Surface->w; x++)
						{
							for(int y = 0; y < m_Surface->h; y++)
							{
								if(getpixel(m_Surface, x, y) != getpixel(compare.m_Surface, x, y))
								{
									// if any pixel is false then break from the loops
									Unlock();
									compare.Unlock();
									return false;
								}
							}
						}
						Unlock();
						compare.Unlock();
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;

		return true;
	}

	bool Surface::operator !=(Surface &compare)
	{
		if((*this) == compare)
			return false;

		return true;
	}

	bool Surface::Blit(const Surface &src)
	{
		if(m_Surface == NULL)
			throw LogicError("m_Surface not intialized before call to Blit(const Surface)");

		if(src.m_Surface == NULL)
			throw LogicError("src.m_Surface not initialized before call to Blit(const Surface)");

		if(SDL_BlitSurface(src.m_Surface, NULL, m_Surface, NULL) == 0)
			return true;

		return false;
	}

	bool Surface::Blit(Rect &srcrect, const Surface &src)
	{
		if(m_Surface == NULL)
			throw LogicError("m_Surface not intialized before call to Blit(const Surface, Rect)");

		if(src.m_Surface == NULL)
			throw LogicError("src.m_Surface not initialized before call to Blit(Rect, const Surface, Rect)");

		if(SDL_BlitSurface(src.m_Surface, &srcrect, m_Surface, NULL) == 0)
			return true;

		return false;

	}

	bool Surface::Blit(const Surface &src, Rect &destrect)
	{
		if(m_Surface == NULL)
			throw LogicError("m_Surface not intialized before call to Blit(const Surface, Rect)");

		if(src.m_Surface == NULL)
			throw LogicError("src.m_Surface not initialized before call to Blit(const Surface, Rect)");

		if(SDL_BlitSurface(src.m_Surface, NULL, m_Surface, &destrect) == 0)
			return true;

		return false;
	}

	bool Surface::Blit(Rect &srcrect, const Surface &src, Rect &destrect)
	{
		if(m_Surface == NULL)
			throw LogicError("m_Surface not intialized before call to Blit(const Surface, Rect, Rect)");

		if(src.m_Surface == NULL)
			throw LogicError("src.m_Surface not initialized before call to Blit(const Surface, Rect, Rect)");

		if(SDL_BlitSurface(src.m_Surface, &srcrect, m_Surface, &destrect) == 0)
			return true;

		return false;
	}

	bool Blit(Rect &srcrect, const Surface &src, Rect &destrect, Surface &dest)
	{
		if(src.m_Surface == NULL)
			throw LogicError("m_Surface not intialized before call to Blit(const Surface, Rect, Surface, Rect)");

		if(dest.m_Surface == NULL)
			throw LogicError("dest.m_Surface not initialized before call to Blit(const Surface, Rect, Surface, Rect)");

		if(SDL_BlitSurface(src.m_Surface, &srcrect, dest.m_Surface, &destrect) == 0)
			return true;

		return false;
	}


	bool Surface::Lock()
	{
		if(SDL_MUSTLOCK(m_Surface))
		{
			if(SDL_LockSurface(m_Surface) == 0)
				return true;

			return false;
		}

		// Surface doesn't need to  be locked
		return true;
	}

	void Surface::Unlock()
	{
		if(SDL_MUSTLOCK(m_Surface))
			SDL_UnlockSurface(m_Surface);
	}

	bool Surface::CreateRGB(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
	{
		if(m_Surface)
			Free();

		m_Surface = SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask);

		if(m_Surface == NULL)
			return false;

		return true;
	}

	bool Surface::CreateRGBFrom(Surface &from, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
	{
		if(m_Surface)
			Free();

		m_Surface = SDL_CreateRGBSurfaceFrom(from.m_Surface, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask);

		if(m_Surface == NULL)
			return false;

		return true;
	}

	bool Surface::Convert(Surface &surface)
	{
		m_Surface = SDL_ConvertSurface(surface.Get(), surface.Get()->format, surface.Get()->flags);

		if(m_Surface == NULL)
			return false;

		return true;
	}

	int Surface::SetColors(Color &colors, int firstcolor, int ncolors)
	{
		return SDL_SetColors(m_Surface, &colors, firstcolor, ncolors);
	}

	int Surface::SetPalette(int flags, Color &colors, int firstcolor, int ncolors)
	{
		return SDL_SetPalette(m_Surface, flags, &colors, firstcolor, ncolors);
	}

	bool Surface::SetColorKey(Uint32 flag, Uint32 key)
	{
		if(SDL_SetColorKey(m_Surface, flag, key) == 0)
			return true;

		return false;
	}

	bool Surface::SetAlpha(Uint32 flag, Uint8 alpha)
	{
		if(SDL_SetAlpha(m_Surface, flag, alpha) == 0)
			return true;

		return false;
	}

	void Surface::SetClipRect(Rect *rect)
	{
		SDL_SetClipRect(m_Surface, rect);
	}

	Rect Surface::GetClipRect()
	{
		Rect rect;
		SDL_GetClipRect(m_Surface, &rect);

		return rect;
	}

	bool Surface::FillRect(Rect &dstrect, Uint32 color)
	{
		if(SDL_FillRect(m_Surface, &dstrect, color) == 0)
			return true;

		return false;
	}

	bool Surface::LoadBMP(std::string file)
	{
		if(m_Surface)
			Free();

		m_Surface = SDL_LoadBMP(file.c_str());

		if(!m_Surface)
			return false;

		return true;
	}

	bool Surface::SaveBMP(std::string file)
	{
		if(SDL_SaveBMP(m_Surface, file.c_str()) == 0)
			return true;

		return false;
	}

	SDL_Surface *Surface::Get()
	{
		return m_Surface;
	}

	Uint32 Surface::GetFlags()
	{
		return m_Surface->flags;
	}

	Rect Surface::GetRect()
	{
		SDL_Rect rect = { 0, 0, m_Surface->w, m_Surface->h };
		return rect;
	}

	PixelFormat *Surface::GetPixelFormat()
	{
		return m_Surface->format;
	}

	Uint16 Surface::GetPitch()
	{
		return m_Surface->pitch;
	}

	namespace GL
	{
		bool LoadLibrary(const std::string path)
		{
			Screen screen;
			if(!GetVideoSurface(screen))
				throw LogicError("You must not setup a Screen before calling GL::LibraryLoad");

			if(screen.m_Surface)
				throw LogicError("You must not setup a Screen before calling GL::LibraryLoad");

			if(SDL_GL_LoadLibrary(path.c_str()) < 0)
				return false;

			return true;
		}

		void *GetProcAddress(const std::string proc)
		{
			Screen screen;
			if(!GetVideoSurface(screen))
				throw LogicError("You must setup a Screen before calling GL::GetProcAddress");

			if(!screen.m_Surface)
				throw LogicError("You must setup a Screen before calling GL::GetGetProcAddress");

			return SDL_GL_GetProcAddress(proc.c_str());
		}

		bool GetAttribute(Attr attr, int &value)
		{
			Screen screen;
			if(!GetVideoSurface(screen))
				throw LogicError("You must setup a Screen before calling GL::GetAttribute");

			if(!screen.m_Surface)
				throw LogicError("You must setup a Screen before calling GL::GetAttribute");

			if(SDL_GL_GetAttribute(attr, &value) < 0)
				return false;

			return true;
		}

		bool SetAttribute(Attr attr, int value)
		{
			Screen screen;
			if(GetVideoSurface(screen))
				throw LogicError("You must not setup a Screen before calling GL::SetAttribute");

			if(screen.m_Surface)
				throw LogicError("You must not setup a Screen before calling GL::SetAttribute");

			if(SDL_GL_SetAttribute(attr, value) < 0)
				return false;

			return true;
		}

		void SwapBuffers(void)
		{
			SDL_GL_SwapBuffers();
		}
	}

	Screen::Screen() : Surface(false)
	{
	}

	Screen::Screen(int w, int h, int bpp, Uint32 flags) : Surface(false)
	{
		SetVideoMode(w, h, bpp, flags);
	}

	Screen::Screen(Surface &icon, Uint8 *mask) : Surface(false)
	{
		SetIcon(icon, mask);
	}

	Screen::~Screen()
	{
	}

	bool GetVideoSurface(Screen &vid)
	{
		// get the video surface here
		SDL_Surface *screen = SDL_GetVideoSurface();

		// now give the vid screen
		// this works fine and safely because Screens don't try deleting the surface on deconstruction
		vid.m_Surface = screen;

		// Now we check if the surface is NULL or not to tell the coder if the surface is initialized or not
		if(vid.m_Surface == NULL)
			return false;

		return true;
	}

	bool Screen::Flip()
	{
		if(SDL_Flip(m_Surface) == 0)
			return true;

		return false;
	}

	void Screen::UpdateRect(Rect &rect)
	{
		SDL_UpdateRect(m_Surface, rect.x, rect.y, rect.w, rect.h);
	}

	void Screen::UpdateRect(Sint32 x, Sint32 y, Sint32 w, Sint32 h)
	{
		SDL_UpdateRect(m_Surface, x, y, w, h);
	}

	// Uses a pionter because rects will be an array
	void Screen::UpdateRects(int numrects, Rect *rects)
	{
		SDL_UpdateRects(m_Surface, numrects, rects);
	}


	bool Screen::SetGamma(float redgamma, float greengamma, float bluegamma)
	{
		if(SDL_SetGamma(redgamma, greengamma, bluegamma) == -1)
			return false;

		return true;
	}

	bool Screen::GetGammaRamp(Uint16 &redtable, Uint16 &greentable, Uint16 &bluetable)
	{
		if(SDL_GetGammaRamp(&redtable, &greentable, &bluetable) == -1)
			return false;

		return true;
	}

	bool Screen::SetGammaRamp(Uint16 &redtable, Uint16 &greentable, Uint16 &bluetable)
	{
		if(SDL_SetGammaRamp(&redtable, &greentable, &bluetable) == -1)
			return false;

		return true;
	}

	int Screen::VideoModeOK(int width, int height, int bpp, Uint32 flags)
	{
		return SDL_VideoModeOK(width, height, bpp, flags);
	}

	std::string Screen::VideoDriverName()
	{
		char namebuf[1000];

		char *name = SDL_VideoDriverName(namebuf, 1000);
		if(name == NULL)
			return "";

		return static_cast<std::string>(name);
	}

	VideoInfo Screen::GetVideoInfo(void)
	{
		const VideoInfo *Vid = SDL_GetVideoInfo();

		return *Vid;
	}

	bool Screen::SetVideoMode(int width, int height, int bpp, Uint32 flags)
	{
		m_Surface = SDL_SetVideoMode(width, height, bpp, flags);

		if(m_Surface == NULL)
			return false;
		return true;
	}

	void Screen::SetIcon(Surface &icon, Uint8 *mask)
	{
		// Make sure icon has something in it
		if(icon.Get() == NULL)
			throw LogicError("icon not intialized before call to SetIcon()");
		// and if the video surface in non-null
		// this function isn't going to work
		if(m_Surface != NULL)
			throw LogicError("Screen.m_Surface already initialized, so this call to SetIcon() would have no purpose");

		SDL_WM_SetIcon(icon.Get(), mask);
	}

	void Screen::SetIcon(std::string iconname, Uint8 *mask)
	{
		Surface icon;
		icon.LoadBMP(iconname);
		SetIcon(icon, mask);
	}

	bool Screen::ToggleFullScreen()
	{
		if(m_Surface == NULL)
			throw LogicError("m_Surface not intialized before call to ToggleFullScreen()");
		// done only to make sure the correct
		// value is returned
		int x = SDL_WM_ToggleFullScreen(m_Surface);

		if(x == 0)
			return false;

		return true;
	}
	Overlay::Overlay()
	{
		m_Overlay = NULL;
	}

	Overlay::Overlay(const Overlay &copy)
	{
	}

	Overlay::Overlay(SDL_Overlay *overlay)
	{
		m_Overlay = overlay;
	}

	Overlay::~Overlay()
	{
		Free();
	}

	void Overlay::Create(int width, int height, Uint32 format, SDL_Surface *display)
	{
		if(m_Overlay)
			Free();

		m_Overlay = SDL_CreateYUVOverlay(width, height, format, display);
	}

	bool Overlay::Lock()
	{
		if(SDL_LockYUVOverlay(m_Overlay) == 0)
			return true;

		return false;
	}

	void Overlay::Unlock()
	{
		SDL_UnlockYUVOverlay(m_Overlay);
	}

	bool Overlay::Display(Rect &destrect)
	{
		if(SDL_DisplayYUVOverlay(m_Overlay, &destrect) == 0)
			return true;

		return false;
	}

	void Overlay::Free()
	{
		if(m_Overlay)
		{
			SDL_FreeYUVOverlay(m_Overlay);
			m_Overlay = NULL;
		}
	}
}

