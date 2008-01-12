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

#ifndef SDL4CPP_MAIN_H
#define SDL4CPP_MAIN_H

#include "SDL.h"
#include <string>
#include <stdexcept>


/*!
 * \namespace SDL
 * \brief The namespace all classes and functions are put in.
 *
 * This is where everything is kept (not to mention the occational namespace
 * inside this one.) All SDL_ prefixes have been taken off of function names
 * when they were put inside of here. Most Structs that didn't need to be put
 * in classes also got their names shortened. The one main struct that kept
 * it's name was SDL_Surface because some work is allowed on the pointer, even
 * though I'd discourage it in most cases.
 */
namespace SDL
{
	/*!
	 * \defgroup General General
	 */
	//@{

	/*!
	 * \brief Simple structure containing version information
	 *
	 * This structure is returned by Linked_Version(). The user can then
	 * examine the fields of this structure to determine the version of SDL
	 * being linked to.
	 *
	 * \b Structure Definition
	 * \code
	 * typedef struct
	 * {
	 *	Uint8 major;
	 *	Uint8 minor;
	 *	Uint8 patch;
	 * } SDL_version;
	 * \endcode
	 *
	 * \b Structure Data
	 * \htmlonly
	 * <pre>
	 * major 	Major version number
	 * minor 	Minor version number
	 * patch 	Patch version number
	 * </pre>
	 * \endhtmlonly
	 */
	typedef SDL_version Version;
	/*!
	 * \brief Initializes SDL
	 *
	 * This should be called before all other SDL functions.
	 *
	 * \param flags specifies what part(s) of SDL to initialize.
	 * \code
	 * SDL_INIT_TIMER	Initializes the timer subsystem.
	 * SDL_INIT_AUDIO	Initializes the audio subsystem.
	 * SDL_INIT_VIDEO	Initializes the video subsystem.
	 * SDL_INIT_CDROM	Initializes the cdrom subsystem.
	 * SDL_INIT_JOYSTICK	Initializes the joystick subsystem.
	 * SDL_INIT_EVERYTHING	Initialize all of the above.
	 * SDL_INIT_NOPARACHUTE	Prevents SDL from catching fatal signals.
	 * SDL_INIT_EVENTTHREAD
	 * \endcode
	 *
	 * \return True on sucess, false on an error.
	 */
	bool Init(Uint32 flags);
	/*!
	 * \brief Initialize subsystems
	 *
	 * After SDL has been initialized with Init you may initialize
	 * uninitialized subsystems with InitSubSystem(). The flags parameter is
	 * the same as that used in Init().
	 *
	 *  \return True on sucess, false on an error.
	 */
	bool InitSubSystem(Uint32 flags);
	/*!
	 * \brief Shut down a subsystem
	 *
	 * QuitSubSystem() allows you to shut down a subsystem that has been
	 * previously initialized by Init() or InitSubSystem().
	 * The flags tells QuitSubSystem() which subsystems to shut down, it uses
	 * the same values that are passed to Init().
	 */
	void QuitSubSystem(Uint32 flags);
	/*!
	 * \brief Shut down SDL
	 *
	 * Quit() shuts down all SDL subsystems and frees the resources allocated
	 * to them. This should always be called before you exit. 
	 * For the sake of simplicity you can set Quit() as your atexit call, like:
	 * \code
	 * using namespace SDL;
	 * Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	 * atexit(Quit);
	 * \endcode
	 * \note While using atexit maybe be fine for small programs, more advanced
	 * users should shut down SDL in their own cleanup code. 
	 * Plus, using atexit in a library is a sure way to crash dynamically
	 * loaded code
	 */
	void Quit(void);
	/*!
	 * \brief Check which subsystems are initialized
	 *
	 * WasInit allows you to see which SDL subsytems have been initialized. 
	 * \param flags is a bitwise OR'd combination of the subsystems you wish to
	 * check (see Init() for a list of subsystem flags).
	 *
	 * \return A bitwised OR'd combination of the initialized subsystems.
	 */
	Uint32 WasInit(Uint32 flags);
	/*!
	 * \brief Get SDL error string
	 *
	 * \return A string containing the last error.
	 */
	std::string GetError(void);
	
