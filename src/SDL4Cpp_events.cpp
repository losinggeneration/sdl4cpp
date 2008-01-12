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

#include "SDL4Cpp_events.h"

namespace SDL
{
	void SetEventFilter(EventFilter filter)
	{
		SDL_SetEventFilter(filter);
	}
	
	EventFilter GetEventFilter(void)
	{
		return SDL_GetEventFilter();
	}
	
	Uint8 EventState(Uint8 type, int state)
	{
		return SDL_EventState(type, state);
	}
	
	Uint8 *GetKeyState(int *numkeys)
	{
		return SDL_GetKeyState(numkeys);
	}
	
	Mod GetModState(void)
	{
		return SDL_GetModState();
	}
	
	void SetModState(Mod modstate)
	{
		SDL_SetModState(modstate);
	}
	
	std::string GetKeyName(Key key)
	{
		return static_cast<std::string>(SDL_GetKeyName(key));
	}
	
	bool EnableUnicode(int enable)
	{
		return SDL_EnableUNICODE(enable);
	}
	
	bool EnableKeyRepeat(int delay, int interval)
	{
		if(SDL_EnableKeyRepeat(delay, interval) == 0)
			return true;
		else
			return false;
	}

	Uint8 GetMouseState(int &x, int &y)
	{
		return SDL_GetMouseState(&x, &y);
	}
	
	Uint8 GetRelativeMouseState(int &x, int &y)
	{
		return SDL_GetRelativeMouseState(&x, &y);
	}
	
	Uint8 GetAppState(void)
	{
		return SDL_GetAppState();
	}
	
	int JoystickState(int state)
	{
		return SDL_JoystickEventState(state);
	}
	

	bool Handle::Active(Uint8 gain, Uint8 state)
	{
		return false;
	}

	bool Handle::KeyPressed(KeySym &keysym)
	{
		return false;
	}
	
	bool Handle::KeyReleased(KeySym &keysym)
	{
		return false;
	}
	
	bool Handle::MouseMotion(Uint8 state, Uint16 x, Uint16 y, Sint16 xrel, Sint16 yrel)
	{
		return false;
	}
	
	bool Handle::MouseButtonPressed(Uint8 button, Uint16 x, Uint16 y)
	{
		return false;
	}
	
	bool Handle::MouseButtonReleased(Uint8 button, Uint16 x, Uint16 y)
	{
		return false;
	}
	
	bool Handle::JoyAxis(Uint8 which, Uint8 axis, Sint16 value)
	{
		return false;
	}
	
	bool Handle::JoyButtonPressed(Uint8 which, Uint8 button)
	{
		return false;
	}
	
	bool Handle::JoyButtonReleased(Uint8 which, Uint8 button)
	{
		return false;
	}
	
	bool Handle::JoyHat(Uint8 which, Uint8 hat, Uint8 value)
	{
		return false;
	}
	
	bool Handle::JoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
	{
		return false;
	}
	
	bool Handle::VideoResize(int w, int h)
	{
		return false;
	}
	
	bool Handle::VideoExpose()
	{
		return false;
	}
	
	bool Handle::SysWM(SysWMmsg *msg)
	{
		return false;
	}
	
	bool Handle::User(int code, void *data1, void *data2)
	{
		return false;
	}
	
	bool Handle::Quit()
	{
		return false;
	}

	bool Handle::All(SDL_Event &event)
	{
		return false;
	}

	void Event::Pump(void)
	{
		SDL_PumpEvents();
	}
	
	int Event::Peep(int numevents, SDL_eventaction action, Uint32 mask)
	{
		return SDL_PeepEvents(&m_Event, numevents, action, mask);
	}
	
	int Event::Pop(Handle &handler, Uint32 mask)
	{
		int isEvent;

		Pump();
		isEvent = Peep(1, SDL_GETEVENT, mask);

		if(isEvent == 1)
			HandleEvents(handler);

		return isEvent;

	}
	
	bool Event::PopActive(Handle &handler)
	{
		return Pop(handler, SDL_ACTIVEEVENTMASK);
	}

	bool Event::PopKeyPressed(Handle &handler)
	{
		return Pop(handler, SDL_KEYDOWNMASK);
	}

	bool Event::PopKeyReleased(Handle &handler)
	{
		return Pop(handler, SDL_KEYUPMASK);
	}

