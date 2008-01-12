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

#ifndef SDL4CPP_EVENTS_H
#define SDL4CPP_EVENTS_H

#include <string>
#include "SDL.h"

namespace SDL
{
	/*!
	 * \defgroup Events Event handling
	 */
	//@{
	
	/*!
	 * \brief A shorter version of SDL_ActiveEvent
	 *
	 * ActiveEvent is a member of the SDL_Event union and is used when an event
	 * of type SDL_ACTIVEEVENT is reported.
	 *
	 * When the mouse leaves or enters the window area a SDL_APPMOUSEFOCUS type
	 * activation event occurs, if the mouse entered the window then gain will
	 * be 1, otherwise gain will be 0. A SDL_APPINPUTFOCUS type activation
	 * event occurs when the application loses or gains keyboard focus. This
	 * usually occurs when another application is made active. Finally, a
	 * SDL_APPACTIVE type event occurs when the application is either
	 * minimised/iconified (gain=0) or restored.
	 *
	 * \note This event does not occur when an application window is first
	 * created.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 gain;
	 *	Uint8 state;
	 * } SDL_ActiveEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_ACTIVEEVENT.
	 * gain	0 if the event is a loss or 1 if it is a gain.
	 * state	SDL_APPMOUSEFOCUS if mouse focus was gained or lost, 
	 * 	SDL_APPINPUTFOCUS if input focus was gained or lost, 
	 * 	or SDL_APPACTIVE if the application was iconified (gain=0) or restored(gain=1).
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_ActiveEvent ActiveEvent;
	/*!
	 * \brief A shorter version of SDL_KeyboardEvent
	 *
	 * SDL_KeyboardEvent is a member of the SDL_Event union and is used when an
	 * event of type SDL_KEYDOWN or SDL_KEYUP is reported.
	 *
	 * The type and state actually report the same information, they just use
	 * different values to do it! A keyboard event occurs when a key is
	 * released (type=SDK_KEYUP or state=SDL_RELEASED) and when a key is
	 * pressed (type=SDL_KEYDOWN or state=SDL_PRESSED). The information on what
	 * key was pressed or released is in the keysym structure.
	 *
	 * \note Repeating SDL_KEYDOWN events will occur if key repeat is enabled
	 * \sa EnableKeyRepeat()
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 state;
	 *	KeySym keysym;
	 * } SDL_KeyboardEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_KEYDOWN or SDL_KEYUP
	 * state	SDL_PRESSED or SDL_RELEASED
	 * keysym	Contains key press information
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_KeyboardEvent KeyboardEvent;
	/*!
	 * \brief A shorter version of SDL_MouseMotionEvent
	 *
	 * SDL_MouseMotionEvent is a member of the SDL_Event union and is used when
	 * an event of type SDL_MOUSEMOTION is reported.
	 *
	 * Simply put, a SDL_MOUSEMOTION type event occurs when a user moves the
	 * mouse within the application window or when WarpMouse() is called. Both
	 * the absolute (x and y) and relative (xrel and yrel) coordinates are
	 * reported along with the current button states (state). The button state
	 * can be interpreted using the SDL_BUTTON macro
	 * \sa GetMouseState()
	 *
	 * If the cursor is hidden (ShowCursor(0)) and the input is grabbed
	 * (SDL::WM::GrabInput(SDL_GRAB_ON)), then the mouse will give relative
	 * motion events even when the cursor reaches the edge fo the screen. This
	 * is currently only implemented on Windows and Linux/Unix-a-likes.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 state;
	 *	Uint16 x, y;
	 *	Sint16 xrel, yrel;
	 * } SDL_MouseMotionEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type		SDL_MOUSEMOTION
	 * state		The current button state
	 * x, y		The X/Y coordinates of the mouse
	 * xrel, yrel	Relative motion in the X/Y direction
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_MouseMotionEvent MouseMotionEvent;
	/*!
	 * \brief A shorter version of SDL_MouseButtonEvent
	 * 
	 * SDL_MouseButtonEvent is a member of the SDL_Event union and is used when
	 * an event of type SDL_MOUSEBUTTONDOWN or SDL_MOUSEBUTTONUP is reported.
	 *
	 * When a mouse button press or release is detected then number of the
	 * button pressed (from 1 to 255, with 1 usually being the left button and
	 * 2 the right) is placed into button, the position of the mouse when this
	 * event occured is stored in the x and the y fields. Like KeyboardEvent,
	 * information on whether the event was a press or a release event is
	 * stored in both the type and state fields, but this should be obvious.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 button;
	 *	Uint8 state;
	 *	Uint16 x, y;
	 * } SDL_MouseButtonEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_MOUSEBUTTONDOWN or SDL_MOUSEBUTTONUP
	 * button	The mouse button index (SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT)
	 * state	SDL_PRESSED or SDL_RELEASED
	 * x, y	The X/Y coordinates of the mouse at press/release time
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_MouseButtonEvent MouseButtonEvent;
	/*!
	 * \brief A shorter version of SDL_JoyAxisEvent
	 *
	 * SDL_JoyAxisEvent is a member of the SDL_Event union and is used when an
	 * event of type SDL_JOYAXISMOTION is reported.
	 *
	 * A SDL_JOYAXISMOTION event occurs when ever a user moves an axis on the
	 * joystick. The field which is the index of the joystick that reported the
	 * event and axis is the index of the axis (for a more detailed
	 * explaination see the Joystick section). value is the current position of
	 * the axis.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 which;
	 *	Uint8 axis;
	 *	Sint16 value;
	 * } SDL_JoyAxisEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_JOYAXISMOTION
	 * which	Joystick device index
	 * axis	Joystick axis index
	 * value	Axis value (range: -32768 to 32767)
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_JoyAxisEvent JoyAxisEvent;
	/*!
	 * \brief A shorter version of SDL_JoyButtonEvent
	 *
	 * SDL_JoyButtonEvent is a member of the SDL_Event union and is used when
	 * an event of type SDL_JOYBUTTONDOWN or SDL_JOYBUTTONUP is reported.
	 *
	 * A SDL_JOYBUTTONDOWN or SDL_JOYBUTTONUP event occurs when ever a user
	 * presses or releases a button on a joystick. The field which is the index
	 * of the joystick that reported the event and button is the index of the
	 * button (for a more detailed explaination see the Joystick section).
	 * state is the current state or the button which is either SDL_PRESSED or
	 * SDL_RELEASED.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 which;
	 *	Uint8 button;
	 *	Uint8 state;
	 * } SDL_JoyButtonEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_JOYBUTTONDOWN or SDL_JOYBUTTONUP
	 * which	Joystick device index
	 * button	Joystick button index
	 * state	SDL_PRESSED or SDL_RELEASED
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_JoyButtonEvent JoyButtonEvent;
	/*!
	 * \brief A shorter version of SDL_JoyHatEvent
	 *
	 * SDL_JoyHatEvent is a member of the SDL_Event union and is used when an
	 * event of type SDL_JOYHATMOTION is reported.
	 *
	 * A SDL_JOYHATMOTION event occurs when ever a user moves a hat on the
	 * joystick. The field which is the index of the joystick that reported the
	 * event and hat is the index of the hat (for a more detailed exlaination
	 * see the Joystick section). value is the current position of the hat. It
	 * is a logically OR'd combination of the following values (whose meanings
	 * should be pretty obvious:) :
	 * \code
	 * SDL_HAT_CENTERED
	 * SDL_HAT_UP
	 * SDL_HAT_RIGHT
	 * SDL_HAT_DOWN
	 * SDL_HAT_LEFT
	 * \endcode
	 * The following defines are also provided:
	 * \code
	 * SDL_HAT_RIGHTUP
	 * SDL_HAT_RIGHTDOWN
	 * SDL_HAT_LEFTUP
	 * SDL_HAT_LEFTDOWN
	 * \endcode
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 which;
	 *	Uint8 hat;
	 *	Uint8 value;
	 * } SDL_JoyHatEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_JOY
	 * which	Joystick device index
	 * hat	Joystick hat index
	 * value	Hat position
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_JoyHatEvent JoyHatEvent;
	/*!
	 * \brief A shorter version of SDL_JoyBallEvent
	 *
	 * SDL_JoyBallEvent is a member of the SDL_Event union and is used when an
	 * event of type SDL_JOYBALLMOTION is reported.
	 *
	 * A SDL_JOYBALLMOTION event occurs when a user moves a trackball on the
	 * joystick. The field which is the index of the joystick that reported the
	 * event and ball is the index of the trackball (for a more detailed
	 * explaination see the Joystick section). Trackballs only return relative
	 * motion, this is the change in position on the ball since it was last
	 * polled (last cycle of the event loop) and it is stored in xrel and yrel.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	Uint8 which;
	 *	Uint8 ball;
	 *	Sint16 xrel, yrel;
	 * } SDL_JoyBallEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type		SDL_JOYBALLMOTION
	 * which		Joystick device index
	 * ball		Joystick trackball index
	 * xrel, yrel	The relative motion in the X/Y direction
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_JoyBallEvent JoyBallEvent;
	/*!
	 * \brief A shorter version of SDL_ResizeEvent
	 *
	 * SDL_ResizeEvent is a member of the SDL_Event union and is used when an
	 * event of type SDL_VIDEORESIZE is reported.
	 *
	 * When SDL_RESIZABLE is passed as a flag to Screen::SetVideoMode() the
	 * user is allowed to resize the applications window. When the window is
	 * resized an SDL_VIDEORESIZE is report, with the new window width and
	 * height values stored in w and h, respectively. When an SDL_VIDEORESIZE
	 * is recieved the window should be resized to the new dimensions using
	 * Screen::SetVideoMode().
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	int w, h;
	 * } SDL_ResizeEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_VIDEORESIZE
	 * w, h	New width and height of the window
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_ResizeEvent ResizeEvent;
	/*!
	 * \brief A shorter version of SDL_ExposeEvent
	 *
	 * SDL_ExposeEvent is a member of the SDL_Event union and is used whan an
	 * event of type SDL_VIDEOEXPOSE is reported.
	 *
	 * A VIDEOEXPOSE event is triggered when the screen has been modified
	 * outside of the application, usually by the window manager and needs to
	 * be redrawn.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type
	 * } SDL_ExposeEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_VIDEOEXPOSE
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_ExposeEvent ExposeEvent;
	/*!
	 * \brief A shorter version of SDL_SysWMEvent
	 *
	 * The system window manager event contains a pointer to system-specific
	 * information about unknown window manager events. If you enable this
	 * event using EventState(), it will be generated whenever unhandled events
	 * are received from the window manager. This can be used, for example, to
	 * implement cut-and-paste in your application.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;	// Always SDL_SYSWMEVENT
	 *	SDL_SysWMmsg *msg;
	 * } SDL_SysWMEvent;
	 * \endcode
	 * If you want to obtain system-specific information about the window
	 * manager, you can fill the version member of a SDL_SysWMinfo structure
	 * (details can be found in SDL_syswm.h, which must be included) using the
	 * SDL_VERSION() macro found in SDL_version.h, and pass it to the function:
	 * int SDL::WM::GetWMInfo(SDL_SysWMinfo *info);
	 */
	typedef SDL_SysWMEvent SysWMEvent;
	
