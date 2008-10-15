# Source files
set(SOURCES
	SDL4Cpp_audio.cpp
	SDL4Cpp_cdrom.cpp
	SDL4Cpp_events.cpp
	SDL4Cpp_joystick.cpp
	SDL4Cpp_main.cpp
	SDL4Cpp_mouse.cpp
	SDL4Cpp_mt.cpp
	SDL4Cpp_rwops.cpp
	SDL4Cpp_time.cpp
	SDL4Cpp_video.cpp
	SDL4Cpp_wm.cpp)

# Headers (only needed for them to show up in project files
set(INC "${CMAKE_SOURCE_DIR}/include/SDL4Cpp")
set(HEADERS
	${INC}/SDL4Cpp_audio.h
	${INC}/SDL4Cpp_cdrom.h
	${INC}/SDL4Cpp_events.h
	${INC}/SDL4Cpp_joystick.h
	${INC}/SDL4Cpp_main.h
	${INC}/SDL4Cpp_mouse.h
	${INC}/SDL4Cpp_mt.h
	${INC}/SDL4Cpp_rwops.h
	${INC}/SDL4Cpp_time.h
	${INC}/SDL4Cpp_video.h
	${INC}/SDL4Cpp_wm.h)

# Sources, headers, and properties needed for SDL_mixer
if(ENABLE_MIXER)
	set(SOURCES
		${SOURCES}
		mixer/SDL4Cpp_mixer.cpp)
	set(HEADERS
		${HEADERS}
		../include/SDL4Cpp/mixer/SDL4Cpp_mixer.h)
	set(MIXER_FLAGS "-I${SDLMIXER_INCLUDE_DIR} -I${INC}/mixer")
	set(MIXER_LINK "${SDLMIXER_LIBRARY}")
endif(ENABLE_MIXER)

# Sources, headers, and properties needed for SDL_image
if(ENABLE_IMAGE)
	set(SOURCES
		${SOURCES}
		image/SDL4Cpp_image.cpp)
	set(HEADERS
		${HEADERS}
		../include/SDL4Cpp/image/SDL4Cpp_image.h)
	set(IMAGE_FLAGS "-I${SDLIMAGE_INCLUDE_DIR} -I${INC}/image")
	set(IMAGE_LINK "${SDLIMAGE_LIBRARY}")
endif(ENABLE_IMAGE)

link_libraries(${SDL_LIBRARY} ${MIXER_LINK} ${IMAGE_LINK})
add_library(SDL4Cpp SHARED ${SOURCES} ${HEADERS})

# Set the compiler/linker flags
set_property(TARGET SDL4Cpp APPEND PROPERTY COMPILE_FLAGS "-I${INC} -I${SDL_INCLUDE_DIR} ${MIXER_FLAGS} ${IMAGE_FLAGS}")
set_property(TARGET SDL4Cpp PROPERTY VERSION "1.2.0")

install(TARGETS SDL4Cpp LIBRARY DESTINATION ${LIB_INSTALL_DIR})