	bool Event::PopMouseMotion(Handle &handler)
	{
		return Pop(handler, SDL_MOUSEMOTIONMASK);
	}

	bool Event::PopMouseButtonDown(Handle &handler)
	{
		return Pop(handler, SDL_MOUSEBUTTONDOWNMASK);
	}

	bool Event::PopMouseButtonUp(Handle &handler)
	{
		return Pop(handler, SDL_MOUSEBUTTONUPMASK);
	}

	bool Event::PopMouse(Handle &handler)
	{
		return Pop(handler, SDL_MOUSEEVENTMASK);
	}

	bool Event::PopJoyAxisMontion(Handle &handler)
	{
		return Pop(handler, SDL_JOYAXISMOTIONMASK);
	}

	bool Event::PopJoyBallMotion(Handle &handler)
	{
		return Pop(handler, SDL_JOYBALLMOTIONMASK);
	}

	bool Event::PopJoyHatMotion(Handle &handler)
	{
		return Pop(handler, SDL_JOYHATMOTIONMASK);
	}

	bool Event::PopJoyButtonDown(Handle &handler)
	{
		return Pop(handler, SDL_JOYBUTTONDOWNMASK);
	}

	bool Event::PopJoyButtonUp(Handle &handler)
	{
		return Pop(handler, SDL_JOYBUTTONUPMASK);
	}

	bool Event::PopJoy(Handle &handler)
	{
		return Pop(handler, SDL_JOYEVENTMASK);
	}

	bool Event::PopVideoResize(Handle &handler)
	{
		return Pop(handler, SDL_VIDEORESIZEMASK);
	}
	
	bool Event::PopVideoExpose(Handle &handler)
	{
		return Pop(handler, SDL_VIDEOEXPOSEMASK);
	}
	
	bool Event::PopQuit(Handle &handler)
	{
		return Pop(handler, SDL_QUITMASK);
	}

	bool Event::PopSysWM(Handle &handler)
	{
		return Pop(handler, SDL_SYSWMEVENTMASK);
	}
	
	bool Event::Wait()
	{
		return SDL_WaitEvent(&m_Event);
	}
	
	bool Event::Peek(Handle &handler, Uint32 mask)
	{
		int isEvent;

		Pump();
		isEvent = Peep(1, SDL_PEEKEVENT, mask);

		if(isEvent == 1)
			HandleEvents(handler);

		return isEvent;
	}

	bool Event::PeekActive(Handle &handler)
	{
		return Peek(handler, SDL_ACTIVEEVENTMASK);
	}

	bool Event::PeekKeyPressed(Handle &handler)
	{
		return Peek(handler, SDL_KEYDOWNMASK);
	}

	bool Event::PeekKeyReleased(Handle &handler)
	{
		return Peek(handler, SDL_KEYUPMASK);
	}

	bool Event::PeekMouseMotion(Handle &handler)
	{
		return Peek(handler, SDL_MOUSEMOTIONMASK);
	}

	bool Event::PeekMouseButtonDown(Handle &handler)
	{
		return Peek(handler, SDL_MOUSEBUTTONDOWNMASK);
	}

	bool Event::PeekMouseButtonUp(Handle &handler)
	{
		return Peek(handler, SDL_MOUSEBUTTONUPMASK);
	}

	bool Event::PeekMouse(Handle &handler)
	{
		return Peek(handler, SDL_MOUSEEVENTMASK);
	}

	bool Event::PeekJoyAxisMontion(Handle &handler)
	{
		return Peek(handler, SDL_JOYAXISMOTIONMASK);
	}

	bool Event::PeekJoyBallMotion(Handle &handler)
	{
		return Peek(handler, SDL_JOYBALLMOTIONMASK);
	}

	bool Event::PeekJoyHatMotion(Handle &handler)
	{
		return Peek(handler, SDL_JOYHATMOTIONMASK);
	}

	bool Event::PeekJoyButtonDown(Handle &handler)
	{
		return Peek(handler, SDL_JOYBUTTONDOWNMASK);
	}

	bool Event::PeekJoyButtonUp(Handle &handler)
	{
		return Peek(handler, SDL_JOYBUTTONUPMASK);
	}

	bool Event::PeekJoy(Handle &handler)
	{
		return Peek(handler, SDL_JOYEVENTMASK);
	}

