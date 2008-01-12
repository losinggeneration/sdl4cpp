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

#ifndef SDL4CPP_TIME_H
#define SDL4CPP_TIME_H

#include "SDL.h"
#include <vector>


namespace SDL
{
	/*!
	 * SDL provides several cross-platform functions for dealing with time. It
	 * provides a way to get the current time, a way to wait a little while,
	 * and a simple timer mechanism. These functions give you two ways of
	 * moving an object every x milliseconds:
	 *
	 * Use a timer callback function. This may have the bad effect that it runs
	 * in a seperate thread or uses alarm signals, but it's easier to
	 * implement.
	 * Or you can get the number of milliseconds passed, and move the object
	 * if, for example, 30 ms passed.
	 */

	/*!
	 * \defgroup Time Time.
	 */
	//@{
	
	/*!
	 * \brief The ID of a timer
	 *
	 * \b Structure \b Definition
	 * Taken from src/timer/SDL_timer.c
	 * \code
	 * struct SDL_TimerID
	 * {
	 * 	Uint32 interval;
	 * 	SDL_NewTimerCallback cb;
	 * 	void *param;
	 * 	Uint32 last_alarm;
	 * 	struct _SDL_TimerID *next;
	 * };
	 * \endcode
	 */
	typedef SDL_TimerID TimerID;
	
	/*!
	 * \brief Get the number of milliseconds since the SDL library initialization.
	 *
	 * \return The number of milliseconds since the SDL library
	 * initialization. 
	 * \note That this value wraps if the program runs for more than ~49 days.
	 */
	Uint32 GetTicks(void);
	/*!
	 * \brief Wait a specified number of milliseconds before returning.
	 *
	 * Delay() will wait at least the specified time, but possible longer due
	 * to OS scheduling.
	 *
	 * \note Count on a delay granularity of at least 10 ms. Some platforms
	 * have shorter clock ticks but this is the most common.
	 *
	 */
	void Delay(Uint32 ms);
	
	/*!
	 * \brief Add a timer which will call a callback after the specified number of milliseconds has elapsed.
	 *
	 * \note Callback type definition for the "new" timer callback function is
	 * \code typedef Uint32 (*SDL_NewTimerCallback)(Uint32 interval, void *param); \endcode
	 * 
	 * Adds a callback function to be run after the specified number of
	 * milliseconds has elapsed. The callback function is passed the current
	 * timer interval and the user supplied parameter from the AddTimer() call
	 * and returns the next timer interval. If the returned value from the
	 * callback is the same as the one passed in, the periodic alarm
	 * continues, otherwise a new alarm is scheduled.
	 *
	 * To cancel a currently running timer call RemoveTimer() with the timer
	 * ID returned from AddTimer().
	 *
	 * The timer callback function may run in a different thread than your
	 * main program, and so shouldn't call any functions from within itself.
	 * You may always call SDL::Event::Push(), however.
	 *
	 * The granularity of the timer is platform-dependent, but you should
	 * count on it being at least 10 ms as this is the most common number.
	 * This means that if you request a 16 ms timer, your callback will run
	 * approximately 20 ms later on an unloaded system. If you wanted to set a
	 * flag signaling a frame update at 30 frames per second (every 33 ms),
	 * you might set a timer for 30 ms (see example below). If you use this
	 * function, you need to pass SDL_INIT_TIMER to Init().
	 *
	 *
	 * \return An ID value for the added timer or NULL if there was an error.
	 */
	TimerID AddTimer(Uint32 interval, SDL_NewTimerCallback callback,
					  void *param);
	/*!
	 * \brief Remove a timer which was added with AddTimer()
	 *
	 * \return True on success, false on failure.
	 */
	bool RemoveTimer(TimerID id);
	/*!
	 * \brief Set a callback to run after the specified number of milliseconds has elapsed.
	 *
	 * \note Callback Function prototype for the timer callback function is
	 * \code typedef Uint32 (*SDL_TimerCallback)(Uint32 interval); \endcode
	 * 
	 * Set a callback to run after the specified number of milliseconds has
	 * elapsed. The callback function is passed the current timer interval and
	 * returns the next timer interval. If the returned value is the same as
	 * the one passed in, the periodic alarm continues, otherwise a new alarm
	 * is scheduled.
	 *
	 * To cancel a currently running timer, call SetTimer(0, NULL);
	 *
	 * The timer callback function may run in a different thread than your
	 * main constant, and so shouldn't call any functions from within itself.
	 *
	 * The maximum resolution of this timer is 10 ms, which means that if you
	 * request a 16 ms timer, your callback will run approximately 20 ms later
	 * on an unloaded system. If you wanted to set a flag signaling a frame
	 * update at 30 frames per second (every 33 ms), you might set a timer for
	 * 30 ms (see example below).
	 *
	 * If you use this function, you need to pass SDL_INIT_TIMER to Init().
	 *
	 * \note This function is kept for compatibility but has been superseded
	 * by the new timer functions AddTimer and RemoveTimer which support
	 * multiple timers.
	 * 
	 * \return not sure actually
	 */
	int SetTimer(Uint32 interval, SDL_TimerCallback callback);
	
	/*!
	 * \brief A little bit less direct Timer handling
	 *
	 * Same as the functions but lets the class deal with the TimerID and
	 * automatically removes the timer on destruction.
	 * \note Only one timer is used per class and if another is added the
	 * previous is removed first.
	 */
	class Timer
	{
		public:
			/*!
			 * \brief Default Constructor
			 */
			Timer();
			/*!
			 * \brief Default Destructor
			 *
			 * Remove() and that's really it.
			 */
			~Timer();
			/*!
			 * \brief Add a timer which will call a callback after the specified number of milliseconds has elapsed.
			 *
			 * \see AddTimer()
			 *
			 * \return True on success, False on an error.
			 */
			bool Add(Uint32 interval, SDL_NewTimerCallback callback,
					 void *param);
			/*!
			 * \brief Removes a timer.
			 *
			 * \see RemoveTimer()
			 * \return True on success, False on an error.
			 */
			bool Remove();
		protected:
			/*!
			 * \brief protected ID for class;
			 *
			 * This is the timer ID used for the class.
			 *
			 * \sa TimerID
			 */
			std::vector<TimerID> m_ID;
	};
	//@}
}

#endif