	/*!
	 * \brief A shorter version of SDL_SysWMmsg
	 *
	 */
	typedef SDL_SysWMmsg SysWMmsg;
	/*!
	 * \brief A shorter version of SDL_UserEvent
	 *
	 * SDL_UserEvent is in the user member of the structure SDL_Event. This
	 * event is unique, it is never created by SDL but only by the user. The
	 * event can be pushed onto the event queue using SDL_PushEvent. The
	 * contents of the structure members or completely up to the programmer,
	 * the only requirement is that type is a value from SDL_USEREVENT to
	 * SDL_NUMEVENTS-1 (inclusive).
	 * \b Examples
	 * \code
	 * SDL_Event event;
	 *
	 * event.type = SDL_USEREVENT;
	 * event.user.code = my_event_code;
	 * event.user.data1 = significant_data;
	 * event.user.data2 = 0;
	 * SDL_PushEvent(&event);
	 * \endcode
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type;
	 *	int code;
	 *	void *data1;
	 *	void *data2;
	 * } SDL_UserEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_USEREVENT through to SDL_NUMEVENTS-1
	 * code	User defined event code
	 * data1	User defined data pointer
	 * data2	User defined data pointer
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_UserEvent UserEvent;
	/*!
	 * \brief A shorter version of SDL_QuitEvent
	 *
	 * SDL_QuitEvent is a member of the SDL_Event union and is used whan an
	 * event of type SDL_QUIT is reported.
	 *
	 * As can be seen, the QuitEvent structure serves no useful purpose. The
	 * event itself, on the other hand, is very important. If you filter out or
	 * ignore a quit event then it is impossible for the user to close the
	 * window. On the other hand, if you do accept a quit event then the
	 * application window will be closed, and screen updates will still report
	 * success event though the application will no longer be visible.
	 *
	 * \note The macro SDL_QuitRequested will return non-zero if a quit event
	 * is pending
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 type
	 * } SDL_QuitEvent;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * type	SDL_QUIT
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_QuitEvent QuitEvent;
	/*!
	 * \brief A shorter version of SDL_keysym KeySym
	 *
	 * The SDL_keysym structure is used by reporting key presses and releases
	 * since it is a part of the SDL_KeyboardEvent.
	 *
	 * The scancode field should generally be left alone, it is the hardware
	 * dependent scancode returned by the keyboard. The sym field is extremely
	 * useful. It is the SDL-defined value of the key (see SDL Key Syms. This
	 * field is very useful when you are checking for certain key presses, like
	 * so:
	 * \code
	 * // From inside an inherited Event
	 * .
	 * .
	 * while(SDL_PollEvent(&event))
	 * {
	 *	switch(event.type)
	 *	{
	 *		case SDL_KEYDOWN:
	 *			if(event.key.keysym.sym==SDLK_LEFT)
	 *				move_left();
	 *			break;
	 *		.
	 *		.
	 *		.
	 *	}
	 * }
	 * .
	 * .
	 * \endcode
	 * mod stores the current state of the keyboard modifiers as explained in
	 * GetModState(). The unicode is only used when Unicode translation is
	 * enabled with EnableUnicode(). If unicode is non-zero then this a the
	 * Unicode character corresponding to the keypress. If the high 9 bits of
	 * the character are 0, then this maps to the equivalent ASCII character:
	 * \code
	 * char ch;
	 * if ( (keysym.unicode & 0xFF80) == 0 )
	 * {
	 *	ch = keysym.unicode & 0x7F;
	 * }
	 * else
	 * {
	 *	printf("An International Character.\n");
	 * }
	 * \endcode
	 * Unicode translation does have a slight overhead so don't enable it
	 * unless its needed.
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 scancode;
	 *	Key sym;
	 *	Mod mod;
	 *	Uint16 unicode;
	 * } KeySym;
	 * \endcode
	 * \b Variables:
	 * \htmlonly
	 * <pre>
	 * scancode	Hardware specific scancode
	 * sym		SDL virtual keysym
	 * mod		Current key modifiers
	 * unicode	Translated characte
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_keysym KeySym;
	/*!
	 * \brief A shorter version of SDLKey
	 *
	 * \htmlonly
	 *
<P><B>SDL KeySym definitions</B></P>
<TABLE BORDER="1" CLASS="CALSTABLE">
	<THEAD>
	<TR>
		<TH WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		Key
		</TH>
		<TH WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		ASCII value
		</TH>
		<TH WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		Common name
		</TH>
	</TR>
	</THEAD>
	<TBODY>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_BACKSPACE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'\b'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		backspace
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_TAB
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'\t'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		tab
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_CLEAR
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		clear
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RETURN
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'\r'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		return
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_PAUSE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		pause
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_ESCAPE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'^['
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		escape
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_SPACE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		' '
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		space
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_EXCLAIM
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'!'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		exclaim
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_QUOTEDBL
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'"'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		quotedbl
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_HASH
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'#'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		hash
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_DOLLAR
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'$'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		dollar
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_AMPERSAND
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'&#38;'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		ampersand
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_QUOTE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'''
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		quote
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LEFTPAREN
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'('
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left parenthesis
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RIGHTPAREN
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		')'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right parenthesis
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_ASTERISK
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'*'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		asterisk
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_PLUS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'+'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		plus sign
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_COMMA
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		','
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		comma
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_MINUS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'-'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		minus sign
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_PERIOD
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'.'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		period
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_SLASH
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'/'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		forward slash
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_0
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'0'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		0
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_1
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'1'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		1
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_2
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'2'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		2
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_3
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'3'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		3
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_4
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'4'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		4
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_5
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'5'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		5
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_6
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'6'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		6
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_7
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'7'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		7
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_8
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'8'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		8
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_9
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'9'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		9
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_COLON
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		':'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		colon
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_SEMICOLON
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		';'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		semicolon
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LESS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'&lt;'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		less-than sign
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_EQUALS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'='
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		equals sign
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_GREATER
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'&gt;'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		greater-than sign
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_QUESTION
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'?'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		question mark
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_AT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'@'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		at
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LEFTBRACKET
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'['
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left bracket
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_BACKSLASH
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'\'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		backslash
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RIGHTBRACKET
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		']'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right bracket
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_CARET
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'^'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		caret
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_UNDERSCORE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'_'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		underscore
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_BACKQUOTE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'`'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		grave
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_a
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'a'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		a
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_b
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'b'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		b
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_c
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'c'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		c
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_d
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'd'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		d
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_e
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'e'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		e
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_f
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'f'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		f
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_g
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'g'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		g
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_h
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'h'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		h
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_i
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'i'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		i
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_j
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'j'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		j
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_k
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'k'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		k
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_l
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'l'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		l
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_m
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'm'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		m
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_n
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'n'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		n
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_o
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'o'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		o
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_p
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'p'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		p
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_q
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'q'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		q
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_r
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'r'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		r
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_s
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		's'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		s
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_t
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		't'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		t
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_u
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'u'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		u
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_v
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'v'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		v
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_w
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'w'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		w
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_x
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'x'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		x
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_y
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'y'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		y
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_z
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'z'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		z
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_DELETE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'^?'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		delete
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP0
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 0
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP1
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 1
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP2
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 2
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP3
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 3
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP4
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 4
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP5
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 5
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP6
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 6
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP7
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 7
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP8
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 8
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP9
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad 9
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_PERIOD
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'.'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad period
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_DIVIDE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'/'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad divide
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_MULTIPLY
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'*'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad multiply
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_MINUS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'-'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad minus
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_PLUS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'+'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad plus
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_ENTER
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'\r'
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad enter
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_KP_EQUALS
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		'='
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		keypad equals
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_UP
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		up arrow
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_DOWN
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		down arrow
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RIGHT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right arrow
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LEFT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left arrow
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_INSERT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		insert
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_HOME
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		home
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_END
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		end
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_PAGEUP
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		page up
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_PAGEDOWN
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		page down
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F1
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F1
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F2
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F2
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F3
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F3
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F4
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F4
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F5
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F5
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F6
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F6
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F7
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F7
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F8
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F8
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F9
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F9
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F10
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F10
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F11
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F11
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F12
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F12
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F13
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F13
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F14
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F14
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_F15
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		F15
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_NUMLOCK
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		numlock
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_CAPSLOCK
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		capslock
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_SCROLLOCK
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		scrollock
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RSHIFT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right shift
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LSHIFT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left shift
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RCTRL
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right ctrl
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LCTRL
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left ctrl
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RALT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right alt
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LALT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left alt
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RMETA
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right meta
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LMETA
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left meta
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_LSUPER
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		left windows key
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_RSUPER
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		right windows key
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_MODE
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		mode shift
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_HELP
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		help
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_PRINT
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		print-screen
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_SYSREQ
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SysRq
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_BREAK
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		break
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_MENU
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		menu
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_POWER
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		power
		</TD>
	</TR>
	<TR>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		SDLK_EURO
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		&nbsp;
		</TD>
		<TD WIDTH="33%" ALIGN="LEFT" VALIGN="TOP">
		euro
		</TD>
	</TR>
	</TBODY>
</TABLE>

	 * \endhtmlonly
	 */
	typedef SDLKey Key;
	/*!
	 * \brief A shorter version of SDL_EventFilter
	 *
	 * Defined as:
	 * \code
	 * typedef int (SDLCALL *SDL_EventFilter)(const SDL_Event *event); 
	 * \endcode
	 */
	typedef SDL_EventFilter EventFilter;
	/*!
	 * \brief A shorter version of SDLMod
	 *
	 * \htmlonly
	 * <P><B>SDL modifier definitions</B></P>
	<TABLE BORDER="1" CLASS="CALSTABLE">
	<THEAD>
		<TR>
		<TH WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			SDL Modifier
		</TH>
		<TH WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Meaning
		</TH>
		</TR>
	</THEAD>
	<TBODY>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_NONE
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			No modifiers applicable
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_NUM
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Numlock is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_CAPS
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Capslock is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_LCTRL
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Left Control is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_RCTRL
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Right Control is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_RSHIFT
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Right Shift is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_LSHIFT
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Left Shift is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_RALT
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Right Alt is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_LALT
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			Left Alt is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_CTRL
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			A Control key is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_SHIFT
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			A Shift key is down
		</TD>
		</TR>
		<TR>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			KMOD_ALT
		</TD>
		<TD WIDTH="50%" ALIGN="LEFT" VALIGN="TOP">
			An Alt key is down
		</TD>
		</TR>
	</TBODY>
</TABLE>
	 * \endhtmlonly
	 */
	typedef SDLMod Mod;
	

