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

#ifndef SDL4CPP_VIDEO_H
#define SDL4CPP_VIDEO_H

#include <string>
#include "SDL.h"


namespace SDL
{
	/*!
	 * \defgroup Video Video
	 */
	//@{

	/*!
	 * \brief An enhanced version of SDL_Rect.
	 *
	 * A Rect defines a rectangular area of pixels. It is used by SDL::Surface::Blit() to define blitting regions and by several other video functions.
	 *
	 * \b Structure Definition
	 * \code
	 * typedef struct
	 * {
	 * 	Sint16 x, y;
	 * 	Uint16 w, h;
	 * } SDL_Rect;
	 * \endcode
	 * 
	 * \b Structure Data
	 * \htmlonly
	 * <pre>
	 * x, y	Position of the upper-left corner of the rectangle
	 * w, h	The width and height of the rectangle
	 * </pre>
	 * \endhtmlonly
	 */
	class Rect : public SDL_Rect
	{
		public:
			/*!
			 * \brief Default constructor.
			 *
			 * Initializes x, y, h, and w to 0
			 */
			Rect();

			/*!
			 * \brief Copy constructor.
			 *
			 * Initializes x, y, h, and w to be the same as rect's
			 */
			Rect(const Rect &rect);

			/*!
			 * \brief SDL_Rect copy constructor.
			 *
			 * Initializes x, y, h, and w to be the same as rect's
			 */
			Rect(const SDL_Rect &rect);

			/*!
			 * \brief Initialize a Rect
			 *
			 * Initializes the Rect to have width w, height h, x = x, and y = y
			 */
			Rect(int x, int y, int w, int h);

			/*!
			 * \brief Destructor.
			 *
			 * Does nothing.
			 */
			~Rect();
			
			/*!
			 * \brief Comparison between a Rect and SDL_Rect.
			 * 
			 * \return True if they have the same values.
			 */
			bool operator ==(const SDL_Rect &rect);

			/*!
			 * \brief Comparison between a Rect and SDL_Rect.
			 *
			 * \return True if they don't have the same values.
			 */
			bool operator !=(const SDL_Rect &rect);

			/*!
			 * \brief Sets a Rect equal to an SDL_Rect.
			 *
			 * \return The Rect that is equal to rect
			 */
			Rect &operator =(const SDL_Rect &rect);

			/*!
			 * \brief Adds a Rect and an SDL_Rect.
			 *
			 * \return The Rect that is the addition of all values of the Rect and the SDL_Rect.
			 */
			Rect &operator +(const SDL_Rect &rect);

			/*!
			 * \brief Subtracts an SDL_Rect and Rect.
			 *
			 * \return The Rect that is the subtraction of all values of SDL_Rect from Rect.
			 */
			Rect &operator -(const SDL_Rect &rect);

			/*!
			 * \brief Comparison between twe Rects.
			 *
			 * \return True if they have the same values.
			 */
			bool operator ==(const Rect &rect);

			/*!
			 * \brief Comparison between twe Rects.
			 *
			 * \return True if they don't have the same values.
			 */
			bool operator !=(const Rect &rect);

			/*!
			 * \brief Sets one Rect equal to another.
			 *
			 * \return The Rect that is equal to rect.
			 */
			Rect &operator =(const Rect &rect);

			/*!
			 * \brief Adds one to all values in Rect.
			 * 
			 * \return The Rect that is the addition of all values of the Rect by one.
			 */
			Rect &operator ++();

			/*!
			 * \brief Subtracts one from all values in Rect.
			 *
			 * \return The Rect that is the subtraction of all values of the Rect by one.
			 */
			Rect &operator --();

			/*!
			 * \brief Adds the values of two Rects together.
			 *
			 * \return The Rect that is the addition of all values of the Rect and rect.
			 */
			Rect &operator +(const Rect &rect);

			/*!
			 * \brief Subtracts a rect from Rect.
			 *
			 * \return The Rect that is the subtraction of all values of rect from Rect.
			 */
			Rect &operator -(const Rect &rect);
	};

