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

#include <stdexcept>
#include "SDL4Cpp_main.h"
#include "SDL4Cpp_cdrom.h"

namespace SDL
{
	int CDNumDrives(void)
	{
		return SDL_CDNumDrives();
	}

	CD::CD()
	{
		m_CD = NULL;
		m_Drive = -1;
	}

	CD::CD(int drive)
	{
		if(!Open(drive))
			throw SDL::RuntimeError(GetError());

		m_Drive = drive;
	}

	CD::~CD()
	{
		Close();
	}

	bool CD::Open(int drive)
	{
		// Sanity check before assigning to a boost ptr
		m_CD = SDL_CDOpen(drive);
		if(!m_CD)
			return false;

		m_Drive = drive;

		return true;
	}

	std::string CD::Name()
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Name()");

		return static_cast<std::string>(SDL_CDName(m_Drive));
	}

	CDstatus CD::Status()
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Status()");

		return SDL_CDStatus(m_CD);
	}

	bool CD::Play(int start, int length)
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Play(int, int)");

		if(SDL_CDPlay(m_CD, start, length) == 0)
			return true;

		return false;
	}

	bool CD::PlayTracks(int start_track, int start_frame, int ntracks, int nframes)
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::PlayTracks(int, int,  int, int)");

		if(SDL_CDPlayTracks(m_CD, start_track, start_frame, ntracks, nframes) == 0)
			return true;

		return false;
	}
	CDtrack CD::GetCurrentTrack()
	{
		return m_CD->track[m_CD->cur_track];
	}

	CDtrack *CD::GetTracks()
	{
		return m_CD->track;
	}

	bool CD::Pause()
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Pause()");

		if(SDL_CDPause(m_CD) == 0)
			return true;

		return false;
	}

	bool CD::Resume()
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Resume()");

		if(SDL_CDResume(m_CD))
			return true;

		return false;
	}

	bool CD::Stop()
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Stop()");

		if(SDL_CDStop(m_CD)== 0)
			return true;

		return false;
	}

	bool CD::Eject()
	{
		if(!m_CD)
			throw SDL::LogicError("m_CD not initialized before call to CD::Eject();");

		if(SDL_CDEject(m_CD) == 0)
			return true;

		return false;
	}

	void CD::Close()
	{
		if(m_CD)
			SDL_CDClose(m_CD);

		m_Drive = -1;
	}
}