	/*!
	 * \typedef ActiveEvent
	 */
	/*!
	 * \brief Sets up a filter to process all events before they are posted to the event queue.
	 *
	 * This function sets up a filter to process all events before they are
	 * posted to the event queue. This is a very powerful and flexible feature.
	 * The filter is prototyped as:
	 *
	 * typedef int (*EventFilter)(const SDL_Event *event);
	 *
	 * If the filter returns 1, then the event will be added to the internal
	 * queue. If it returns 0, then the event will be dropped from the queue.
	 * This allows selective filtering of dynamically.
	 *
	 * There is one caveat when dealing with the SDL_QUITEVENT event type. The
	 * event filter is only called when the window manager desires to close the
	 * application window. If the event filter returns 1, then the window will
	 * be closed, otherwise the window will remain open if possible. If the
	 * quit event is generated by an interrupt signal, it will bypass the
	 * internal queue and be delivered to the application at the next event
	 * poll.
	 *
	 * \note Events pushed onto the queue with Event::Push() or Event::Peep()
	 * do not get passed through the event filter.
	 *
	 * \note Be Careful! The event filter function may run in a different
	 * thread so be careful what you do within it.
	 *
	 */
	void SetEventFilter(EventFilter &filter);
	/*!
	 * \brief Retrieves a pointer to he event filter
	 *
	 * This function retrieces a pointer to the event filter that was
	 * previously set using SetEventFilter(). An EventFilter function is
	 * defined as:
	 *
	 * typedef int (*SDL_EventFilter)(const SDL_Event *event);
	 * 
	 * \return
	 */
	EventFilter GetEventFilter(void);
	/*!
	 * \brief This function allows you to set the state of processing certain events.
	 *
	 * This function allows you to set the state of processing certain event
	 * type's.
	 *
	 * If state is set to SDL_IGNORE, that event type will be automatically
	 * dropped from the event queue and will not be filtered.
	 * If state is set to SDL_ENABLE, that event type will be processed
	 * normally.
	 * If state is set to SDL_QUERY, SDL_EventState will return the current
	 * processing state of the specified event type.
	 *
	 * A list of event type's can be found in the Event section.
	 * 
	 * \return
	 */
	Uint8 EventState(Uint8 type, int state);
	/*!
	 * \brief Get a snapshot of the current keyboard state
	 *
	 * Gets a snapshot of the current keyboard state. The current state is
	 * return as a pointer to an array, the size of this array is stored in
	 * numkeys. The array is indexed by the SDLK_* symbols. A value of 1 means
	 * the key is pressed and a value of 0 means its not. The pointer returned
	 * is a pointer to an internal SDL array and should not be freed by the
	 * caller.
	 *
	 * \note Use Event::Pump() to update the state array.
	 * 
	 * \return
	 */
	Uint8* GetKeyState(int *numkeys);
	/*!
	 * \brief Get the state of modifier keys.
	 *
	 * Returns the current state of the modifier keys (CTRL, ALT, etc.).
	 * 
	 * \return The return value can be an OR'd combination of the Mod enum.
	 * 
	 * \b Enum \b Definition
	 * \code 
	 * typedef enum
	 * {
	 * 	KMOD_NONE	= 0x0000,
	 * 	KMOD_LSHIFT= 0x0001,
	 * 	KMOD_RSHIFT= 0x0002,
	 * 	KMOD_LCTRL = 0x0040,
	 * 	KMOD_RCTRL = 0x0080,
	 * 	KMOD_LALT	= 0x0100,
	 * 	KMOD_RALT	= 0x0200,
	 * 	KMOD_LMETA = 0x0400,
	 * 	KMOD_RMETA = 0x0800,
	 * 	KMOD_NUM	= 0x1000,
	 * 	KMOD_CAPS	= 0x2000,
	 * 	KMOD_MODE	= 0x4000,
	 * } Mod;
	 * \endcode
	 *
	 * SDL also defines the following symbols for convenience:
	 * \code
	 * #define KMOD_CTRL (KMOD_LCTRL|KMOD_RCTRL)
	 * #define KMOD_SHIFT	(KMOD_LSHIFT|KMOD_RSHIFT)
	 * #define KMOD_ALT	(KMOD_LALT|KMOD_RALT)
	 * #define KMOD_META (KMOD_LMETA|KMOD_RMETA)
	 * \endcode
	 */
	Mod GetModState(void);
	/*!
	 * \brief Set the current key modifier state
	 *
	 * The inverse of GetModState(), SetModState() allows you to impose
	 * modifier key states on your application.
	 *
	 * Simply pass your desired modifier states into modstate. This value my be
	 * a logical OR'd combination of the following:
	 *
	 * \b Structure \b Definition
	 * \code
	 * typedef enum
	 * {
	 * 	KMOD_NONE	= 0x0000,
	 * 	KMOD_LSHIFT= 0x0001,
	 * 	KMOD_RSHIFT= 0x0002,
	 * 	KMOD_LCTRL = 0x0040,
	 * 	KMOD_RCTRL = 0x0080,
	 * 	KMOD_LALT	= 0x0100,
	 * 	KMOD_RALT	= 0x0200,
	 * 	KMOD_LMETA = 0x0400,
	 * 	KMOD_RMETA = 0x0800,
	 * 	KMOD_NUM	= 0x1000,
	 * 	KMOD_CAPS	= 0x2000,
	 * 	KMOD_MODE	= 0x4000,
	 * } Mod;
	 * \endcode
	 */
	void SetModState(Mod modstate);
	/*!
	 * \brief Get the name of an SDL virtual keysym
	 *
	 * \return Returns the SDL-defined name of the Key key.
	 */
	std::string GetKeyName(Key key);
	/*!
	 * \brief Enable Unicode translation
	 *
	 * Enables/Disables Unicode keyboard translation.
	 *
	 * To obtain the character codes corresponding to received keyboard events,
	 * Unicode translation must first be turned on using this function. The
	 * translation incurs a slight overhead for each keyboard event and is
	 * therefore disabled by default. For each subsequently received key down
	 * event, the unicode member of the KeySym structure will then contain the
	 * corresponding character code, or zero for keysyms that do not correspond
	 * to any character code.
	 *
	 * A value of 1 for enable enables Unicode translation; 0 disables it, and
	 * -1 leaves it unchanged (useful for querying the current translation
	 * mode).
	 *
	 * \note Only key press events will be translated, not release events.
	 *
	 * \return The previous translation mode False for off, True for on.
	 */
	bool EnableUnicode(int enable);
	/*!
	 * \brief Set keyboard repeat rate.
	 *
	 * Enables or disables the keyboard repeat rate. delay specifies how long
	 * the key must be pressed before it begins repeating, it then repeats at
	 * the speed specified by interval. Both delay and interval are expressed
	 * in milliseconds.
	 *
	 * Setting delay to 0 disables key repeating completely. Good default
	 * values are SDL_DEFAULT_REPEAT_DELAY and SDL_DEFAULT_REPEAT_INTERVAL
	 * 
	 * \return True on success and False on failure.
	 */
	bool EnableKeyRepeat(int delay, int interval);
	/*!
	 * \brief Retrieve the current state of the mouse
	 *
	 * The current button state is returned as a button bitmask, which can be
	 * tested using the SDL_BUTTON(X) macros, and x and y are set to the
	 * current mouse cursor position. You can pass NULL for either x or y.
	 * 
	 * \return 
	 */
	Uint8 GetMouseState(int &x, int &y);
	/*!
	 * \brief Retrieve the current state of the mouse
	 *
	 * The current button state is returned as a button bitmask, which can be
	 * tested using the SDL_BUTTON(X) macros, and x and y are set to the change
	 * in the mouse position since the last call to SDL_GetRelativeMouseState
	 * or since event initialization. You can pass NULL for either x or y.
	 *
	 * \return 
	 */
	Uint8 GetRelativeMouseState(int &x, int &y);
	/*!
	 * \brief Get the state of the application.
	 *
	 * \return This function returns the current state of the application. The
	 * value returned is a bitwise combination of:
	 * \code
	 * SDL_APPMOUSEFOCUS	The application has mouse focus.
	 * SDL_APPINPUTFOCUS	The application has keyboard focus
	 * SDL_APPACTIVE	The application is visible
	 * \endcode
	 */
	Uint8 GetAppState(void);
	/*!
	 * \brief Enable/disable joystick event polling
	 *
	 * This function is used to enable or disable joystick event processing.
	 * With joystick event processing disabled you will have to update joystick
	 * states with SDL_JoystickUpdate and read the joystick information
	 * manually. state is either SDL_QUERY, SDL_ENABLE or SDL_IGNORE.
	 *
	 * \note Joystick event handling is prefered
	 *
	 * \return If state is SDL_QUERY then the current state is returned,
	 * otherwise the new processing state is returned.
	 */
	int JoystickState(int state);
	