	/*!
	 * \brief A shorter named version of SDL_VideoInfo
	 *
	 * Video Target information
	 *
	 * This (read-only) structure is returned by Screen::GetVideoInfo(). It contains information on either the 'best' available mode (if called before Screen::SetVideoMode()) or the current video mode.
	 *
	 * \b Structure Definition
	 * \code
	 * typedef struct
	 * {
	 *	 Uint32 hw_available:1;
	 *	 Uint32 wm_available:1;
	 *	 Uint32 blit_hw:1;
	 *	 Uint32 blit_hw_CC:1;
	 *	 Uint32 blit_hw_A:1;
	 *	 Uint32 blit_sw:1;
	 *	 Uint32 blit_sw_CC:1;
	 *	 Uint32 blit_sw_A:1;
	 *	 Uint32 blit_fill;
	 *	 Uint32 video_mem;
	 *	 SDL_PixelFormat *vfmt;
	 * }
	 * \endcode
	 * 
	 * \b Structure Data
	 * \htmlonly
	 * <pre>
	 * hw_available	Is it possible to create hardware surfaces?
	 * wm_available	Is there a window manager available
	 * blit_hw	Are hardware to hardware blits accelerated?
	 * blit_hw_CC	Are hardware to hardware colorkey blits accelerated?
	 * blit_hw_A	Are hardware to hardware alpha blits accelerated?
	 * blit_sw	Are software to hardware blits accelerated?
	 * blit_sw_CC	Are software to hardware colorkey blits accelerated?
	 * blit_sw_A	Are software to hardware alpha blits accelerated?
	 * blit_fill	Are color fills accelerated?
	 * video_mem	Total amount of video memory in Kilobytes
	 * vfmt		PixelFormat of the video device
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_VideoInfo VideoInfo;

	/*!
	 * \brief A shorter named version of SDL_PixelFormat
	 *
	 * Stores surface format information
	 * 
	 * A PixelFormat describes the format of the pixel data stored at the pixels field of a Surface. Every surface stores a PixelFormat in the format field.
	 *
	 * If you wish to do pixel level modifications on a surface, then understanding how SDL stores its color information is essential.
	 *
	 * 8-bit pixel formats are the easiest to understand. Since its an 8-bit format, we have 8 BitsPerPixel and 1 BytesPerPixel. Since BytesPerPixel is 1, all pixels are represented by a Uint8 which contains an index into palette->colors. 
	 * So, to determine the color of a pixel in a 8-bit surface: we read the color index from surface->pixels and we use that index to read the Color structure from surface->format->palette->colors. Like so:
	 * \code
	 * SDL_Surface *surface;
	 * SDL_PixelFormat *fmt;
	 * SDL_Color *color;
	 * Uint8 index;
	 *
	 * .
	 * .
	 *
	 * // Create surface
	 * .
	 * .
	 * fmt=surface->format;
	 * // Check the bitdepth of the surface
	 * if(fmt->BitsPerPixel!=8){
	 * 		  fprintf(stderr, "Not an 8-bit surface.\n");
	 * 		   return(-1);
	 *	}
	 *
	 * // Lock the surface
	 * SDL_LockSurface(surface);
	 * // Get the topleft pixel
	 * index=*(Uint8 *)surface->pixels;
	 * color=fmt->palette->colors[index];
	 * // Unlock the surface
	 * SDL_UnlockSurface(surface);
	 * printf("Pixel Color- *Red: %d, Green: %d, Blue: %d. Index: %d\n",
	 * 			          color->r, color->g, color->b, index);
	 * .
	 * .
	 * \endcode
	 *
	 * Pixel formats above 8-bit are an entirely different experience. 
	 * They are considered to be "TrueColor" formats and the color information is stored in the pixels themselves, not in a palette. 
	 * The mask, shift and loss fields tell us how the color information is encoded.
	 * The mask fields allow us to isolate each color component, the shift fields tell us the number of bits to the right of each component in the pixel value and the loss fields tell us the number of bits lost from each component when packing 8-bit color component in a pixel.
	 * 
	 * \code
	 * // Extracting color components from a 32-bit color value
	 * SDL_PixelFormat *fmt;
	 * SDL_Surface *surface;
	 * Uint32 temp, pixel;
	 * Uint8 red, green, blue, alpha;
	 * .
	 * .
	 * .
	 * fmt=surface->format;
	 * SDL_LockSurface(surface);
	 * pixel=*((Uint32*)surface->pixels);
	 * SDL_UnlockSurface(surface);
	 * // Get Red component
	 * temp=pixel&fmt->Rmask; // Isolate red component
	 * temp=temp>>fmt->Rshift; // Shift it down to 8-bit
	 * temp=temp<<fmt->Rloss; // Expand to a full 8-bit number
	 * red=(Uint8)temp;
	 * // Get Green component
	 * temp=pixel&fmt->Gmask; // Isolate green component
	 * temp=temp>>fmt->Gshift; // Shift it down to 8-bit
	 * temp=temp<<fmt->Gloss; // Expand to a full 8-bit number
	 * green=(Uint8)temp;
	 * 
	 * // Get Blue component
	 * temp=pixel&fmt->Bmask; // Isolate blue component
	 * temp=temp>>fmt->Bshift;// Shift it down to 8-bit
	 * temp=temp<<fmt->Bloss; // Expand to a full 8-bit number
	 * blue=(Uint8)temp;
	 *
	 * // Get Alpha component
	 * temp=pixel&fmt->Amask; // Isolate alpha component
	 * temp=temp>>fmt->Ashift;// Shift it down to 8-bit
	 * temp=temp<<fmt->Aloss; // Expand to a full 8-bit number
	 * alpha=(Uint8)temp;
	 * 
	 * printf("Pixel Color - *R: %d,  G: %d,  B: %d,  A: %d\n", red, green, blue, alpha);
	 * .
	 * .
	 * .
	 * \endcode
	 *
	 * \b Structure Definition
	 * \code
	 * typedef struct
	 * {
	 * 	SDL_Palette *palette;
	 * 	Uint8  BitsPerPixel;
	 * 	Uint8  BytesPerPixel;
	 * 	Uint32 Rmask, Gmask, Bmask, Amask;
	 * 	Uint8  Rshift, Gshift, Bshift, Ashift;
	 * 	Uint8  Rloss, Gloss, Bloss, Aloss;
	 * 	Uint32 colorkey;
	 * 	Uint8  alpha;
	 * }
	 * \endcode
	 * 
	 * \b Structure Data
	 * \htmlonly
	 * <pre>
	 * palette	Pointer to the palette, or NULL if the BitsPerPixel>8
	 * BitsPerPixel	The number of bits used to represent each pixel in a surface. Usually 8, 16, 24 or 32.
	 * BytesPerPixel	The number of bytes used to represent each pixel in a surface. Usually one to four.
	 * [RGBA]mask	Binary mask used to retrieve individual color values
	 * [RGBA]loss	Precision loss of each color component (2[RGBA]loss)
	 * [RGBA]shift	Binary left shift of each color component in the pixel value
	 * colorkey	Pixel value of transparent pixels
	 * alpha		Overall surface alpha value
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_PixelFormat PixelFormat;

	/*!
	 * \brief A shorter named version of SDL_Palette
	 *
	 * Color palette for 8-bit pixel formats
	 *
	 * Each pixel in an 8-bit surface is an index into the colors field of the Palette structure store in PixelFormat. 
	 * A Palette should never need to be created manually. It is automatically created when SDL allocates a PixelFormat for a Surface.
	 * The colors values of a Surfaces palette can be set with the Surface::SetColors().
	 *
	 * \b Structure Definition
	 * \code
	 * typedef struct
	 * {
	 * 	int ncolors;
	 * 	SDL_Color *colors;
	 * }
	 * \endcode
	 * 
	 * \b Structure Data
	 * \htmlonly
	 * <pre>
	 * ncolors	Number of colors used in this palette
	 * colors		Pointer to SDL_Color structures that make up the palette.
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_Palette Palette;

	/*!
	 * \brief A shorter named version of SDL_Color
	 *
	 * Format independent color description
	 *
	 * Color describes a color in a format independent way. You can convert a Color to a pixel value for a certain pixel format using MapRGB().
	 * 
	 * \b Structure Definition
	 * \code
	 * typedef struct
	 * {
	 * 	Uint8 r;
	 * 	Uint8 g;
	 * 	Uint8 b;
	 * 	Uint8 unused;
	 * }
	 * \endcode
	 * 
	 * \b Structure Data
	 * \htmlonly
	 * <pre>
	 * r	Red intensity
	 * g	Green intensity
	 * b	Blue intensity
	 * unused	Unused
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_Color Color;

	/*!
	 * Documention not written yet.
	 */
	Uint32 MapRGB(PixelFormat &fmt, Uint8 r, Uint8 g, Uint8 b);