	bool Event::PeekVideoResize(Handle &handler)
	{
		return Peek(handler, SDL_VIDEORESIZEMASK);
	}
	
	bool Event::PeekVideoExpose(Handle &handler)
	{
		return Peek(handler, SDL_VIDEOEXPOSEMASK);
	}
	
	bool Event::PeekQuit(Handle &handler)
	{
		return Peek(handler, SDL_QUITMASK);
	}

	bool Event::PeekSysWM(Handle &handler)
	{
		return Peek(handler, SDL_SYSWMEVENTMASK);
	}
	
	bool Event::Push(ActiveEvent &event)
	{
		m_Event.active = event;

		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(KeyboardEvent &event)
	{
		m_Event.key = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(MouseMotionEvent &event)
	{
		m_Event.motion = event;

		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(MouseButtonEvent &event)
	{
		m_Event.button = event;

		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(JoyAxisEvent &event)
	{
		m_Event.jaxis = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(JoyButtonEvent &event)
	{
		m_Event.jbutton = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(JoyHatEvent &event)
	{
		m_Event.jhat = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(JoyBallEvent &event)
	{
		m_Event.jball = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(ResizeEvent &event)
	{
		m_Event.resize = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(ExposeEvent &event)
	{
		m_Event.expose = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(SysWMEvent &event)
	{
		m_Event.syswm = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(UserEvent &event)
	{
		m_Event.user = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	bool Event::Push(QuitEvent &event)
	{
		m_Event.quit = event;
		
		if(SDL_PushEvent(&m_Event) == 0)
			return true;
		else
			return false;
	}
	
	void Event::Poll(Handle &handler)
	{
		while(SDL_PollEvent(&m_Event))
		{
			if(!HandleEvents(handler))
				handler.All(m_Event);
		}
	}
	
	bool Event::HandleEvents(Handle &handler)
	{
		bool handled = false;

		switch(m_Event.type)
		{
			case SDL_ACTIVEEVENT:
				handled = handler.Active(m_Event.active.gain, m_Event.active.state);
				break;
			case SDL_KEYDOWN:
				handled = handler.KeyPressed(m_Event.key.keysym);
				break;
			case SDL_KEYUP:
				handled = handler.KeyReleased(m_Event.key.keysym);
				break;
			case SDL_MOUSEMOTION:
				handled = handler.MouseMotion(m_Event.motion.state, m_Event.motion.x, m_Event.motion.y, m_Event.motion.xrel, m_Event.motion.yrel);
				break;
			case SDL_MOUSEBUTTONDOWN:
				handled = handler.MouseButtonPressed(m_Event.button.button, m_Event.button.x, m_Event.button.y);
				break;
			case SDL_MOUSEBUTTONUP:
				handled = handler.MouseButtonReleased(m_Event.button.button, m_Event.button.x, m_Event.button.y);
				break;
			case SDL_JOYAXISMOTION:
				handled = handler.JoyAxis(m_Event.jaxis.which, m_Event.jaxis.axis, m_Event.jaxis.value);
				break;
			case SDL_JOYBALLMOTION:
				handled = handler.JoyBall(m_Event.jball.which, m_Event.jball.ball, m_Event.jball.xrel, m_Event.jball.yrel);
				break;
			case SDL_JOYHATMOTION:
				handled = handler.JoyHat(m_Event.jhat.which, m_Event.jhat.hat, m_Event.jhat.value);
				break;
			case SDL_JOYBUTTONDOWN:
				handled = handler.JoyButtonPressed(m_Event.jbutton.which, m_Event.jbutton.button);
				break;
			case SDL_JOYBUTTONUP:
				handled = handler.JoyButtonReleased(m_Event.jbutton.which, m_Event.jbutton.button);
				break;
			case SDL_QUIT:
				handled = handler.Quit();
				break;
			case SDL_SYSWMEVENT:
				handled = handler.SysWM(m_Event.syswm.msg);
				break;
			case SDL_VIDEORESIZE:
				handled = handler.VideoResize(m_Event.resize.w, m_Event.resize.h);
				break;
			case SDL_VIDEOEXPOSE:
				handled = handler.VideoExpose();
				break;
			case SDL_USEREVENT:
				handled = handler.User(m_Event.user.code, m_Event.user.data1, m_Event.user.data2);
				break;
		}

		return handled;
	}
}

