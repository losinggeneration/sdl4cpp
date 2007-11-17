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

#include "SDL4Cpp_mt.h"

namespace SDL
{
	namespace MT
	{
		Thread *CreateThread(int (*fn)(void *), void *data)
		{
			return SDL_CreateThread(fn, data);
		}
		
		Uint32 ThreadID(void)
		{
			return SDL_ThreadID();
		}
		
		Uint32 GetThreadID(Thread *thread)
		{
			return SDL_GetThreadID(thread);
		}
		
		void WaitThread(Thread *thread, int *status)
		{
			SDL_WaitThread(thread, status);
		}
		
		void KillThread(Thread *thread)
		{
			SDL_KillThread(thread);
		}
		
		Mutex *CreateMutex(void)
		{
			return SDL_CreateMutex();
		}
		
		void DestroyMutex(Mutex *mutex)
		{
			SDL_DestroyMutex(mutex);
		}
		
		int MutexP(Mutex *mutex)
		{
			return SDL_mutexP(mutex);
		}
	
		int MutexV(Mutex *mutex)
		{
			return SDL_mutexV(mutex);
		}
	
		Sem *CreateSemaphore(Uint32 initial_value)
		{
			return SDL_CreateSemaphore(initial_value);
		}
	
		void DestroySemaphore(Sem *sem)
		{
			SDL_DestroySemaphore(sem);
		}
	
		int SemWait(Sem *sem)
		{
			return SDL_SemWait(sem);
		}
	
		int SemTryWait(Sem *sem)
		{
			return SDL_SemTryWait(sem);
		}
	
		int SemWaitTimeout(Sem *sem, Uint32 timeout)
		{
			return SDL_SemWaitTimeout(sem, timeout);
		}
	
		int SemPost(Sem *sem)
		{
			return SDL_SemPost(sem);
		}
	
		Uint32 SemValue(Sem *sem)
		{
			return SDL_SemValue(sem);
		}
	
		Cond *CreateCond(void)
		{
			return SDL_CreateCond();
		}
	
		void DestroyCond(Cond *cond)
		{
			SDL_DestroyCond(cond);
		}
	
		int CondSignal(Cond *cond)
		{
			return SDL_CondSignal(cond);
		}
	
		int CondBroadcast(Cond *cond)
		{
			return SDL_CondBroadcast(cond);
		}
	
		int CondWait(Cond *cond, Mutex *mutex)
		{
			return SDL_CondWait(cond, mutex);
		}
	
		int CondWaitTimeout(Cond *cond, Mutex *mutex, Uint32 ms)
		{
			return SDL_CondWaitTimeout(cond, mutex, ms);
		}
	}
}