	/*!
	 * \brief Clear the current SDL error
	 *
	 * ClearError() deletes all information about the last internal SDL error.
	 * Useful if the error has been handled by the program.
	 */
	void ClearError(void);
	/*!
	 * \brief Loads a shared object.
	 *
	 *This function dynamically loads a shared object. The sofile parameter is
	 * a system dependent name of the object file.
	 *
	 * \note These functions only work on C function names. Other languages may
	 * have name mangling and intrinsic language support that varies from
	 * compiler to compiler.
	 * \note Make sure you declare your function pointers with the same calling
	 * convention as the actual library function. Your code will crash
	 * mysteriously if you do not do this.
	 * \note Avoid namespace collisions. If you load a symbol from the library,
	 * it is not defined whether or not it goes into the global symbol
	 * namespace for the application. If it does and it conflicts with symbols
	 * in your code or other shared libraries, you will not get the results you
	 * expect.
	 *
	 * \return a pointer to the object handle, or NULL on error.
	 */
	void *LoadObject(const std::string sofile);
	/*!
	 * \brief Returns the address of a function in a loaded shared object.
	 *
	 * Given an object handle, this function looks up the address of the named
	 * function in the shared object and returns it. This address is no longer
	 * valid after calling UnloadObject().
	 *
	 * \note These functions only work on C function names. Other languages may
	 * have name mangling and intrinsic language support that varies from
	 * compiler to compiler.
	 * \note Make sure you declare your function pointers with the same calling
	 * convention as the actual library function. Your code will crash
	 * mysteriously if you do not do this.
	 * \note Avoid namespace collisions. If you load a symbol from the library,
	 * it is not defined whether or not it goes into the global symbol
	 * namespace for the application. If it does and it conflicts with symbols
	 * in your code or other shared libraries, you will not get the results you
	 * expect.
	 * \return the address of the function.
	 */
	void *LoadFunction(void *handle, const std::string name);
	/*!
	 * \brief Unload a shared object from memory.
	 *
	 * \note These functions only work on C function names. Other languages may
	 * have name mangling and intrinsic language support that varies from
	 * compiler to compiler.
	 * \note Make sure you declare your function pointers with the same calling
	 * convention as the actual library function. Your code will crash
	 * mysteriously if you do not do this.
	 * \note Avoid namespace collisions. If you load a symbol from the library,
	 * it is not defined whether or not it goes into the global symbol
	 * namespace for the application. If it does and it conflicts with symbols
	 * in your code or other shared libraries, you will not get the results you
	 * expect. 
	 *
	 */
	void UnloadObject(void *handle);
	/*!
	 * \brief Gets the version of the dynamically linked SDL library
	 *
	 * LinkedVersion gets the version of the current dynamically linked SDL
	 * library and returns a pointer to a Version structure containing the
	 * version information. 
	 *
	 * \return a constant pointer to an Version structure containing the
	 * version information.
	 */
	const Version *LinkedVersion(void);
	
	/*!
	 * \brief Runtime error handling class
	 * 
	 * This inherits the standard runtime_error class
	 */
	class RuntimeError : public std::runtime_error
	{
		public:
			/*!
			 * Takes a character string describing the error.
			 */
			explicit RuntimeError(const std::string &message);
			virtual ~RuntimeError() throw();
			
			/*!
			 * \brief What the exception was
			 * 
			 * \returns a C-style character string describing the general cause
			 * of the current error.
			 */
			virtual const char* what() const throw();
			
		private:
			std::string m_Message;
	};
	
	/*!
	 * \brief Logic error handling class
	 * 
	 * This inherits the standard logic_error class for convienence so you
	 * don't need to include stdexcept
	 */
	class LogicError : public std::logic_error
	{
		public:
		/*!
		 * Takes a character string describing the error.
		 */
			explicit LogicError(const std::string &message);
			virtual ~LogicError() throw();
			
			/*!
			 * \brief What the exception was
			 * 
			 * \returns a C-style character string describing the general cause
			 * of the current error.
			 */
			virtual const char* what() const throw();
			
		private:
			std::string m_Message;
	};
	//@}
}

#endif

