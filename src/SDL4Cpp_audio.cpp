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

#include "SDL4Cpp_audio.h"

namespace SDL
{
	namespace Audio
	{
		int OpenAudio(AudioSpec *desired, AudioSpec *obtained)
		{
			return SDL_OpenAudio(desired, obtained);
		}

		void PauseAudio(int pause_on)
		{
			SDL_PauseAudio(pause_on);
		}

		AudioStatus GetAudioStatus(void)
		{
			return SDL_GetAudioStatus();
		}

		AudioSpec *LoadWAV(const std::string file, AudioSpec *spec, Uint8 **audio_buf, Uint32 *audio_len)
		{
			return SDL_LoadWAV(file.c_str(), spec, audio_buf, audio_len);
		}

		void FreeWAV(Uint8 *audio_buf)
		{
			SDL_FreeWAV(audio_buf);
		}

		int BuildAudioCVT(AudioCVT *cvt, Uint16 src_format, Uint8 src_channels, int src_rate, Uint16 dst_format, Uint8 dst_channels, int dst_rate)
		{
			return SDL_BuildAudioCVT(cvt, src_format, src_channels, src_rate, dst_format, dst_channels, dst_rate);
		}

		int ConvertAudio(AudioCVT *cvt)
		{
			return SDL_ConvertAudio(cvt);
		}

		void MixAudio(Uint8 *dst, Uint8 *src, Uint32 len, int volume)
		{
			SDL_MixAudio(dst, src, len, volume);
		}

		void LockAudio(void)
		{
			SDL_LockAudio();
		}

		void UnlockAudio(void)
		{
			SDL_UnlockAudio();
		}

		void CloseAudio(void)
		{
			SDL_CloseAudio();
		}
	}
}

