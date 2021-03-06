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

#ifndef SDL4CPP_H
#define SDL4CPP_H

#include "SDL.h"

#include "SDL4Cpp_main.h"
#include "SDL4Cpp_video.h"
#include "SDL4Cpp_events.h"
#include "SDL4Cpp_joystick.h"
#include "SDL4Cpp_mouse.h"
#include "SDL4Cpp_audio.h"
#include "SDL4Cpp_cdrom.h"
#include "SDL4Cpp_mt.h"
#include "SDL4Cpp_time.h"
#include "SDL4Cpp_rwops.h"
#include "SDL4Cpp_wm.h"

/*!
 *  \mainpage SDL4Cpp documentation
 *
 *  \author Harley Laue
 *
 * \section FAQ
 * \b Q: Why another SDL->C++ Wrapper?/Why not just use/improve upon SDLmm? \n
 * \b A: I wanted to make my own, and because choice is a good thing. Don't
 * like how I wrapped SDL, use SDLmm instead. Don't like how SDLmm does
 * something, make your own or change what's out there.
 *
 * \b Q: Why not just use SDL the way it is? \n
 * \b A: First, I think C++ allows code to be written cleaner in many cases.
 * Second, I like not having to worry about memory usage. Many C programmers
 * that use C++ will use many new's and deletes. While this dosn't normally
 * hurt things, it can make code harder to manage down the road (unless it's
 * well kept in classes that deal with the cleanup.) Also, if not done very
 * carefully, memory leaks can be there. For these reasons, I wrap SDL into
 * classes when I thought needed, and almost always used referances instead of
 * pointers.
 *
 * Questions, Comments, Feature Requests (for now), Bug Reports (for now), etc.
 * please send an email to losinggeneration@yahoo.com
 *
 */
#endif