	/*!
	 * \brief The handler to handle all events.
	 *
	 * This is the handler class for event actions. You'll want to inherit this
	 * class and override any actions you want/need.
	 *
	 * This was taken pretty much directly from SDLmm when I was looking
	 * through their headers getting an idea how it handled events.
	 * So I'm going to say that this class is taken from SDLmm in accordance
	 * with the LGPL, liscened under the LGPL, and is copyrighted 2001 David
	 * Hedbor.
	 *
	 * \b Example
	 * \code
	 * // This will set up a 320x240x32bpp Window and then wait till Escape is
	 * pressed
	 * // Note this isn't the only way to do this, but is one of the simpler
	 * code examples
	 * #include <SDL4Cpp.h>
	 *	
	 * using namespace SDL;
	 *
	 * class MyHandle : public Handle
	 * {
	 * 	public:
	 * 		MyHandle() : m_Quit(false) {}
	 * 		bool KeyPressed(KeySym &keysym)
	 * 		{
	 * 			if(keysym.sym == SDLK_ESCAPE)
	 * 				m_Quit = true;
	 *
	 * 			return true;
	 * 		}
	 *
	 * 		operator bool()
	 * 		{
	 * 			return m_Quit;
	 * 		}
	 * 	private:
	 * 		bool m_Quit;
	 * } myhandler;
	 *
	 * int main()
	 * {
	 * 	Event myevents;
	 * 	Screen screen;
	 *
	 * 	Init(SDL_INIT_VIDEO);
	 *
	 * 	screen.SetVideoMode(320, 240, 8, SDL_SWSURFACE);
	 * 	
	 * 	while(!myhandler)
	 * 		myevents.Poll(myhandler);
	 * 
	 * 	return 0;
	 * }
	 * \endcode
	 */
	class Handle
	{
		public:
			/*!
			 * \brief Default destructor
			 * 
			 * Overrides default destructor to be virtual.
			 */
			virtual ~Handle() {}
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool Active(Uint8 gain, Uint8 state);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool KeyPressed(KeySym &keysym);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool KeyReleased(KeySym &keysym);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool MouseMotion(Uint8 state,	Uint16 x, Uint16 y,
									 Sint16 xrel, Sint16 yrel);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 * 
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool MouseButtonPressed(Uint8 button, Uint16 x, Uint16 y);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool MouseButtonReleased(Uint8 button, Uint16 x, Uint16 y);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool JoyAxis(Uint8 which, Uint8 axis, Sint16 value);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool JoyButtonPressed(Uint8 which, Uint8 button);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool JoyButtonReleased(Uint8 which, Uint8 button);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool JoyHat(Uint8 which, Uint8 hat, Uint8 value);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool JoyBall(Uint8 which, Uint8 ball, Sint16 xrel,
								 Sint16 yrel);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool VideoResize(int w, int h);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool VideoExpose();
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool SysWM(SysWMmsg *msg);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool User(int code, void *data1, void *data2);
			/*!
			 * \brief 
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool Quit();
			/*!
			 * \brief For those who want to do it all the old way.
			 *
			 * Documention not written yet.
			 *
			 * \return false by default, but when implemented, it should return
			 * true
			 */
			virtual bool All(SDL_Event &m_Event);
	};

