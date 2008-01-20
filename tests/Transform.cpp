#include <iostream>
#include <stdexcept>

#include "SDL4Cpp.h"
#include <SDL/SDL_image.h>

using namespace std;
using namespace SDL;

/*
 * These (for the most part) should only be done on squares.
 * Copy is the only one that shouldn't matter.
 *
 * I tried to make sure to use SDL4Cpp as much as possible
 *
 * Also, these are mainly examples to illistrate how to completely
 * take control of the underlying Surface. Even though it should be
 * pretty obvious to most, an example doesn't hurt either.
 */
class Transform : public Surface
{
	public:
		Transform() {};
		~Transform() {};

		// To do a Transform = Surface copy
		Transform operator=(const Surface &copy)
		{
			Surface temp = copy;
			// don't try blitting if the surface from copy is NULL
			if(temp.Get() != NULL)
			{
				// Free the current surface if needed
				if(m_Surface != NULL)
					Free();

				// get the surface information from the copy
				Convert(temp);

				// then copy the data here
				if(!Blit(temp))
					throw runtime_error(SDL::GetError());
			}

			return *this;
		}

		/*
		 * 1 rotation is 90 degrees clockwise 1-4 valid
		 */
		void Rotation(int rotations)
		{
			// If rotations is 0, we don't wantto do anything
			if(!rotations)
				return;
			// As usual check for programmers' errors
			if(!m_Surface)
				throw logic_error("Surface not initialized before call to rotation. Doing nothing");
			if(rotations > 3)
				throw  logic_error("rotations should be between 0 and 3");


			// Maximum X
			int maxX = m_Surface->w;
			// Maximum Y
			int maxY = m_Surface->h;

			// The dest copys the first row to the last column, then second row to second to last column, etc
			//
			// destpossitionY = 0, srcpossitionX = 0, destX--, and srcY++ after each inner loop
			// destX and srcY are used to make code cleaner looking instead of just x and y for counters
			int srcpossitionX, srcpossitionY, destpossitionX, destpossitionY;

			// These are the two pixel pointers which are used to copy each pixel of the image
			Uint8 *srcpixelpointer, *destpixelpointer;

			// Short handed versions
			int bpp = m_Surface->format->BytesPerPixel, pitch = m_Surface->pitch;

			for(int x = 0; x < rotations; x++)
			{
				// Create a new surface the same that's the same as m_Surface
				Surface destsurface;
				destsurface.CreateRGB(m_Surface->flags, m_Surface->w, m_Surface->h, m_Surface->format->BitsPerPixel,
						m_Surface->format->Rmask, m_Surface->format->Gmask, m_Surface->format->Bmask, m_Surface->format->Amask);
				// We need to set the dest possitions so that it wont get out of bounds
				destpossitionX = maxX - 1;
				destpossitionY = 0;

				// Lock if needed the surfaces to work with the pixels
				Lock();
				destsurface.Lock();

				// These two for loops will do one rotation
				for(srcpossitionY = 0; srcpossitionY < maxY; srcpossitionX = 0, destpossitionY = 0, destpossitionX--, srcpossitionY++)
				{
					for(srcpossitionX = 0; srcpossitionX < maxX; srcpossitionX++, destpossitionY++)
					{
						// Then move the pixel by X = posX * bpp  and Y = posY * pitch
						// Then add that value to pixels
						srcpixelpointer = (Uint8 *)m_Surface->pixels + srcpossitionY * pitch + srcpossitionX * bpp;
						destpixelpointer = (Uint8 *)destsurface.Get()->pixels + destpossitionY * pitch + destpossitionX * bpp;

						// Set the destpixelpointer equal to the pixel from srcpixelpointer
						// This process is different for each bpp
						switch(bpp)
						{
							case 1:
								// Already an 8 bit uint
								*destpixelpointer = *srcpixelpointer;
								break;
							case 2:
								// Cast to a 16 bit uint
								*(Uint16 *)destpixelpointer = *(Uint16 *)srcpixelpointer;
							case 3:
								// No casting can be done here but this works ok
								// This could be done for 2 and 4, but the casting
								// works as well and is less typing
								destpixelpointer[0] = srcpixelpointer[0];
								destpixelpointer[1] = srcpixelpointer[1];
								destpixelpointer[2] = srcpixelpointer[2];
								break;
							case 4:
								// Cast to a 32 bit uint
								*(Uint32 *)destpixelpointer = *(Uint32 *)srcpixelpointer;
								break;
						}
					}
				}

				// Unlock the surfaces because we're done with pixel manipulation for now
				destsurface.Unlock();
				Unlock();

				// In order to another rotation, we need m_Surface to be the same as destsurface (which is rotated)
				*this = destsurface;
			}
		}

