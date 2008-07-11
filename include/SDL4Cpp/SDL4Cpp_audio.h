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

#ifndef SDL4CPP_AUDIO_H
#define SDL4CPP_AUDIO_H

#include "SDL_audio.h"
#include <string>

namespace SDL
{
	/*!
	 * \defgroup Audio Audio handling.
	 */
	//@{
	/*!
	 *  \brief SDL Audio will most likely not be wrapped into a class
	 *
	 * Because of many C-isms that the audio portion of SDL uses makes it hard
	 * to cleanly wrap it into a class. I will work on this if I get enough
	 * emails wanting this. If not, use SDL_mixer.
	 *
	 * Sound on the computer is translated from waves that you hear into a
	 * series of values, or samples, each representing the amplitude of the
	 * wave. When these samples are sent in a stream to a sound card, an
	 * approximation of the original wave can be recreated. The more bits used
	 * to represent the amplitude, and the greater frequency these samples are
	 * gathered, the closer the approximated sound is to the original, and the
	 * better the quality of sound.
	 *
	 * This library supports both 8 and 16 bit signed and unsigned sound
	 * samples, at frequencies ranging from 11025 Hz to 44100 Hz, depending on
	 * the underlying hardware. If the hardware doesn't support the desired
	 * audio format or frequency, it can be emulated if desired
	 *
	 * \sa OpenAudio()
	 *
	 * A commonly supported audio format is 16 bits per sample at 22050 Hz.
	*/
	namespace Audio
	{
		/*!
		 * \brief Audio Specification Structure
		 *
		 * \b Structure \b Definition
		 * \code
		 * typedef struct
		 * {
		 *	int freq;	// Audio frequency in samples per second
		 *	Uint16 format;	// Audio data format
		 *	Uint8 channels;	// Number of channels: 1 mono, 2 stereo
		 *	Uint8 silence;	// Audio buffer silence value (calculated)
		 *	Uint16 samples;	// Audio buffer size in samples
		 *	Uint32 size;	// Audio buffer size in bytes (calculated)
		 *	void (*callback)(void *userdata, Uint8 *stream, int len);	// Callback function for filling the audio buffer
		 *	void *userdata;	// Pointer the user data which is passed to the callback function
		 * } AudioSpec;
		 * \endcode
		 *
		 * The AudioSpec structure is used to describe the format of some audio data. This structure is used by OpenAudio and LoadWAV. While all fields are used by OpenAudio only freq, format, samples and channels are used by LoadWAV. We will detail these common members here.
		 *
		 * \param freq	The number of samples sent to the sound device every second. Common values are 11025, 22050 and 44100. The higher the better.
		 * \param format	Specifies the size and type of each sample element
		 * \code
		 * AUDIO_U8			Unsigned 8-bit samples
		 * AUDIO_S8			Signed 8-bit samples
		 * AUDIO_U16 or AUDIO_U16LSB	Unsigned 16-bit little-endian samples
		 * AUDIO_S16 or AUDIO_S16LSB	Signed 16-bit little-endian samples
		 * AUDIO_U16MSB			Unsigned 16-bit big-endian samples
		 * AUDIO_S16MSB			Signed 16-bit big-endian samples
		 * AUDIO_U16SYS			Either AUDIO_U16LSB or AUDIO_U16MSB depending on you systems endianness
		 * AUDIO_S16SYS			Either AUDIO_S16LSB or AUDIO_S16MSB depending on you systems endianness
		 * \endcode
		 * \param channels	The number of seperate sound channels. 1 is mono (single channel), 2 is stereo (dual channel).
		 * \param samples	When used with OpenAudio this refers to the size of the audio buffer in samples. A sample a chunk of audio data of the size specified in format mulitplied by the number of channels. When the AudioSpec is used with LoadWAV samples is set to 4096.
		 *
		 * \sa OpenAudio, LoadWAV
		 */
		typedef SDL_AudioSpec AudioSpec;
		/*!
		 * \brief Audio Conversion Structure
		 *
		 * \b Structure \b Definition
		 * \code
		 * typedef struct
		 * {
		 *	int needed;		// Set to one if the conversion is possible
		 *	Uint16 src_format;	// Audio format of the source
		 *	Uint16 dest_format;	// Audio format of the destination
		 *	double rate_incr;	// Rate conversion increment
		 *	Uint8 *buf;		// Audio buffer
		 *	int len;		// Length of the original audio buffer in bytes
		 *	int len_cvt;		// Length of converted audio buffer in bytes (calculated)
		 *	int len_mult;		// buf must be len*len_mult bytes in size(calculated)
		 *	double len_ratio;	// Final audio size is len*len_ratio
		 *	void (*filters[10])(struct AudioCVT *cvt, Uint16 format);	// Pointers to functions needed for this conversion
		 *	int filter_index;	// Current conversion function
		 * } AudioCVT;
		 * \endcode
		 *
		 * The AudioCVT is used to convert audio data between different formats. A AudioCVT structure is created with the BuildAudioCVT
		 * function, while the actual conversion is done by the ConvertAudio
		 * function.
		 *
		 * Many of the fields in the AudioCVT structure should be considered
		 * private and their function will not be discussed here.
		 *
		 * \param *buf  This points to the audio data that will be used in the
		 * conversion. It is both the source and the destination, which means
		 * the converted audio data overwrites the original data. It also means
		 * that the converted data may be larger than the original data (if you
		 * were converting from 8-bit to 16-bit, for instance), so you must
		 * ensure buf is large enough. See below.
		 * \param len This is the length of the original audio data in bytes.
		 * \param len_mult As explained above, the audio buffer needs to be big
		 * enough to store the converted data, which may be bigger than the
		 * original audio data. The length of buf should be len*len_mult.
		 * \param len_ratio When you have finished converting your audio data,
		 * you need to know how much of your audio buffer is valid.
		 * len*len_ratio is the size of the converted audio data in bytes. This
		 * is very similar to len_mult, however when the convert audio data is
		 * shorter than the original len_mult would be 1. len_ratio, on the
		 * other hand, would be a fractional number between 0 and 1.
		 *
		 * \sa BuildAudioCVT, ConvertAudio, AudioSpec
		 */
		typedef SDL_AudioCVT AudioCVT;
		/*!
		 * \brief Audio Status Structure
		 *
		 * \b Structure \b Definition
		 * \code
		 * typedef enum
		 * {
		 *	SDL_AUDIO_STOPPED,
		 *	SDL_AUDIO_PAUSED,
		 *	SDL_AUDIO_PLAYING
		 * } SDL_audiostatus;
		 * \endcode
		 */
		typedef SDL_audiostatus AudioStatus;