	/*!
	 * \brief The main class to access SDL's events.
	 * 
	 * Use this to Push, Poll, Peek, Peep, and Wait on events. It also uses
	 * HandleEvent() to handle the events via Handle
	 * \sa Handle for an example on how to use this event structure.
	 */
	class Event
	{
		public:
			/*!
			 * \brief Test all input devices, and updates the queue.
			 *
			 * This is used internally but kept so a user can use them if so
			 * wanted
			 */
			void Pump(void);
			/*!
			 * \brief Peep an event in the event queue.
			 *
			 * This is used internally but kept so a user can use them if so
			 * wanted
			 */
			int Peep(int numevents, SDL_eventaction action, Uint32 mask);

			/*!
			 * These three should be the ones you use the most IMO
			 * Poll and Peek call the approprate handle functions
			 * so to make it do anything useful, you need to inherit Handle and
			 * define the functions you need/want
			 */

			/*!
			 * Automatically pumps then peeps an event of type mask and returns
			 * true if there's that event
			 * \code
			 * SDL_ACTIVEEVENTMASK		=	SDL_EVENTMASK(SDL_ACTIVEEVENT)
			 * SDL_KEYDOWNMASK		=	SDL_EVENTMASK(SDL_KEYDOWN)
			 * SDL_KEYUPMASK			=	SDL_EVENTMASK(SDL_KEYUP)
			 * SDL_MOUSEMOTIONMASK		=	SDL_EVENTMASK(SDL_MOUSEMOTION)
			 * SDL_MOUSEBUTTONDOWNMASK	=	SDL_EVENTMASK(SDL_MOUSEBUTTONDOWN)
			 * SDL_MOUSEBUTTONUPMASK		=	SDL_EVENTMASK(SDL_MOUSEBUTTONUP)
			 * SDL_MOUSEEVENTMASK		=	SDL_EVENTMASK(SDL_MOUSEMOTION)
			 * 				|	SDL_EVENTMASK(SDL_MOUSEBUTTONDOWN)
			 * 				|	SDL_EVENTMASK(SDL_MOUSEBUTTONUP)
			 * SDL_JOYAXISMOTIONMASK		=	SDL_EVENTMASK(SDL_JOYAXISMOTION)
			 * SDL_JOYBALLMOTIONMASK		=	SDL_EVENTMASK(SDL_JOYBALLMOTION)
			 * SDL_JOYHATMOTIONMASK		=	SDL_EVENTMASK(SDL_JOYHATMOTION)
			 * SDL_JOYBUTTONDOWNMASK		=	SDL_EVENTMASK(SDL_JOYBUTTONDOWN)
			 * SDL_JOYBUTTONUPMASK		=	SDL_EVENTMASK(SDL_JOYBUTTONUP)
			 * SDL_JOYEVENTMASK		=	SDL_EVENTMASK(SDL_JOYAXISMOTION)
			 * 				|	SDL_EVENTMASK(SDL_JOYBALLMOTION)
			 * 				|	SDL_EVENTMASK(SDL_JOYHATMOTION)
			 * 				|	SDL_EVENTMASK(SDL_JOYBUTTONDOWN)
			 * 				|	SDL_EVENTMASK(SDL_JOYBUTTONUP)
			 * SDL_VIDEORESIZEMASK		=	SDL_EVENTMASK(SDL_VIDEORESIZE)
			 * SDL_VIDEOEXPOSEMASK		=	SDL_EVENTMASK(SDL_VIDEOEXPOSE)
			 * SDL_QUITMASK			=	SDL_EVENTMASK(SDL_QUIT)
			 * SDL_SYSWMEVENTMASK		=	SDL_EVENTMASK(SDL_SYSWMEVENT)
			 * \endcode
			 */
			bool Peek(Handle &handler, Uint32 mask = 0);
			/*!
			 * Documention not written yet.
			 */
			bool PeekActive(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekKeyPressed(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekKeyReleased(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekMouseMotion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekMouseButtonDown(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekMouseButtonUp(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekMouse(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekJoyAxisMontion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekJoyBallMotion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekJoyHatMotion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekJoyButtonDown(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekJoyButtonUp(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekJoy(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekVideoResize(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekVideoExpose(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekQuit(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PeekSysWM(Handle &handler);
			
			/*!
			 * Wait indefinatly for an event
			 */
			bool Wait();

			/*!
			 * Documention not written yet.
			 */
			int Pop(Handle &handler, Uint32 mask);
			/*!
			 * Documention not written yet.
			 */
			bool PopActive(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopKeyPressed(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopKeyReleased(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopMouseMotion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopMouseButtonDown(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopMouseButtonUp(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopMouse(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopJoyAxisMontion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopJoyBallMotion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopJoyHatMotion(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopJoyButtonDown(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopJoyButtonUp(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopJoy(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopVideoResize(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopVideoExpose(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopQuit(Handle &handler);
			/*!
			 * Documention not written yet.
			 */
			bool PopSysWM(Handle &handler);

			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(ActiveEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(KeyboardEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(MouseMotionEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(MouseButtonEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(JoyAxisEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(JoyButtonEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(JoyHatEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(JoyBallEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(ResizeEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(ExposeEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(SysWMEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(UserEvent &event);
			/*!
			 * push this user defined event onto the queue
			 */
			bool Push(QuitEvent &event);

			/*!
			 * See if an event is on the queue, remove it, and handle it
			 */
			void Poll(Handle &handler);
		protected:
			/*!
			 * \brief The event structure used by SDL.
			 *
			 * \b Structure \b Definition
			 * \code
			 * typedef union
			 * {
			 * 	Uint8 type;
			 * 	SDL_ActiveEvent active;
			 * 	SDL_KeyboardEvent key;
			 * 	SDL_MouseMotionEvent motion;
			 * 	SDL_MouseButtonEvent button;
			 * 	SDL_JoyAxisEvent jaxis;
			 * 	SDL_JoyBallEvent jball;
			 * 	SDL_JoyHatEvent jhat;
			 * 	SDL_JoyButtonEvent jbutton;
			 * 	SDL_ResizeEvent resize;
			 * 	SDL_ExposeEvent expose;
			 * 	SDL_QuitEvent quit;
			 * 	SDL_UserEvent user;
			 * 	SDL_SywWMEvent syswm;
			 * } SDL_Event;
			 * \endcode
			 */
			SDL_Event m_Event;
			/*!
			 * Handles events
			 */
			bool HandleEvents(Handle &handler);
	};
	//@}
}

#endif