		/*
		 * This copies each line of one surface to another (It does the same thing as Blit)
		 * This way most likely isn't the most effective but illistrates one
		 * way to copy one surface to another.
		 *
		 * And more importantly how some of the lower level pixel maniplations
		 * can be implimented.
		 *
		 * I don't completely trust this function. It does work, but I wont
		 * be using it for anything other than this demonstration.
		 */
		void Copy(Surface &CopySurface)
		{
			// Check it the CopySurface has a surface before destroying the data in this one
			if(CopySurface.Get() == NULL)
				throw runtime_error("Error initializing a surface");

			// srcsurface is shorter to type than CopySurface.Get()
			// I'm lazy alright?
			SDL_Surface *srcsurface = CopySurface.Get();

			// Maximum Y
			int maxY = srcsurface->h;
			// Another shorthand variable
			int bpp = srcsurface->format->BytesPerPixel;
			// Each pixel is X bits per pixel, and 8 bits are in one byte (one Uint8),
			// So, size[bpp] * each pixel in the width is how large each row is
			Uint8 sizeBpp[bpp];
			int size = sizeof(sizeBpp) * srcsurface->w;

			// Our two pointers for the our two surfaces
			// srcpixelpointer is the pixel pointer to the surface that was passed in
			// and destpixelpointer is the pixel pointer to m_Surface.
			// Both are going to point to the area for the first pixel for each row
			Uint8 *srcpixelpointer, *destpixelpointer;

			// Free m_Surface if needed
			if(m_Surface)
				Free();

			// Create a new surface the same that's the same as CopySurface
			CreateRGB(srcsurface->flags, srcsurface->w, srcsurface->h, srcsurface->format->BitsPerPixel,
					srcsurface->format->Rmask, srcsurface->format->Gmask, srcsurface->format->Bmask, srcsurface->format->Amask);

			// Lock the surfaces to work with the pixels
			Lock();
			CopySurface.Lock();

			// Do a row by row copy
			for(int y = 0; y < maxY; y++)
			{
				srcpixelpointer = (Uint8 *)srcsurface->pixels + y * srcsurface->pitch;
				destpixelpointer = (Uint8 *)m_Surface->pixels + y * m_Surface->pitch;

				memcpy(destpixelpointer, srcpixelpointer, sizeof(Uint8) * srcsurface->pitch);
			}

			// Unlock the surfaces because we're done with pixel manipulation
			CopySurface.Unlock();
			Unlock();
		}

		/*
		 * Do a horizontal flip
		 */
		void FlipH()
		{
		}

		/*
		 * Do a vertical flip
		 */
		void FlipV()
		{
		}

	private:
};

int main(int argv, char *argc[])
{
	SDL::Init(SDL_INIT_VIDEO);
	atexit(SDL::Quit);

	class Handler : public Handle
	{
		public:
			Handler() : keypressed(false)
			{
			}

			bool KeyPressed(KeySym &keysym)
			{
				if(keysym.sym == SDLK_ESCAPE)
					keypressed = true;

				return true;
			}

			operator bool()
			{
				return keypressed;
			}

		private:
			bool keypressed;
	} myHandler;

	Event myEvent;

	int gap = 40;
	Transform Tests, Tests2, Tests3, Tests4;

	Tests.LoadBMP("square.bmp");
	Tests2 = IMG_Load("square.png");

	Rect square(gap, gap, Tests.GetRect().w, Tests.GetRect().w);

	Screen screen(420, 240, 32);
	Rect screenRect(0, 0, 420, 240);
	// Fill the screen with this color (which was the purple used for transparency in Allegro =)
	// And byte order shouldn't matter here since FF00FF is the same in Big or Little endian
	screen.FillRect(screenRect, 0xFF00FF);

	// Blit the first surface
	screen.Blit(Tests, square);

	// Test Copying images here

	// Make a copy of the first surface and blit the copy
	Tests3.Copy(Tests);
	square.x += Tests.GetRect().w + gap;
	screen.Blit(Tests3, square);

	// Blit the second image
	square.x += Tests3.GetRect().w + gap;
	screen.Blit(Tests2, square);

	// Make a copy of the second image and blit that
	Tests4.Copy(Tests2);
	square.x += Tests2.GetRect().w + gap;
	screen.Blit(Tests4, square);

	// Test rotations here
	// First move the rect dow one and zero x out and do the same
	// as above but with Rotation
	square.y += Tests.GetRect().w + gap;
	square.x = gap;

	// Rotate none Blit the first surface
	Tests.Rotation(0);
	screen.Blit(Tests, square);

	// Rotate Tests3 90 degrees clockwise and blit it
	Tests3.Rotation(1);
	square.x += Tests.GetRect().w + gap;
	screen.Blit(Tests3, square);

	// Rotate Tests2 180 degrees clockwiso and blit it
	square.x += Tests3.GetRect().w + gap;
	Tests2.Rotation(2);
	screen.Blit(Tests2, square);

	// Rotate Test4 270 degrees clockwise and blit it
	// It really does do the rotation clockwise three times
	// at 90 degrees each time, which is in-efficient, again
	// this is an example and not production quality.
	//
	// Though if one relatively small image needs to be rotate
	// like this only once the code would be good enough, but for
	// larger images or ones that need to be rotated multiple times
	// it will get costly.
	//
	// In the later case, you should consider precalculating the rotations
	// and saving the precalculated rotations in an image (or multiple images.)
	//
	// I just felt this was worth noting.
	Tests4.Rotation(3);
	square.x += Tests2.GetRect().w + gap;
	screen.Blit(Tests4, square);

	screen.Flip();

	while(!myHandler)
		myEvent.Poll(myHandler);

	return 0;
}
