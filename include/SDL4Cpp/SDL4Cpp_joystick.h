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

#ifndef SDL4CPP_JOYSTICK_H
#define SDL4CPP_JOYSTICK_H

#include <string>
#include "SDL_joystick.h"


namespace SDL
{
	/*!
	 * \defgroup Joystick Joystick
	 */
	//@{

	/*!
	 * \brief Count available joysticks.
	 *
	 * \return The number of joysticks attached to the system
	 */
	int NumJoysticks(void);

	/*!
	 * \brief Handling of joysticks and their respective actions.
	 *
	 * Joystick support is initialized by passed the SDL_INIT_JOYSTICK flag to
	 * SDL::Init(). Once initilized joysticks must be opened using
	 * Joystick::Open or the appropriate constructor.
	 *
	 * \note If you are not handling the joystick via the event queue then you
	 * must explicitly request a joystick update by calling JoystickUpdate.
	 */
	class Joystick
	{
		public:
			/*!
			 * \brief Default constructor.
			 *
			 * Constructor that doesn't try to load a joystick when being
			 * constructed.
			 */
			Joystick(void);
			/*!
			 * \brief Load a joystick on construction.
			 *
			 * A constructor that is passed the number of the joystick to
			 * open.
			 * \param index is the number of the joystick to open, from
			 * 0-[NumJoysticks-1]
			 *
			 * \throws SDL::LogicError if that joystick isn't available
			 */
			Joystick(int index);
			/*!
			 * \brief Deconstructor
			 *
			 * Frees the current joystick
			 * \throws SDL::RuntimeError if that joystick isn't freed
			 */
			~Joystick(void);

			/*!
			 * \brief Opens a joystick for use.
			 *
			 * Opens a joystick for use within SDL. A joystick must be opened
			 * before it game be used.
			 *
			 * \param index is the number of the joystick to open, from
			 * 0-[NumJoysticks-1]
			 *
			 * \return False on error, True otherwise.
			 */
			bool Open(int index);

			/*!
			 *
			 */
			bool Opened();

			/*!
			 * \brief Determine if a joystick has been opened
			 *
			 * Determines whether a joystick has already been opened within
			 * the application.
			 *
			 * \param index is the number of the joystick to open, from
			 * 0-[NumJoysticks-1]
			 *
			 * \return True if a joystick at that location is opened,
			 * otherwise False.
			 */
			static bool Opened(int index);

			/*!
			 * \brief Get the index of this Joystick
			 *
			 * \return The index number of this Joystick.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			int Index(void);

			/*!
			 * \brief Get the number of joystick axes
			 *
			 * \return The number of axes for this Joystick.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			int NumAxes(void);
			/*!
			 * \brief Get joystick name.
			 *
			 * Get the implementation dependent name of this Joystick.
			 *
			 * \return Returns a std::string to this Joystick name.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			std::string Name();
			/*!
			 * \brief Updates the state of all joysticks
			 *
			 * Updates the state(position, buttons, etc.) of all open
			 * joysticks.
			 * If joystick events have been enabled with
			 * SDL_JoystickEventState then this is called automatically in the
			 * event loop.
			 */
			static void Update(void);
			/*!
			 * \brief Get the number of joystick trackballs
			 *
			 * \return The number of balls for this Joystick.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			int NumBalls(void);
			/*!
			 * \brief Get the number of joystick hats
			 *
			 * \return The number of hats for this Joystick.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			int NumHats(void);
			/*!
			 * \brief Get the number of joysitck buttons
			 *
			 * \return The number of buttons for this Joystick.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			int NumButtons(void);

			/*!
			 * \brief Get the current state of an axis
			 *
			 * On most modern joysticks the X axis is usually represented by
			 * axis 0 and the Y axis by axis 1.
			 * The value returned by GetAxis is a signed integer (-32768 to
			 * 32768) representing the current position of the axis,
			 * it maybe necessary to impose certain tolerances on these values
			 * to account for jitter.
			 * It is worth noting that some joysticks use axes 2 and 3 for
			 * extra buttons.
			 *
			 * \param axis is the axis you want information for.
			 *
			 * \return A 16-bit signed integer representing the current
			 * position of the axis.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			Sint16 GetAxis(int axis);
			/*!
			 * \brief Get the current state of a joystick hat
			 *
			 * \param hat is the hat you want the information for.
			 *
			 * \return The current state is returned as a Uint8 which is
			 * defined as an OR'd combination of one or more of the following
			 * \code
			 * SDL_HAT_CENTERED
			 * SDL_HAT_UP
			 * SDL_HAT_RIGHT
			 * SDL_HAT_DOWN
			 * SDL_HAT_LEFT
			 * SDL_HAT_RIGHTUP
			 * SDL_HAT_RIGHTDOWN
			 * SDL_HAT_LEFTUP
			 * SDL_HAT_LEFTDOWN
			 * \endcode
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			Uint8 GetHat(int hat);
			/*!
			 * \brief Get the current state of a given button on a given joystick
			 *
			 * \param button is the button you want information for.
			 *
			 * \return True if the button is pressed, False if not.
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			bool GetButton(int button);
			/*!
			 * \brief Get relative trackball motion
			 *
			 * Trackballs can only return relative motion since the last call
			 * to GetBall, these motion deltas a placed into dx and dy.
			 *
			 * \param ball is the ball you want information on.
			 * \param dx is the change in x since the last call to GetBall().
			 * \param dy is the change in y since the last call to GetBall().
			 *
			 * \return False on failure, True otherwise. This does not mean
			 * False if no movement and true otherwise. That has to be
			 * determined by if there is a change in x or y
			 *
			 * \throws SDL::LogicError if the joystick isn't initialized
			 */
			bool GetBall(int ball, int &dx, int &dy);
		protected:
			/*!
			 * \brief Close this joystick
			 *
			 * \return False on error, True otherwise.
			 */
			bool Close(void);

			/*!
			 * \brief The structure SDL uses for joystick information.
			 *
			 * All funtions in this class work on this variable.
			 *
			 * \b Structure \b Definition
			 * taken from src/joystick/SDL_sysjoystick.h
			 * \code
			 * struct _SDL_Joystick
			 * {
			 *	Uint8 index;		// Device index
			 *	const char *name;	// Joystick name - system dependent
			 *
			 *	int naxes;		// Number of axis controls on the joystick
			 *	Sint16 *axes;		// Current axis states
			 *
			 *	int nhats;		// Number of hats on the joystick
			 *	Uint8 *hats;		// Current hat states
			 *
			 *	int nballs;		// Number of trackballs on the joystick
			 *	struct balldelta
			 *	{
			 *		int dx;
			 *		int dy;
			 *	} *balls;		// Current ball motion deltas
			 *
			 *	int nbuttons;		// Number of buttons on the joystick
			 *	Uint8 *buttons;		// Current button states
			 *
			 *	struct joystick_hwdata *hwdata;	// Driver dependent information
			 *	int ref_count;		// Reference count for multiple opens
			 * };
			 * \endcode
			 */
			SDL_Joystick *m_Joystick;
			/*!
			 * \brief Holds the index of the current joystick
			 */
			int m_Index;
	};
	//@}
}

#endif

