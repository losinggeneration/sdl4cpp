#ifndef SDL4CPP_H
#define SDL4CPP_H

#include "SDL.h"

#include "SDL4Cpp_main.h"
#include "SDL4Cpp_video.h"
#include "SDL4Cpp_wm.h"
#include "SDL4Cpp_events.h"
#include "SDL4Cpp_joystick.h"
#include "SDL4Cpp_mouse.h"
#include "SDL4Cpp_audio.h"
#include "SDL4Cpp_cdrom.h"
#include "SDL4Cpp_mt.h"
#include "SDL4Cpp_time.h"
/*!
 *  \mainpage SDL4Cpp documentation
 *
 *  \author Harley Laue
 *
 * \section FAQ
 * \b Q: Why another SDL->C++ Wrapper?/Why not just use/improve upon SDLmm? \n
 * \b A: I wanted to make my own. I originally didn't like how SDLmm handled some things (one of which, Event handling, I ended up liking after all and using the same method). Surfaces was another thing I didn't much care for in SDLmm. SDLmm isn't very complete and I don't believe it's actively worked on. Not to mention they put nearly everything in classes. That's my one gripe about languages like Java, pretty much everything is an object (even arrays... yuck.) It has it's advantages, but isn't always needed IMO. 
 *
 * \b Q: Why not just use SDL the way it is? \n
 * \b A: First, I think C++ allows code to be written cleaner in many cases. Second, I like not having to worry about memory usage. Many C programmers that use C++ will use many new's and deletes. While this dosn't normally hurt things, it can make code harder to manage down the road (unless it's well kept in classes that deal with the cleanup.) Also, if not done very carefully, memory leaks can be there. For these reasons, I wrap SDL into classes when I thought needed, and almost always used referances instead of pointers.
 *
 * Questions, Comments, Feature Requests (for now), Bug Reports (for now), etc. please send an email to losinggeneration@yahoo.com
 *
 */
#endif

