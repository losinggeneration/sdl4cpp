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

#ifndef SDL4CPP_CDROM_H
#define SDL4CPP_CDROM_H

#include <string>
#include "SDL.h"

namespace SDL
{
	/*!
	 * \defgroup CD CD handling functions.
	 */
	//@{
	/*!
	 * \brief A shorter name for the SDL_CDtrack structure
	 * 
	 * CDtrack stores data on each track on a CD, its fields should be pretty self explainatory. It is a member a the CD class,
	 * and can be accessed via Gets.
	 *
	 * \b Variables: \n
	 * \e id	Track number (0-99) \n
	 * \e type	SDL_AUDIO_TRACK or SDL_DATA_TRACK \n
	 * \e length	Length, in frames, of this track \n
	 * \e offset	Frame offset to the beginning of this track \n
	 */
	typedef SDL_CDtrack CDtrack;

	/*!
	 * \brief Returns the number of CD-ROM drives on the system.
	 *
	 * \return The number of CD/DVD drives available
	 */
	int CDNumDrives(void);

	/*!
	 * \class CD
	 * \brief A class to do work on a CD drive (Play, Stop, Close, etc.)
	 *
	 * This is all the functions in SDL that have to do directly with SDL's CD handling.
	 */
	//@}
	class CD
	{
		public:
			/*!
			 * Constructor that sets up m_CD to NULL, and Open() must be called later
			 */
			CD();
			/*!
			 * Constructor that takes a drive as its argument to open it and set up m_CD for use
			 *
			 * \param drive is the drive number to load into this class
			 *
			 * \throws std::runtime_error if the cdrom is not opened
			 */
			CD(int drive);
			/*!
			 * Destructor that deals with freeing m_CD
			 */
			~CD();

			/*!
			 * \brief Opens a CD-ROM drive for access.
			 *
			 * Drives are numbered starting with 0. Drive 0 is the system default CD-ROM.
			 * \note This should be called before anything else if the default constructor is used.
			 *
			 * \return True if the cd drive is opened sucessfully, False if not.  
			 */
			bool Open(int drive);
			
			/*!
			 * \brief Get the current status of the given drive.
			 *
			 * This function returns the current status of the given drive. Status is described like so:
			 *
			 * \code
			 * typedef enum 
			 * {
			 *	CD_TRAYEMPTY,
			 *	CD_STOPPED,
			 *	CD_PLAYING,
			 *	CD_PAUSED,
			 *	CD_ERROR = -1
			 * } CDstatus;
			 * \endcode
			 * If the drive has a CD in it, the table of contents of the CD and current play position of the CD will be stored in m_CD.
			 *
			 * The macro CD_INDRIVE is provided for convenience, and given a status returns true if there's a disk in the drive.
			 *
			 * \throws std::logic_error if the CD is not initialized before this call
			 */
			CDstatus Status();
			
			/*!
			 * \brief Returns a human-readable, system-dependent identifier for the CD-ROM.
			 *
			 * Returns a human-readable, system-dependent identifier for the CD-ROM. drive is the index of the drive. Drive indices start to 0 and end at CDNumDrives()-1.
			 *
			 * \return A strinf of a human-readable, system-dependent identifier for the CD-ROM.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			std::string Name();

			/*!
			 * \brief Play a CD
			 *
			 * Plays the cdrom defined in Open(), starting a frame start for length frames.
			 *
			 * \param start is the first fram to play
			 * \param length is the amount of frames to play
			 *
			 * \return False an an error, otherwise True.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			bool Play(int start, int length);
			
			/*!
			 * \brief Play the given CD track(s)
			 *
			 * Plays the given CD starting at track start_track, for ntracks tracks.
			 *
			 * \param start_track is the first track to play
			 * \param start_frame is the frame offset, from the beginning of the start_track, at which to start. 
			 * \param ntracks is how many tracks to play
			 * \param nframes is the frame offset, from the beginning of the last track (start_track+ntracks), at which to end playing.
			 *
			 * CDPlayTracks() should only be called after calling Status() to get track information about the CD.
			 *
			 * \note Data tracks are ignored.
			 * 
			 * \return False on an error, otherwise True.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			bool PlayTracks(int start_track, int start_frame, int ntracks, int nframes);
			
			/*!
			 * \brief Get the current track information
			 *
			 * \return CDTrack structure with the current tracks information
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			CDtrack GetCurrentTrack();
			
			/*!
			 * \brief Get all tracks information
			 *
			 * \return an array of CDTrack(s) that the CD has
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			CDtrack *GetTracks();
			
			/*!
			 * \brief Pauses a CDROM
			 *
			 * Pauses play on the cdrom.
			 *
			 * \return False on an error, otherwise True.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			bool Pause();
			
			/*!
			 * \brief Resumes a CDROM
			 *
			 * Resumes play on the cdrom.
			 *
			 * \return False on an error, otherwise True.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			bool Resume();
			
			/*!
			 * \brief Stops a CDROM
			 *
			 * Stops play on the cdrom.
			 *
			 * \return False on an error, otherwise True.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			bool Stop();
			
			/*!
			 * \brief Ejects a CDROM
			 *
			 * Ejects the cdrom.
			 * 
			 * \return False on an error, otherwise True.
			 *
			 * \throws std::logic_error if this CD is not initialized before this call
			 */
			bool Eject();
			
			/*!
			 * \brief Closes a CD
			 *
			 * Closes the cdrom.
			 */
			void Close();
		protected:
			/*!
			 * \brief A cdrom drive and information
			 * 
			 * \b Structure \b Definition
			 * \code
			 * typedef struct
			 * {
			 *	int id;
			 *	CDstatus status;
			 *	int numtracks;
			 *	int cur_track;
			 *	int cur_frame;
			 *	SDL_CDtrack track[SDL_MAX_TRACKS+1];
			 * } SDL_CD;
			 * \endcode
			 * \b Variables: \n
			 * \htmlonly
			 * <pre>
			 * id				Private drive identifier
			 * status				Drive status
			 * numtracks			Number of tracks on the CD
			 * cur_track			Current track
			 * cur_frame			Current frame offset within the track
			 * track[SDL_MAX_TRACKS+1]	Array of track descriptions. (see SDL_CDtrack)
			 * </pre>
			 * \endhtmlonly
			 */
			SDL_CD *m_CD;
			/*!
			 * \brief Keeps which drive this class is using.
			 *
			 * m_Drive is used to store the drive that the class is currently working with
			 */
			int m_Drive;

	};

}

#endif