		/*!
		 * \brief Opens the audio device with the desired parameters.
		 *
		 * This function opens the audio device with the desired parameters,
		 * and returns 0 if successful, placing the actual hardware parameters
		 * in the structure pointed to by obtained. If obtained is NULL, the
		 * audio data passed to the callback function will be guaranteed to be
		 * in the requested format, and will be automatically converted to the
		 * hardware audio format if necessary. This function returns -1 if it
		 * failed to open the audio device, or couldn't set up the audio thread.
		 *
		 * To open the audio device a desired AudioSpec must be created.
		 * \code
		 * AudioSpec *desired;
		 * .
		 * .
		 * desired=(AudioSpec *)malloc(sizeof(AudioSpec));
		 * \endcode
		 * You must then fill this structure with your desired audio
		 * specifications.
		 *
		 * \e desired->freq The desired audio frequency in samples-per-second.
		 *
		 * \e desired->format The desired audio format (see AudioSpec)
		 *
		 * \e desired->samples The desired size of the audio buffer in samples.
		 * This number should be a power of two, and may be adjusted by the
		 * audio driver to a value more suitable for the hardware. Good values
		 * seem to range between 512 and 8192 inclusive, depending on the
		 * application and CPU speed. Smaller values yield faster response
		 * time, but can lead to underflow if the application is doing heavy
		 * processing and cannot fill the audio buffer in time. A stereo sample
		 * consists of both right and left channels in LR ordering. Note that
		 * the number of samples is directly related to time by the following
		 * formula: ms = (samples*1000)/freq
		 *
		 * \e desired->callback This should be set to a function that will be
		 * called when the audio device is ready for more data. It is passed a
		 * pointer to the audio buffer, and the length in bytes of the audio
		 * buffer. This function usually runs in a separate thread, and so you
		 * should protect data structures that it accesses by calling LockAudio
		 * and UnlockAudio in your code. The callback prototype is:
		 *
		 * \e void \e callback(void \e *userdata, \e Uint8 \e *stream, \e int \e len);
		 * userdata is the pointer stored in userdata field of the AudioSpec.
		 * stream is a pointer to the audio buffer you want to fill with
		 * information and len is the length of the audio buffer in bytes.
		 *
		 * \e desired->userdata This pointer is passed as the first parameter
		 * to the callback function.
		 *
		 * OpenAudio reads these fields from the desired AudioSpec structure
		 * pass to the function and attempts to find an audio configuration
		 * matching your desired. As mentioned above, if the obtained parameter
		 * is NULL then SDL with convert from your desired audio settings to
		 * the hardware settings as it plays.
		 *
		 * If obtained is NULL then the desired AudioSpec is your working
		 * specification, otherwise the obtained AudioSpec becomes the working
		 * specification and the desirec specification can be deleted. The data
		 * in the working specification is used when building AudioCVT's for
		 * converting loaded data to the hardware format.
		 *
		 * OpenAudio calculates the size and silence fields for both the
		 * desired and obtained specifications. The size field stores the total
		 * size of the audio buffer in bytes, while the silence stores the
		 * value used to represent silence in the audio buffer
		 *
		 * The audio device starts out playing silence when it's opened, and
		 * should be enabled for playing by calling PauseAudio(0) when you are
		 * ready for your audio callback function to be called. Since the audio
		 * driver may modify the requested size of the audio buffer, you should
		 * allocate any local mixing buffers after you open the audio device.
		 *
		 * \b Example
		 * \code
		 * // Prototype of our callback function
		 * void my_audio_callback(void *userdata, Uint8 *stream, int len);
		 *
		 * // Open the audio device
		 * AudioSpec *desired, *obtained;
		 * AudioSpec *hardware_spec;
		 *
		 * // Allocate a desired AudioSpec
		 * desired=(AudioSpec *)malloc(sizeof(AudioSpec));
		 *
		 * // Allocate space for the obtained AudioSpec
		 * obtained=(AudioSpec *)malloc(sizeof(AudioSpec));
		 *
		 * // 22050Hz - FM Radio quality
		 * desired->freq=22050;
		 *
		 * // 16-bit signed audio
		 * desired->format=AUDIO_S16LSB;
		 *
		 * // Large audio buffer reduces risk of dropouts but increases
		 * response time
		 * desired->samples=8192;
		 *
		 * // Our callback function
		 * desired->callback=my_audio_callback;
		 *
		 * desired->userdata=NULL;
		 *
		 * // Open the audio device
		 * if(OpenAudio(desired, obtained) < 0)
		 * {
		 *	fprintf(stderr, "Couldn't open audio: %s\n", GetError());
		 *	exit(-1);
		 * }
		 *
		 * // desired spec is no longer needed
		 * free(desired);
		 * hardware_spec=obtained;
		 * .
		 * .
		 * // Prepare callback for playing
		 * .
		 * .
		 * .
		 * // Start playing
		 * PauseAudio(0);
		 * \endcode
		 * \sa AudioSpec, LockAudio, UnlockAudio, PauseAudio
		 */
		int OpenAudio(AudioSpec *desired, AudioSpec *obtained);
		/*!
		 * \brief Pauses and unpauses the audio callback processing
		 *
		 * This function pauses and unpauses the audio callback processing. It
		 * should be called with pause_on=0 after opening the audio device to
		 * start playing sound. This is so you can safely initialize data for
		 * your callback function after opening the audio device. Silence will
		 * be written to the audio device during the pause.
		 * \sa GetAudioStatus, OpenAudio
		 *
		 */
		void PauseAudio(int pause_on);
		/*!
		 * \brief Get the current audio state
		 *
		 * \return either SDL_AUDIO_STOPPED, SDL_AUDIO_PAUSED or
		 * SDL_AUDIO_PLAYING depending on the current audio state.
		 * \sa PauseAudio
		 */
		AudioStatus GetAudioStatus(void);
		/*!
		 * \brief Load a WAVE file
		 *
		 * LoadWAV This function loads a WAVE file into memory.
		 *
		 * If this function succeeds, it returns the given AudioSpec, filled
		 * with the audio data format of the wave data, and sets audio_buf to a
		 * malloc'd buffer containing the audio data, and sets audio_len to the
		 * length of that audio buffer, in bytes. You need to free the audio
		 * buffer with FreeWAV when you are done with it.
		 *
		 * This function returns NULL and sets the SDL error message if the
		 * wave file cannot be opened, uses an unknown data format, or is
		 * corrupt. Currently raw, MS-ADPCM and IMA-ADPCM WAVE files are
		 * supported.
		 * Example
		 * \code
		 * AudioSpec wav_spec;
		 * Uint32 wav_length;
		 * Uint8 *wav_buffer;
		 *
		 * // Load the WAV
		 *
		 * if(LoadWAV("test.wav", &wav_spec, &wav_buffer, &wav_length) == NULL)
		 * {
		 *	fprintf(stderr, "Could not open test.wav: %s\n", GetError());
		 *	exit(-1);
		 * }
		 *
		 * .
		 * .
		 * .
		 * // Do stuff with the WAV
		 * .
		 * .
		 * // Free It
		 * FreeWAV(wav_buffer);
		 * \endcode
		 *
		 * \sa AudioSpec, OpenAudio, FreeWAV
		 */
		AudioSpec *LoadWAV(std::string file, AudioSpec *spec,
						   Uint8 **audio_buf, Uint32 *audio_len);
		/*!
		 * \brief Frees previously opened WAV data
		 *
		 * After a WAVE file has been opened with LoadWAV its data can
		 * eventually be freed with FreeWAV. audio_buf is a pointer to the
		 * buffer created by LoadWAV.
		 *
		 * \sa LoadWAV
		 */
		void FreeWAV(Uint8 *audio_buf);
		/*!
		 * \brief Initializes a AudioCVT structure for conversion
		 *
		 * Before an AudioCVT structure can be used to convert audio data it
		 * must be initialized with source and destination information.
		 *
		 * src_format and dst_format are the source and destination format of
		 * the conversion. (For information on audio formats see AudioSpec).
		 * src_channels and dst_channels are the number of channels in the
		 * source and destination formats. Finally, src_rate and dst_rate are
		 * the frequency or samples-per-second of the source and destination
		 * formats. Once again, see AudioSpec.
		 *
		 * \return -1 if the filter could not be built or 1 if it could.
		 *
		 * \sa ConvertAudio, AudioCVT
		 */
		int BuildAudioCVT(AudioCVT *cvt, Uint16 src_format, Uint8 src_channels,
						  int src_rate, Uint16 dst_format, Uint8 dst_channels,
						  int dst_rate);
		/*!
		 * \brief Convert audio data to a desired audio format.
		 *
		 * ConvertAudio takes one parameter, cvt, which was previously
		 * initilized. Initilizing a AudioCVT is a two step process. First of
		 * all, the structure must be passed to BuildAudioCVT along with source
		 * and destination format parameters. Secondly, the cvt->buf and
		 * cvt->len fields must be setup. cvt->buf should point to the audio
		 * data and cvt->len should be set to the length of the audio data in
		 * bytes. Remember, the length of the buffer pointed to by buf show be
		 * len*len_mult bytes in length.
		 *
		 * Once the AudioCVTstructure is initilized then we can pass it to
		 * ConvertAudio, which will convert the audio data pointer to by
		 * cvt->buf. If ConvertAudio returned 0 then the conversion was
		 * completed successfully, otherwise -1 is returned.
		 *
		 * If the conversion completed successfully then the converted audio
		 * data can be read from cvt->buf. The amount of valid, converted,
		 * audio data in the buffer is equal to cvt->len*cvt->len_ratio.
		 * \b Example
		 * \code
		 * // Converting some WAV data to hardware format
		 * void my_audio_callback(void *userdata, Uint8 *stream, int len);
		 *
		 * AudioSpec *desired, *obtained;
		 * AudioSpec wav_spec;
		 * AudioCVT  wav_cvt;
		 * Uint32 wav_len;
		 * Uint8 *wav_buf;
		 * int ret;
		 *
		 * // Allocated audio specs
		 * desired=(AudioSpec *)malloc(sizeof(AudioSpec));
		 * obtained=(AudioSpec *)malloc(sizeof(AudioSpec));
		 *
		 * // Set desired format
		 * desired->freq=22050;
		 * desired->format=AUDIO_S16LSB;
		 * desired->samples=8192;
		 * desired->callback=my_audio_callback;
		 * desired->userdata=NULL;
		 *
		 * // Open the audio device
		 * if(OpenAudio(desired, obtained) < 0)
		 * {
		 *	fprintf(stderr, "Couldn't open audio: %s\n", GetError());
		 *	exit(-1);
		 * }
		 *
		 * free(desired);
		 *
		 * // Load the test.wav
		 * if(LoadWAV("test.wav", &wav_spec, &wav_buf, &wav_len) == NULL)
		 * {
		 *	fprintf(stderr, "Could not open test.wav: %s\n", GetError());
		 *	CloseAudio();
		 *	free(obtained);
		 *	exit(-1);
		 * }
		 *
		 * // Build AudioCVT
		 * ret = BuildAudioCVT(&wav_cvt,
		 *                wav_spec.format, wav_spec.channels, wav_spec.freq,
		 *                obtained->format, obtained->channels, obtained->freq);
		 *
		 * // Check that the convert was built
		 * if(ret==-1)
		 * {
		 *	fprintf(stderr, "Couldn't build converter!\n");
		 *	CloseAudio();
		 *	free(obtained);
		 *	FreeWAV(wav_buf);
		 * }
		 *
		 * // Setup for conversion
		 * wav_cvt.buf=(Uint8 *)malloc(wav_len*wav_cvt.len_mult);
		 * wav_cvt.len=wav_len;
		 * memcpy(wav_cvt.buf, wav_buf, wav_len);
		 *
		 * // We can delete to original WAV data now
		 * FreeWAV(wav_buf);
		 *
		 * // And now we're ready to convert
		 * ConvertAudio(&wav_cvt);
		 *
		 * // do whatever
		 * .
		 * .
		 * .
		 * .
		 * \endcode
		 *
		 * \sa BuildAudioCVT, AudioCVT
		 */
		int ConvertAudio(AudioCVT *cvt);
		/*!
		 * \brief Mix audio data
		 *
		 * This function takes two audio buffers of len bytes each of the
		 * playing audio format and mixes them, performing addition, volume
		 * adjustment, and overflow clipping. The volume ranges from 0 to
		 * SDL_MIX_MAXVOLUME and should be set to the maximum value for full
		 * audio volume. Note this does not change hardware volume. This is
		 * provided for convenience -- you can mix your own audio data.
		 *
		 * \sa OpenAudio
		 */
		void MixAudio(Uint8 *dst, Uint8 *src, Uint32 len, int volume);
		/*!
		 * \brief Lock out the callback function
		 *
		 * The lock manipulated by these functions protects the callback
		 * function. During a LockAudio period, you can be guaranteed that the
		 * callback function is not running. Do not call these from the
		 * callback function or you will cause deadlock.
		 *
		 * \sa OpenAudio
		 */
		void LockAudio(void);
		/*!
		 * \brief Unlock the callback function
		 *
		 * Unlocks a previous LockAudio call.
		 *
		 * \sa OpenAudio
		 */
		void UnlockAudio(void);
		/*!
		 * \brief Shuts down audio processing and closes the audio device.
		 *
		 * \sa OpenAudio
		 */
		void CloseAudio(void);
	}
	//@}
}

#endif

