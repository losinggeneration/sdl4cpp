cmake_minimum_required(VERSION 2.6)
project(SDL4Cpp)
set(VERSION "1.2.0")

option(ENABLE_DOXYGEN "Enable building of documentation" off)
option(GENERATE_DOCS "Build documentation on every build" off)
option(ENABLE_TESTS "Build test programs" off)
option(ENABLE_MIXER "Build with SDL_mixer support" off)
option(ENABLE_IMAGE "Build with SDL_image support" off)

# Rather than doing this via pkg-config I'm going to hope this is more cross
# platform
#include(FindSDL)
Find_Package(SDL REQUIRED)
if(NOT SDL_FOUND)
	message(SEND_ERROR "SDL not found")
endif(NOT SDL_FOUND)

if(ENABLE_MIXER)
	Find_Package(SDL_mixer REQUIRED)
	if(NOT SDLMIXER_FOUND)
		message(SEND_ERROR "SDL_mixer not found")
	endif(NOT SDLMIXER_FOUND)
endif(ENABLE_MIXER)

if(ENABLE_IMAGE)
	Find_Package(SDL_image REQUIRED)
	if(NOT SDLIMAGE_FOUND)
		message(SEND_ERROR "SDL_image not found")
	endif(NOT SDLIMAGE_FOUND)
endif(ENABLE_IMAGE)

# Pretty much taken from KDE/kdesupport/phonon
# Used for sdl4cpp.pc which is a pkg-config file for those who don't know
set(LIB_SUFFIX "" CACHE STRING "Define suffix of directory name (32/64)" )
set(EXEC_INSTALL_PREFIX
	"${CMAKE_INSTALL_PREFIX}" CACHE STRING
	"Base directory for executables and libraries")
set(SHARE_INSTALL_PREFIX
	"${CMAKE_INSTALL_PREFIX}/share" CACHE STRING
	"Base directory for files which go to share/")
set(BIN_INSTALL_DIR
	"${EXEC_INSTALL_PREFIX}/bin" CACHE STRING
	"The install dir for executables (default ${EXEC_INSTALL_PREFIX}/bin)")
set(LIB_INSTALL_DIR
	"${EXEC_INSTALL_PREFIX}/lib${LIB_SUFFIX}" CACHE STRING
	"The subdirectory relative to the install prefix where libraries will be
	installed (default is ${EXEC_INSTALL_PREFIX}/lib${LIB_SUFFIX})")
set(INCLUDE_INSTALL_DIR
	"${CMAKE_INSTALL_PREFIX}/include" CACHE STRING
	"The subdirectory to the header prefix")

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/sdl4cpp.pc.in"
  "${CMAKE_CURRENT_BINARY_DIR}/sdl4cpp.pc"
  IMMEDIATE @ONLY)

install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/sdl4cpp.pc

	DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pkgconfig)

set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)
add_subdirectory(include)
