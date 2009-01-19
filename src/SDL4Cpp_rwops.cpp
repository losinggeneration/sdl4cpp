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

#include "SDL4Cpp_main.h"
#include "SDL4Cpp_rwops.h"

namespace SDL
{
	RWops::RWops() : m_RWops(NULL)
	{
	}

	RWops::RWops(const std::string file, const std::string mode) : m_RWops(NULL)
	{
		if(!FromFile(file, mode))
			throw RuntimeError("RWOps(const std::string file, const std::string mode) failed to load file");
	}

	RWops::RWops(const RWops &copy) : m_RWops(NULL)
	{
		// XXX TODO RWops Copy constructor
	}

	RWops::~RWops()
	{
		Free();
	}

	RWops &RWops::operator =(const RWops &copy)
	{
		// XXX TODO RWops equals operator
	}

	bool RWops::FromFile(const std::string file, const std::string mode)
	{
		if(m_RWops)
			Free();

		m_RWops = SDL_RWFromFile(file.c_str(), mode.c_str());

		if(!m_RWops)
			return false;

		return true;}

	#ifdef HAVE_STDIO_H
	bool RWops::FromFP(FILE *fp, int autoclose)
	{
		if(m_RWops)
			Free();

		m_RWops = SDL_RWFromFP(fp, autoclose);

		if(!m_RWops)
			return false;

		return true;}
	#endif

	bool RWops::FromMem(void *mem, int size)
	{
		if(m_RWops)
			Free();

		m_RWops = SDL_RWFromMem(mem, size);

		if(!m_RWops)
			return false;

		return true;}

	bool RWops::FromConstMem(const void *mem, int size)
	{
		if(m_RWops)
			Free();

		m_RWops = SDL_RWFromConstMem(mem, size);

		if(!m_RWops)
			return false;

		return true;}

	bool RWops::Alloc(void)
	{
		if(m_RWops)
			Free();

		m_RWops = SDL_AllocRW();

		if(!m_RWops)
			return false;

		return true;
	}

	void RWops::Free()
	{
		if(m_RWops)
		{
			SDL_FreeRW(m_RWops);
			m_RWops = NULL;
		}
	}

	int RWops::seek(int offset, int whence)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling seek(int offset, int whence)");

		return SDL_RWseek(m_RWops, offset, whence);
	}

	int RWops::tell()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling tell()");

		return SDL_RWtell(m_RWops);
	}

	int RWops::read(void *ptr, int size, int blocks)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling read(void *ptr, int size, int blocks)");

		return SDL_RWread(m_RWops, ptr, size, blocks);
	}

	int RWops::write(void *ptr, int size, int blocks)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling write(void *ptr, int size, int blocks)");

		return SDL_RWwrite(m_RWops, ptr, size, blocks);
	}

	bool RWops::close()
	{
		if(SDL_RWclose(m_RWops) == 0)
			return true;

		return false;
	}

	Uint16 RWops::ReadLE16()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling ReadLE16()");

		return SDL_ReadLE16(m_RWops);
	}

	Uint16 RWops::ReadBE16()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling ReadBE16()");

		return SDL_ReadBE16(m_RWops);
	}

	Uint32 RWops::ReadLE32()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling ReadLE32()");

		return SDL_ReadLE32(m_RWops);
	}

	Uint32 RWops::ReadBE32()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling ReadBE32()");

		return SDL_ReadBE32(m_RWops);
	}

	Uint64 RWops::ReadLE64()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling ReadLE64()");

		return SDL_ReadLE64(m_RWops);
	}

	Uint64 RWops::ReadBE64()
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling ReadBE64()");

		return SDL_ReadBE64(m_RWops);
	}

	int RWops::WriteLE16(Uint16 value)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling WriteLE16(Uint16 value)");

		return SDL_WriteLE16(m_RWops, value);
	}

	int RWops::WriteBE16(Uint16 value)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling WriteBE16(Uint16 value)");

		return SDL_WriteBE16(m_RWops, value);
	}

	int RWops::WriteLE32(Uint32 value)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling WriteLE32(Uint32 value))");

		return SDL_WriteLE32(m_RWops, value);
	}

	int RWops::WriteBE32(Uint32 value)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling WriteBE32(Uint32 value))");

		return SDL_WriteBE32(m_RWops, value);
	}

	int RWops::WriteLE64(Uint64 value)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling WriteLE64(Uint64 value)");

		return SDL_WriteLE64(m_RWops, value);
	}

	int RWops::WriteBE64(Uint64 value)
	{
		if(m_RWops == NULL)
			throw LogicError("m_RWops must be inialized before calling WriteBE64(Uint64 value)");

		return SDL_WriteBE64(m_RWops, value);
	}

	SDL_RWops *RWops::Get()
	{
		return m_RWops;
	}
}