	/*!
	 * Documention not written yet.
	 */
	Uint32 MapRGBA(PixelFormat &fmt, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/*!
	 * Documention not written yet.
	 */
	void GetRGB(Uint32 pixel, PixelFormat &fmt, Uint8 &r, Uint8 &g, Uint8 &b);

	/*!
	 * Documention not written yet.
	 */
	void GetRGBA(Uint32 pixel, PixelFormat &fmt, Uint8 &r, Uint8 &g, Uint8 &b, Uint8 &a);
	
	/*!
	 * \brief Graphical Surface Structure.
	 * 
	 * This is the Surface class that is the equivilant to SDL_Surface, with the functions that deal directly with an SDL_Surface. 
	 * So, the functions (for the most part) work on this surface.
	 *
	 * There are also some small enhancements like being able to compare two surfaces, or assign the values of one surface to another.
	 */
	class Surface
	{
		public:
			/*!
			 * \brief Default constructor.
			 * 
			 * Creates an empty Surface, with m_Surface set to NULL.
			 *
			 * \note Since m_Surface is NULL, you have to make sure to assign something to it before calling anything else that works on it. Otherwise it will throw an std::logic_error
			 */
			Surface();

			/*!
			 * \brief Copy constructor.
			 *
			 * Copies the data of one surface to another. 
			 *
			 * \note This doesn't just copy the pointer location like the C SDL libary would do. Every "public" variable in SDL_Surface is copied.
			 * \note If copy.m_Surface is NULL, *this.m_Surface will be NULL.
			 *
			 * \throws std::runtime_error if blitting to this surface from the copy fails.
			 * \throws std::logic_error if the surface's m_Surface is NULL
			 */
			Surface(const Surface &copy);

			/*!
			 * \brief Create a Surface from an SDL_Surface
			 *
			 * \pre surface is non-NULL
			 *
			 * Use this for say a libary like SDL_Image that's unwrapped. 
			 *
			 * \code
			 * SDL::Surface image(IMG_Load("image.png"));
			 * \endcode
			 *
			 * checking for errors
			 * \code
			 * try
			 * {
			 * 	SDL::Surface image(IMG_Load("image.png"));
			 *	// Do something with the surface.
			 * }
			 * catch(std::runtime_error e)
			 * {
			 * 	cout << "Error loading image.png" << endl;
			 * 	cout  << SDL::GetError() << endl;
			 * }
			 * \endcode 
			 *
			 * This method to me, is somewhat annoying because more code has to be in the try block to use the function. 
			 * \sa Surface::operator= (SDL_Surface *) for a different way to get SDL_Surfaces
			 * \note The pointer to surface is what m_Surface gets, not the value. Use this with care.
			 *
			 * \throws std::logic_error if m_Surface is NULL after assigning surface to it. 
			 */
			Surface(SDL_Surface *surface);

			/*!
			 * \brief Create a Surface with these arguments
			 *
			 * Creates a surface of width w, height h, bits per pixel bpp, and flags
			 *
			 * for flags \see CreateRGB()
			 * \throws std::runtime_error if m_Surface is NULL after assigning screen to it. 
			 */
			Surface(int w, int h, int bpp, Uint32 flags = SDL_SWSURFACE);

			/*!
			 * \brief Special constructor for Screen
			 *
			 * This constructor is used to tell Surface if it should delete the SDL_Surface or not. 
			 *
			 * Only Screen should used this function, and is only documented for completeness.
			 *
			 * \note Do not use.
			 */
			Surface(bool deletesurface);

			/*!
			 * \brief Destructor
			 *
			 * This makes a call to Free() to free m_Surface.
			 */
			virtual ~Surface();

			/*!
			 * \brief Copies one surface to another
			 *
			 * Copies the data of one surface to another. 
			 *
			 * \note This doesn't just copy the pointer location like the C SDL libary would do. Every "public" variable in SDL_Surface is copied.
			 * \note If copy.m_Surface is NULL, *this.m_Surface will be NULL.
			 *
			 * \throws std::runtime_error if blitting to this surface from the copy fails.
			 */
			Surface &operator =(const Surface &copy);

			/*!
			 * \brief Changes the surface pointer to this one.
			 *
			 * This is needed for such things as SDL_image for instance.
			 * 
			 * \code
			 * SDL::Surface image;
			 * image = IMG_Load("image.png");
			 * \endcode
			 *
			 * How to correctly handle errors
			 * \code
			 * SDL::Surface image:
			 * try
			 * {
			 * 	image = IMG_Load("image.png");
			 * }
			 * catch(std::runtime_error e)
			 * {
			 * 	cout << "Error loading image.png" << endl;
			 * 	cout << SDL::GetError();
			 * }
			 * \endcode
			 * This is because almost every SDL function (all I can think of) return NULL if there's a problem 
			 * creating a SDL_Surface. So image = static_cast<SDL_Surface *>(NULL); would throw an error.
			 * 
			 * This is still legal, but not reccomended because in the future Get() might be removed. Maybe not though.
			 * \code
			 * image = IMG_Load("image.png");
			 * 
			 * if(image.Get() == NULL)
			 * 	cout << "Error"  << endl;
			 * \endcode
			 *
			 * \note This frees m_Surface and gets the new pointer address from surface.
			 * \throws std::runtime_error if the surface passed is NULL
			 */
			Surface &operator =(SDL_Surface *surface);

			/*!
			 * \brief Compares two Surfaces.
			 *
			 * Compare all "public" members of m_Surface including the values of pixel data.
			 *
			 * \return True if they have the same values in them, False otherwise.
			 */
			bool operator ==(Surface &compare);

			/*!
			 * \brief Compares two Surfaces.
			 *
			 * Compare all "public" members of m_Surface including the values of pixel data.
			 *
			 * \return True if they have at least one value that isn't the same, otherwise they're the same and False is returned. 
			 */
			bool operator !=(Surface &compare);

			/*!
			 * \brief Blit one Surface to another.
			 *
			 * Blit an entire Surface to upper left corner of this one.
			 *
			 * \return True if the blit was sucessfull. otherwise false.
			 *
			 * \throws std::logic_error if either Surface::m_Surface is NULL.
			 */
			bool Blit(const Surface &src);

			/*!
			 * \brief Blit one Surface to another.
			 *
			 * Blit just this region to upper left corner of this one.
			 *
			 * The aruments are reversed here beause I think this will be less used than the function to blit to a destrect.
			 *
			 * \return True if the blit was sucessfull. otherwise false.
			 *
			 * \throws std::logic_error if either Surface::m_Surface is NULL.
			 */
			bool Blit(Rect &srcrect, const Surface &src);

			/*!
			 * \brief Blit one Surface to another.
			 * 
			 * Blit the entire Surface (src) to this region of this surface.
			 *
			 * \return True if the blit was sucessfull. otherwise false.
			 *
			 * \throws std::logic_error if either Surface::m_Surface is NULL.
			 */
			bool Blit(const Surface &src, Rect &destrect);

			/*!
			 * \brief Blit one Surface to another.
			 *
			 * Blit this region to a specfic region on this one
			 *
			 * \return True if the blit was sucessfull. otherwise false.
			 *
			 * \throws std::logic_error if either Surface::m_Surface is NULL.
			 */
			bool Blit(Rect &srcrect, const Surface &src, Rect &destrect);

			/*!
			 * \brief Blit one Surface to another.
			 *
			 * Blit this surface and region to any other surface and region
			 *
			 * This is the strangest one to me because I don't know why the other Blits wouldn't be called instead.
			 *
			 * So this shouldn't be needed but kept just in case someone wants it.
			 *
			 * \return True if the blit was sucessfull. otherwise false.
			 *
			 * \throws std::logic_error if either Surface::m_Surface is NULL.
			 */
			friend bool Blit(Rect &srcrect, const Surface &src, Rect &destrect, Surface &dest);

			/*!
			 * Documention not written yet.
			 */
			bool CreateRGB(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);

			/*!
			 * Documention not written yet.
			 */
			bool CreateRGBFrom(Surface &from, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
			/*!
			 * Documention not written yet.
			 */
			bool Convert(Surface &surface);

			/*!
			 * Documention not written yet.
			 */
			bool Lock();

			/*!
			 * Documention not written yet.
			 */
			void Unlock();

			/*!
			 * Documention not written yet.
			 */
			int SetColors(Color &colors, int firstcolor, int ncolors);

			/*!
			 * Documention not written yet.
			 */
			int SetPalette(int flags, Color &colors, int firstcolor, int ncolors);

			/*!
			 * Documention not written yet.
			 */
			bool SetColorKey(Uint32 flag, Uint32 key);

			/*!
			 * Documention not written yet.
			 */
			bool SetAlpha(Uint32 flag, Uint8 alpha);

			/*!
			 * Documention not written yet.
			 */
			void SetClipRect(Rect *rect);

			/*!
			 * Documention not written yet.
			 */
			Rect GetClipRect();
			
			/*!
			 * Documention not written yet.
			 */
			bool FillRect(Rect &dstrect, Uint32 color);
			
			/*!
			 * Documention not written yet.
			 */
			bool LoadBMP(std::string file);

			/*!
			 * Documention not written yet.
			 */
			bool SaveBMP(std::string file);

			/*!
			 * \brief Get the pointer to m_Surface.
			 *
			 * This shouldn't normally be used, but is here to accomodate things I may have forgotten, overlooked, etc. \b Use \b with \b care.
			 */
			SDL_Surface *Get();

			/*!
			 * Documention not written yet.
			 */
			Uint32 GetFlags();

			/*!
			 * Documention not written yet.
			 */
			Rect GetRect();

			/*!
			 * Documention not written yet.
			 */
			PixelFormat *GetPixelFormat();

			/*!
			 * Documention not written yet.
			 */
			Uint16 GetPitch();

			/*!
			 * Frees (deletes) m_Surface
			 *
			 * Frees the resources used by a previously created from m_Surface. If the surface was created using CreateRGBSurfaceFrom() then the pixel data is not freed.
			 *
			 * \note There isn't any functions to check for CreateRGBSurfaceFrom(), so for now you should take care of that.
			 */
			void Free();
		protected:
			/*!
			 * \brief The SDL_Surface for the Surface class.
			 *
			 * SDL_Su5rface's represent areas of "graphical" memory, memory that can be drawn to. The video framebuffer stored in Screen from Screen::SetVideoMode() and this SDL_Surface can be accessed via Screen::GetVideoSurface(). Most of the fields should be pretty obvious. w and h are the width and height of the surface in pixels. pixels is a pointer to the actual pixel data, the surface should be locked before accessing this field. The clip_rect field is the clipping rectangle as set by SetClipRect().
			 *
			 * The following are supported in the flags field.
			 * \htmlonly
			 * <pre>
			 * SDL_SWSURFACE		Surface is stored in system memory
			 * SDL_HWSURFACE		Surface is stored in video memory
			 * SDL_ASYNCBLIT		Surface uses asynchronous blits if possible
			 * SDL_ANYFORMAT		Allows any pixel-format (Display surface)
			 * SDL_HWPALETTE		Surface has exclusive palette
			 * SDL_DOUBLEBUF		Surface is double buffered (Display surface)
			 * SDL_FULLSCREEN		Surface is full screen (Display Surface)
			 * SDL_OPENGL		Surface has an OpenGL context (Display Surface)
			 * SDL_OPENGLBLIT		Surface supports OpenGL blitting (Display Surface)
			 * SDL_RESIZABLE		Surface is resizable (Display Surface)
			 * SDL_HWACCEL		Surface blit uses hardware acceleration
			 * SDL_SRCCOLORKEY	Surface use colorkey blitting
			 * SDL_RLEACCEL		Colorkey blitting is accelerated with RLE
			 * SDL_SRCALPHA		Surface blit uses alpha blending
			 * SDL_PREALLOC		Surface uses preallocated memory
			 * </pre>
			 * \endhtmlonly
			 *
			 * \b Structure \b Definition
			 * \code
			 * typedef struct SDL_Surface
			 * {
			 *	Uint32 flags;			// Read-only
			 *	SDL_PixelFormat *format;	// Read-only
			 *	int w, h;			// Read-only
			 *	Uint16 pitch;			// Read-only
			 *	void *pixels;			// Read-write
			 *
			 *	// clipping information
			 *	SDL_Rect clip_rect;		// Read-only
			 *
			 *	// Reference count -- used when freeing surface
			 *	int refcount;			// Read-mostly
			 *
			 *	// This structure also contains private fields not shown here
			 * } SDL_Surface;
			 * \endcode
			 * \b Structure \b Data
			 * \htmlonly
			 * <pre>
			 * flags		Surface flags
			 * format		Pixel format
			 * w, h		Width and height of the surface
			 * pitch		Length of a surface scanline in bytes
			 * pixels		Pointer to the actual pixel data
			 * clip_rect	surface clip rectangle
			 * </pre>
			 * \endhtmlonly
			 */
			SDL_Surface *m_Surface;

			/*!
			 * Documention not written yet.
			 */
			bool m_DeleteSurface;
	};

	/*!
	 * \brief The namespace all functions for SDL GL are put in.
	 */
	namespace GL
	{
		/*!
		 * \brief SDL GL Attributes
		 *
		 * While you can set most OpenGL attributes normally, the attributes listed above must be known before SDL sets the video mode. These attributes are set and read with SetAttribute() and GetAttribute().
		 *
		 * \htmlonly
		 * <pre>
		 * SDL_GL_RED_SIZE 	Size of the framebuffer red component, in bits.
		 * SDL_GL_GREEN_SIZE 	Size of the framebuffer green component, in bits.
		 * SDL_GL_BLUE_SIZE 	Size of the framebuffer blue component, in bits.
		 * SDL_GL_ALPHA_SIZE 	Size of the framebuffer alpha component, in bits.
		 * SDL_GL_BUFFER_SIZE 	Size of the framebuffer, in bits.
		 * SDL_GL_DOUBLEBUFFER 	Enable or disable double buffering (0 or 1).
		 * SDL_GL_DEPTH_SIZE 	Size of the depth buffer, in bits.
		 * SDL_GL_STENCIL_SIZE 	Size of the stencil buffer, in bits.
		 * SDL_GL_ACCUM_RED_SIZE 	Size of the accumulation buffer red component, in bits.
		 * SDL_GL_ACCUM_GREEN_SIZE 	Size of the accumulation buffer green component, in bits.
		 * SDL_GL_ACCUM_BLUE_SIZE 	Size of the accumulation buffer blue component, in bits.
		 * SDL_GL_ACCUM_ALPHA_SIZE 	Size of the accumulation buffer alpha component, in bits.
		 * SDL_GL_STEREO 	Enable or disable stereo (left and right) buffers (0 or 1).
		 * SDL_GL_MULTISAMPLEBUFFERS 	Number of multisample buffers (0 or 1). *
		 * SDL_GL_MULTISAMPLESAMPLES 	Number of samples per pixel when multisampling is enabled. *
		 * SDL_GL_SWAP_CONTROL 	Vsync: Swap buffers every n'th retrace (0 to disable, which is the default). **
		 *
		 * * Requires the GL_ARB_multisample extension.
		 * ** Available since SDL 1.2.10
		 * </pre>
		 * \endhtmlonly
		 * \sa SetAttribute
		 * \sa GetAttribute 
		 */
		typedef SDL_GLattr Attr;

		/*!
		 * \brief Specify an OpenGL library
		 *
		 * If you wish, you may load the OpenGL library at runtime, this must be done before Screen::SetVideoMode() is called. The path of the GL library is passed to LoadLibrary(). You must then use GetProcAddress() to retrieve function pointers to GL functions.
		 *
		 * \return true an sucess and false on an error.
		 * \throws std::logic_error if the Screen has been initialized before calling.
		 */
		bool LoadLibrary(const std::string path);

		/*!
		 * \brief Get the address of a GL function
		 *
		 * Returns the address of the GL function proc, or NULL if the function is not found. If the GL library is loaded at runtime, with LoadLibrary(), then all GL functions must be retrieved this way. Usually this is used to retrieve function pointers to OpenGL extensions. Note that this function needs an OpenGL context to function properly, so it should be called after Screen::SetVideoMode() has been called (with the SDL_OPENGL flag).
		 *
		 * OpenGL function pointers must be declared APIENTRY as in the example code. This will ensure the proper calling convention is followed on platforms where this matters (Win32) thereby avoiding stack corruption. In a Win32 build environment, APIENTRY should be defined as __stdcall. 
		 *
		 * \return the address of the GL function proc, or NULL if the function is not found.
		 * \throws std::logic_error if the Screen has not been initialized.
		 */
		void *GetProcAddress(const std::string proc);

		/*!
		 * \brief Get the value of a special SDL/OpenGL attribute
		 *
		 * Places the value of the SDL/OpenGL attribute attr into value. This is useful after a call to Screen::SetVideoMode() to check whether your attributes have been set as you expected.
		 *
		 * \return true an sucess and false on an error.
		 * \throws std::logic_error if the Screen has not been initialized.
		 */
		bool GetAttribute(Attr attr, int &value);

		/*!
		 * \brief Set a special SDL/OpenGL attribute
		 *
		 * Sets the OpenGL attribute attr to value. The attributes you set don't take effect until after a call to Screen::SetVideoMode(). You should use GetAttribute() to check the values after a Screen::SetVideoMode() call, since the values obtained can differ from the requested ones.
		 *
		 * \note The SDL_DOUBLEBUF flag is not required to enable double buffering when setting an OpenGL video mode. Double buffering is enabled or disabled using the SDL_GL_DOUBLEBUFFER attribute. 
		 * \return true an sucess and false on an error.
		 * \throws std::logic_error if the Screen has been initialized.
		 */
		bool SetAttribute(Attr attr, int value);

		/*!
		 * \brief Swap OpenGL framebuffers/Update Display
		 *
		 * only if double-buffering is supported.
		 */
		void SwapBuffers(void);
	}

	/*!
	 * \brief The Surface that represents the screen to be drawn to.
	 *
	 * This class inherits all of Surface and then adds the functionality to set the video mode (SetVideoMode()), icon (SetIcon()), gamma (SetGamma()), and gammaramp. It also has UpdateRect(), UpdateRects(), and Flip() to use.
	 *
	 * Unwrapped Screen functions:
	 * \code
	 * SDL_Rect **SDL_ListModes(SDL_PixelFormat *format, Uint32 flags);
	 * void SDL_GL_SwapBuffers(void );
	 * int SDL_GL_SetAttribute(SDL_GLattr attr, int value);
	 * int SDL_GL_GetAttribute(SDLGLattr attr, int *value);
	 * void *SDL_GL_GetProcAddress(const char* proc);
	 * int SDL_GL_LoadLibrary(const char *path);
	 * \endcode
	 *
	 * \note Sceen uses the special Surface constructor so Surface doesn't free m_Surface on destruction. This is because Quit() does frees the video surface.
	 */ 
	class Screen : public Surface
	{
		public:
			/*!
			 * \brief Default constructor
			 *
			 * Sets m_Surface to NULL
			 */
			Screen();

			/*!
			 * \brief Create this screen.
			 *
			 * Sets up the video mode with these paramaters by calling SetVideoSurface().
			 *
			 * \param w is the width of the window/resolution
			 * \param h is the height of the window/resolution
			 * \param bpp is the bits per pixel for the window/resolution
			 * \param flags is the SDL_Surface flags 
			 * 
			 * \sa Surface::m_Surface for list of flags passable as flags.
			 *
			 */
			Screen(int w, int h, int bpp, Uint32 flags = SDL_SWSURFACE);

			/*!
			 * \brief Sets this icon to the Screen.
			 *
			 * This makes a call to SetIcon() to set the icon of the window.
			 *
			 * \throws std::logic_error if the Screen has already been setup or if icon.m_Surface is NULL.
			 */
			Screen(Surface &icon, Uint8 *mask);

			/*!
			 * \brief Default destructor
			 *
			 * Does nothing.
			 */
			~Screen();

			/*!
			 * \brief Swaps screen buffers
			 *
			 * On hardware that supports double-buffering, this function sets up a flip and returns. The hardware will wait for vertical retrace, and then swap video buffers before the next video surface blit or lock will return. On hardware that doesn't support double-buffering, this is equivalent to calling UpdateRect(0, 0, 0, 0)
			 *
			 * The SDL_DOUBLEBUF flag must have been passed to SetVideoMode, when setting the video mode for this function to perform hardware flipping.
			 * 
			 * \return True if successful, or False otherwise.
			 */
			bool Flip();

			/*!
			 * \brief Makes sure the given area is updated.
			 *
			 * The rectangle must be confined within the screen boundaries (no clipping is done).
			 *
			 * If 'x', 'y', 'w' and 'h' in rect are all 0, UpdateRect will update the entire screen.
			 *
			 * \note This function should not be called while 'screen' is locked.
			 */
			void UpdateRect(Rect &rect);

			/*!
			 * \brief Makes sure the given area is updated.
			 *
			 * The rectangle must be confined within the screen boundaries (no clipping is done).
			 *
			 * If 'x', 'y', 'w' and 'h' are all 0, UpdateRect will update the entire screen.
			 *
			 * This function should not be called while 'screen' is locked.
			 */
			void UpdateRect(Sint32 x, Sint32 y, Sint32 w, Sint32 h);

			/*!
			 * \brief Makes sure the given list of rectangles is updated.
			 *
			 * The rectangles must all be confined within the screen boundaries (no clipping is done).
			 *
			 * The rectangles are not automatically merged or checked for overlap. 
			 * In general, the programmer can use his knowledge about his particular rectangles to merge them in an efficient way, to avoid overdraw.
			 *
			 * \note This function should not be called while screen is locked.
			 *
			 * \note It is adviced to call this function only once per frame, since each call has some processing overhead. This is no restriction since you can pass any number of rectangles each time.
			 */
			void UpdateRects(int numrects, Rect *rects);

			/*!
			 * \brief Sets the color gamma function for the display.
			 *
			 * Sets the "gamma function" for the display of each color component. Gamma controls the brightness/contrast of colors displayed on the screen. A gamma value of 1.0 is identity (i.e., no adjustment is made).
			 *
			 * This function adjusts the gamma based on the "gamma function" parameter, you can directly specify lookup tables for gamma adjustment with SetGammaRamp().
			 *
			 * Not all display hardware is able to change gamma.
			 * 
			 * \return False on error (or if gamma adjustment is not supported), True otherwise.
			 */
			static bool SetGamma(float redgamma, float greengamma, float bluegamma);

			/*!
			 * \brief Gets the color gamma lookup tables for the display.
			 *
			 * Gets the gamma translation lookup tables currently used by the display. Each table is an array of 256 Uint16 values.
			 *
			 * Not all display hardware is able to change gamma.
			 * 
			 * \return  False on error, True otherwise.
			 */
			static bool GetGammaRamp(Uint16 &redtable, Uint16 &greentable, Uint16 &bluetable);

			/*!
			 * \brief Sets the color gamma lookup tables for the display.
			 *
			 * Sets the gamma lookup tables for the display for each color component. Each table is an array of 256 Uint16 values, representing a mapping between the input and output for that channel. The input is the index into the array, and the output is the 16-bit gamma value at that index, scaled to the output color precision. You may pass NULL to any of the channels to leave them unchanged.
			 *
			 * This function adjusts the gamma based on lookup tables, you can also have the gamma calculated based on a "gamma function" parameter with SetGamma().
			 *
			 * Not all display hardware is able to change gamma.
			 *
			 * \return False on error (or if gamma adjustment is not supported), True otherwise.
			 */
			static bool SetGammaRamp(Uint16 &redtable, Uint16 &greentable, Uint16 &bluetable);
			
			/*!
			 * \brief Check to see if a particular video mode is supported.
			 *
			 * The bits-per-pixel value returned is only a suggested mode. You can usually request and bpp you want when setting the video mode and SDL will emulate that color depth with a shadow video surface.
			 *
			 * The arguments to VideoModeOK() are the same ones you would pass to SetVideoMode()
			 *
			 * \return 0 if the requested mode is not supported under any bit depth, or returns the bits-per-pixel of the closest available mode with the given width, height and requested surface flags
			 * \sa SetVideoMode() for flags.
			 */
			static int VideoModeOK(int w, int h, int bpp, Uint32 flags);

			/*!
			 * \brief Obtain the name of the video driver.
			 *
			 * The driver name is a simple one word identifier like "x11" or "windib".
			 *
			 * \return an empty string if video has not been initialised with Init() or a string with the driver name in it.
			 */
			static std::string VideoDriverName();

			/*!
			 * \brief Get information about the video hardware.
			 *
			 * \return VideoInof containing the information about the video hardware. 
			 * \note If this is called before SetVideoMode(), the vfmt member of the returned structure will contain the pixel format of the "best" video mode.
			 */
			static VideoInfo GetVideoInfo(void);

			/*!
			 * \brief Set up a video mode with the specified width, height and bits-per-pixel.
			 *
			 * \param w is the width of the window/resolution.
			 * \param h is the height of the window/resolution.
			 * \param bpp is the bits per pixel for the window/resolution.
			 * \param flags are the flags below.
			 * 
			 * \htmlonly
			 *
			 * <TABLE BORDER="1" CLASS="CALSTABLE">
			 *	<TBODY>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_SWSURFACE
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Create the video surface in system memory
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_HWSURFACE
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Create the video surface in video memory
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_ASYNCBLIT
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Enables the use of asynchronous updates of the display surface. This will usually slow down blitting on single CPU machines, but may provide a speed increase on SMP systems.
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_ANYFORMAT
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Normally, if a video surface of the requested bits-per-pixel (<I>bpp</I>) is not available, SDL will emulate one with a shadow surface. Passing SDL_ANYFORMAT prevents this and causes SDL to use the video surface, regardless of its pixel depth.
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_HWPALETTE
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Give SDL exclusive palette access. Without this flag you may not always get the the colors you request with SetColors() or SetPalette() .
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_DOUBLEBUF
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Enable hardware double buffering; only valid with SDL_HWSURFACE. Calling Flip() will flip the buffers and update the screen. All drawing will take place on the surface that is not displayed at the moment. If double buffering could not be enabled then SDL_Flip will just perform a UpdateRect() on the entire screen.
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_FULLSCREEN
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL will attempt to use a fullscreen mode. If a hardware resolution change is not possible (for whatever reason), the next higher resolution will be used and the display window centered on a black background.
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_OPENGL
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Create an OpenGL rendering context. You should have previously set OpenGL video attributes with GL_SetAttribute().
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_OPENGLBLIT
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Create an OpenGL rendering context, like above, but allow normal blitting operations. The screen (2D) surface may have an alpha channel, and UpdateRects must be used for updating changes to the screen surface. NOTE: This option is kept for compatibility only, and is<I>not</I *recommended for new code.
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_RESIZABLE
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			Create a resizable window. When the window is resized by the user a SDL_VIDEORESIZE event is generated and SetVideoMode() can be called again with the new size.
			 *		</TD>
			 *	</TR>
			 *	<TR>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *		
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			SDL_NOFRAME
			 *		</TD>
			 *		<TD ALIGN="LEFT" VALIGN="TOP">
			 *			If possible, SDL_NOFRAME causes SDL to create a window with no title bar or frame decoration. Fullscreen modes automatically have this flag set.
			 *		</TD>
			 *	</TR>
			 *	</TBODY>
			 * </TABLE>
			 * \endhtmlonly
			 *
			 * \return True if m_Surface is created and non-NULL, false if NULL.
			 */
			bool SetVideoMode(int w, int h, int bpp, Uint32 flags = SDL_SWSURFACE);

			/*!
			 * \brief Sets the icon for the display window.
			 *
			 * Sets the icon for the display window. Win32 icons must be 32x32.
			 *
			 *
			 * The mask is a bitmask that describes the shape of the icon. If mask is NULL, then the shape is determined by the colorkey of icon, if any, or makes the icon rectangular (no transparency) otherwise.
			 *
			 * If mask is non-NULL, it points to a bitmap with bits set where the corresponding pixel should be visible. The format of the bitmap is as follows: Scanlines come in the usual top-down order. Each scanline consists of (width / 8) bytes, rounded up. The most significant bit of each byte represents the leftmost pixel.
			 * 
			 * \note This function must be called before the first call to SDL_SetVideoMode.
			 */
			void SetIcon(Surface &icon, Uint8 *mask);

			/*!
			 * \brief Create an Overlay from an SDL_Overlay.
			 *
			 * Documentation not written yet.
			 */
			void SetIcon(std::string iconname, Uint8 *mask);

			/*!
			 * \brief Toggles fullscreen mode.
			 *
			 * Toggles the application between windowed and fullscreen mode, if supported. (X11 is the only target currently supported, BeOS support is experimental).
			 *
			 * \return True on success, and False otherwise.
			 */
			bool ToggleFullScreen();

			/*!
			 * \brief Fills vid with current display surface
			 *
			 * \post Screen has the current display and is ready to be used.
			 *
			 *
			 * Multiple Screen classes can be used after the call to SetVideoMode() by calling GetVideoSurface().
			 * \code
			 * void SetScreen()
			 * {
			 * 	Screen screen1(320, 200, 8);
			 * }
			 *
			 * void SomeOtherFunction()
			 * {
			 * 	Screen screen;
			 *
			 * 	if(!GetVideoSurface(screen))
			 * 		cout << "Error getting screen" << endl;
			 * } 
			 * \endcode
			 * \return True if m_Surface is non-NULL, or False otherwise.
			 */
			friend bool GetVideoSurface(Screen &vid);
		
			friend bool GL::LoadLibrary(const std::string path);
			friend void *GL::GetProcAddress(const std::string proc);
			friend bool GL::GetAttribute(Attr attr, int &value);
			friend bool GL:: SetAttribute(Attr attr, int value);
	};
	
	bool GetVideoSurface(Screen &vid);

	/*!
	 * \brief YUV overlay wrapped class.
	 *
	 * This is for anyone who wants overlays. I've never used them, so if someone wants to expand upon this, then feel free to.
	 *
	 * \note May need some work to play nice with Surface or Screen.
	 */
	class Overlay
	{
		public:
			/*!
			 * \brief Default constructor.
			 *
			 * Creates an empty Overlay. 
			 * 
			 * \note Until created (m_Overlay), Display will throw an execption. So make sure to initialize it before then.
			 */
			Overlay();

			/*!
			 * \brief Copy constructor.
			 *
			 * Documentation not written yet.
			 */
			Overlay(const Overlay &copy);

			/*!
			 * \brief Create an Overlay from an SDL_Overlay.
			 *
			 * Documentation not written yet.
			 */
			Overlay(SDL_Overlay *overlay);

			/*!
			 * \brief Destructor.
			 *
			 * Documentation not written yet.
			 */
			~Overlay();

			/*!
			 * \brief Create an Overlay.
			 *
			 * Documentation not written yet.
			 */
			void Create(int width, int height, Uint32 format, SDL_Surface *display);

			/*!
			 * \brief Lock the Overlay.
			 *
			 * Documentation not written yet.
			 * 
			 * \return True if Overlay was locked, False on error.
			 */
			bool Lock();

			/*!
			 * \brief Unlock the Overlay.
			 *
			 * Documentation not written yet.
			 */
			void Unlock();

			/*!
			 * \brief Display the Overlay on the Screen.
			 *
			 * Documentation not written yet.
			 * 
			 * \return True if it was able to be displayed, False otherwise.
			 */
			bool Display(Rect &destrect);
		protected:
			/*!
			 * \brief Free the Overlay.
			 *
			 * Documentation not written yet.
			 */
			void Free();

			/*!
			 * \brief The main data for this class.
			 *
			 * Documentation not written yet.
			 */
			SDL_Overlay *m_Overlay;
	};
	//@}	
}

#endif

