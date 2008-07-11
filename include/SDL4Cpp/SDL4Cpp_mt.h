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

#ifndef SDL4CPP_MT_H
#define SDL4CPP_MT_H

#include "SDL_thread.h"


namespace SDL
{
	/*!
	 * \defgroup MT Multi-Thread handling functions.
	 */
	//@{
	/*!
	 *  \brief SDL Multi-Thread will most likely not be wrapped into a class.
	 *
	 * Because of many C-isms that the multi-thread portion of SDL uses makes
	 * it hard to cleanly wrap it into a \b class. I will work on this though.
	 *
	 * SDL provides functions for creating threads, mutexes, semphores and
	 * condition variables.
	 *
	 * In general, you must be very aware of concurrency and data integrity
	 * issues when writing multi-threaded programs. Some good guidelines
	 * include:
	 *	Don't call SDL video/event functions from separate threads
	 *	Don't use any library functions in separate threads
	 *	Don't perform any memory management in separate threads
	 *	Lock global variables which may be accessed by multiple threads
	 *	Never terminate threads, always set a flag and wait for them to quit
	 *	Think very carefully about all possible ways your code may interact
	 * \note SDL's threading is not implemented on MacOS, due to that lack of
	 * preemptive thread support (MacOS X dosn't suffer from this problem)
	*/
	namespace MT
	{
		/*!
		 * Used to shorten SDL_Thread
		 *
		 * \b Structure \b Definition
		 * \code
		 * struct Thread
		 * {
		 *	Uint32 threadid;
		 *	SYS_ThreadHandle handle;
		 *	int status;
		 *	error errbuf;
		 *	void *data;
		 * };
		 * \endcode
		 */
		typedef SDL_Thread Thread;

		/*!
		 * Used to shorten SDL_mutex
		 *
		 * \b Structure \b Definition
		 * Taken from SDL-1.2.9/src/thread/generic/SDL_sysmutex.c
		 * \code
		 * struct SDL_mutex
		 * {
		 *	int recursive;
		 *	Uint32 owner;
		 *	SDL_sem *sem;
		 * };
		 * \endcode
		 */
		typedef SDL_mutex Mutex;

		/*!
		 * Used to shorten SDL_sem
		 *
		 * \b Structure \b Definition
		 * Taken from SDL-1.2.9/src/thread/generic/SDL_syssem.c
		 * \code
		 * struct SDL_semaphore
		 * {
		 *	Uint32 count;
		 *	Uint32 waiters_count;
		 *	SDL_mutex *count_lock;
		 *	SDL_cond *count_nonzero;
		 * };
		 * \endcode
		 */
		typedef SDL_sem Sem;

		/*!
		 * Used to shorten SDL_cond
		 *
		 * \b Structure \b Definition
		 * Taken from SDL-1.2.9/src/thread/generic/SDL_syscond.c
		 * \code
		 * struct SDL_cond
		 * {
		 *	SDL_mutex *lock;
		 *	int waiting;
		 *	int signals;
		 *	SDL_sem *wait_sem;
		 *	SDL_sem *wait_done;
		 * };
		 * \endcode
		 */
		typedef SDL_cond Cond;

		/*!
		 * CreateThread creates a new thread of execution that shares all of
		 * its parent's global memory, signal handlers, file descriptors, etc,
		 * and runs the function fn passed the void pointer data The thread
		 * quits when this function returns.
		 */
		Thread *CreateThread(int (*fn)(void *), void *data);
		/*!
		 * Get the 32-bit thread identifier for the current thread.
		 */
		Uint32 ThreadID(void);
		/*!
		 * Get the SDL thread ID of a Thread
		 * Returns the ID of a Thread created by CreateThread.
		 * CreateThread
		 */
		Uint32 GetThreadID(Thread *thread);
		/*!
		 *  Wait for a thread to finish.
		 *  Wait for a thread to finish (timeouts are not supported).
		 *  \return The return code for the thread function is placed in the
		 * area pointed to by status, if status is not NULL.
		 */
		void WaitThread(Thread *thread, int &status);
		/*!
		 * Gracelessly terminates the thread.
		 *
		 * KillThread gracelessly terminates the thread associated with
		 * thread. If possible, you should use some other form of IPC to
		 * signal the thread to quit.
		 * \sa CreateThread, WaitThread
		 */
		void KillThread(Thread *thread);
		/*!
		 * Create a new, unlocked mutex.
		 *
		 * Examples
		 * \code
		 * Mutex *mut;
		 * mut=CreateMutex();
		 * ..
		 * if(MutexP(mut)==-1)
		 * {
		 *	fprintf(stderr, "Couldn't lock mutex\n");
		 *	exit(-1);
		 * }
		 * ..
		 * // Do stuff while mutex is locked
		 * ..
		 * ..
		 * if(MutexV(mut)==-1)
		 * {
		 *	fprintf(stderr, "Couldn't unlock mutex\n");
		 *	exit(-1);
		 * }
		 *
		 * DestroyMutex(mut);
		 * \endcode
		 * \sa MutexP, MutexV, DestroyMutex
		 */
		Mutex *CreateMutex(void);
		/*!
		 * Destroy a previously created mutex.
		 * \sa CreateMutex
		 */
		void DestroyMutex(Mutex *mutex);
		/*!
		 * Locks the mutex, which was previously created with CreateMutex. If
		 * the mutex is already locked then MutexP will not return until it is
		 * unlocked.
		 *
		 * SDL also defines a macro
		 * \code
		 * #define LockMutex(m) MutexP(m).
		 * \endcode
		 *
		 * \return Returns 0 on success, or -1 on an error.
		 * \sa CreateMutex, MutexV
		 */
		int MutexP(Mutex *mutex);
		/*!
		 * Unlocks the mutex, which was previously created with CreateMutex.
		 * Returns 0 on success, or -1 on an error.
		 *
		 * SDL also defines a macro
		 * \code
		 * #define UnlockMutex(m) MutexV(m).
		 * \endcode
		 * \sa CreateMutex, MutexP
		 */
		int MutexV(Mutex *mutex);
		/*!
		 * \short Creates a new semaphore and assigns an initial value to it.
		 *
		 * CreateSemaphore() creates a new semaphore and initializes it with
		 * the value initial_value. Each locking operation on the semaphore by
		 * SemWait, SemTryWait or SemWaitTimeout will atomically decrement the
		 * semaphore value. The locking operation will be blocked if the
		 * semaphore value is not positive (greater than zero). Each unlock
		 * operation by SemPost will atomically increment the semaphore value.
		 *
		 * Examples
		 * \code
		 * sem *my_sem;
		 * my_sem = CreateSemaphore(INITIAL_SEM_VALUE);
		 * if (my_sem == NULL)
		 * {
		 *	return CREATE_SEM_FAILED;
		 * }
		 * \endcode
		 *
		 * \return a pointer to an initialized semaphore or NULL if there was
		 * an error.
		 * \sa DestroySemaphore, SemWait, SemTryWait, SemWaitTimeout, SemPost,
		 * SemValue
		 */
		Sem *CreateSemaphore(Uint32 initial_value);
		/*!
		 * DestroySemaphore destroys the semaphore pointed to by sem that was
		 * created by CreateSemaphore. It is not safe to destroy a semaphore
		 * if there are threads currently blocked waiting on it.
		 *
		 * Examples
		 * \code
		 * if (my_sem != NULL)
		 * {
		 *	DestroySemaphore(my_sem);
		 *	my_sem = NULL;
		 * }
		 * \endcode
		 * \sa CreateSemaphore, SemWait, SemTryWait, SemWaitTimeout, SemPost,
		 * SemValue
		 */
		void DestroySemaphore(Sem *sem);
		/*!
		 * SemWait() suspends the calling thread until either the semaphore
		 * pointed to by sem has a positive value, the call is interrupted by
		 * a signal or error. If the call is successful it will atomically
		 * decrement the semaphore value.
		 *
		 * After SemWait() is successful, the semaphore can be released and
		 * its count atomically incremented by a successful call to SemPost.
		 *
		 * \return 0 if successful or -1 if there was an error (leaving the
		 * semaphore unchanged).
		 *
		 * Examples
		 * \code
		 * if (SemWait(my_sem) == -1)
		 * {
		 *	return WAIT_FAILED;
		 * }
		 *
		 * ...
		 *
		 * SemPost(my_sem);
		 * \endcode
		 * \sa CreateSemaphore, DestroySemaphore, SemTryWait, SemWaitTimeout,
		 * SemPost, SemValue
		 */
		int SemWait(Sem *sem);
		/*!
		 * SemTryWait is a non-blocking varient of SemWait. If the value of
		 * the semaphore pointed to by sem is positive it will atomically
		 * decrement the semaphore value and return 0, otherwise it will
		 * return MUTEX_TIMEDOUT instead of suspending the thread.
		 *
		 * After SemTryWait is successful, the semaphore can be released and
		 * its count atomically incremented by a successful call to SemPost.
		 *
		 * If the semaphore was not successfully locked, the semaphore will be
		 * unchanged.
		 *
		 * Examples
		 * \code
		 * res = SemTryWait(my_sem);
		 * if (res == MUTEX_TIMEDOUT) {
		 *        return TRY_AGAIN;
		 * }
		 *
		 * if (res == -1) {
		 *         return WAIT_ERROR;
		 * }
		 *
		 * ...
		 *
		 * SemPost(my_sem);
		 * \endcode
		 *
		 * \return 0 if the semaphore was successfully locked or either
		 * MUTEX_TIMEDOUT or -1 if the thread would have suspended or there
		 * was an error, respectivly.
		 * \sa CreateSemaphore, DestroySemaphore, SemWait, SemWaitTimeout,
		 * SemPost, SemValue
		 */
		int SemTryWait(Sem *sem);
		/*!
		 * SemWaitTimeout() is a varient of SemWait with a maximum timeout
		 * value. If the value of the semaphore pointed to by sem is positive
		 * (greater than zero) it will atomically decrement the semaphore
		 * value and return 0, otherwise it will wait up to timeout
		 * milliseconds trying to lock the semaphore. This function is to be
		 * avoided if possible since on some platforms it is implemented by
		 * polling the semaphore every millisecond in a busy loop.
		 *
		 * After SemWaitTimeout() is successful, the semaphore can be released
		 * and its count atomically incremented by a successful call to
		 * SemPost.
		 *
		 * If the semaphore was not successfully locked, the semaphore will be
		 * unchanged.
		 *
		 * Examples
		 * \code
		 * res = SemWaitTimeout(my_sem, WAIT_TIMEOUT_MILLISEC);
		 * if (res == MUTEX_TIMEDOUT) {
		 * return TRY_AGAIN;
		 * }
		 * if (res == -1) {
		 * return WAIT_ERROR;
		 * }
		 * ...
		 * SemPost(my_sem);
		 * \endcode
		 *
		 * \return 0 if the semaphore was successfully locked or either
		 * MUTEX_TIMEDOUT or -1 if the timeout period was exceeded or there
		 * was an error, respectivly.
		 * \sa CreateSemaphore, DestroySemaphore, SemWait, SemTryWait,
		 * SemPost, SemValue
		 */
		int SemWaitTimeout(Sem *sem, Uint32 timeout);
		/*!
		 * SemPost unlocks the semaphore pointed to by sem and atomically
		 * increments the semaphores value. Threads that were blocking on the
		 * semaphore may be scheduled after this call succeeds.
		 *
		 * SemPost should be called after a semaphore is locked by a
		 * successful call to SemWait, SemTryWait or SemWaitTimeout.
		 *
		 * Examples
		 * \code
		 * SemPost(my_sem);
		 * \endcode
		 *
		 * \return 0 if successful or -1 if there was an error (leaving the
		 * semaphore unchanged).
		 * \sa CreateSemaphore, DestroySemaphore, SemWait, SemTryWait,
		 * SemWaitTimeout, SemValue
		 */
		int SemPost(Sem *sem);
		/*!
		 * SemValue() returns the current semaphore value from the semaphore
		 * pointed to by sem.
		 *
		 * Examples
		 * \code
		 * sem_value = SemValue(my_sem);
		 * \endcode
		 *
		 * \return current value of the semaphore.
		 * \sa CreateSemaphore, DestroySemaphore, SemWait, SemTryWait,
		 * SemWaitTimeout, SemPost
		 */
		Uint32 SemValue(Sem *sem);
		/*!
		 * Creates a condition variable.
		 *
		 * Examples
		 * \code
		 * cond *cond;
		 *
		 * cond=CreateCond();
		 * .
		 * .
		 * // Do stuff
		 *
		 * .
		 * .
		 * DestroyCond(cond);
		 * \endcode
		 * \sa DestroyCond, CondWait,
		 */
		Cond *CreateCond(void);
		/*!
		 * Destroys a condition variable.
		 */
		void DestroyCond(Cond *cond);
		/*!
		 * Restart one of the threads that are waiting on the condition
		 * variable, cond. Returns 0 on success of -1 on an error.
		 * \sa CondWait, CondBroadcast
		 */
		int CondSignal(Cond *cond);
		/*!
		 * Restarts all threads that are waiting on the condition variable,
		 * cond. Returns 0 on success, or -1 on an error.
		 * \sa CondSignal, CondWait
		 */
		int CondBroadcast(Cond *cond);
		/*!
		 * Wait on the condition variable cond and unlock the provided mutex.
		 * The mutex must the locked before entering this function. Returns 0
		 * when it is signalled, or -1 on an error.
		 * \sa CondWaitTimeout, CondSignal, MutexP
		 */
		int CondWait(Cond *cond, Mutex *mutex);
		/*!
		 * Wait on the condition variable cond for, at most, ms milliseconds.
		 * mut is unlocked so it must be locked when the function is called.
		 * Returns MUTEX_TIMEDOUT if the condition is not signalled in the
		 * allotted time, 0 if it was signalled or -1 on an error.
		 * \sa CondWait
		 */
		int CondWaitTimeout(Cond *cond, Mutex *mutex, Uint32 ms);

	}
	//@}
}

#endif

