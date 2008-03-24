INCLUDES = -I$(top_srcdir)/include/SDL4Cpp

lib_LTLIBRARIES = libSDL4Cpp.la

AM_CXXFLAGS = $(SDL4CPP_CFLAGS)

libSDL4Cpp_la_SOURCES = SDL4Cpp_audio.cpp \
	SDL4Cpp_cdrom.cpp \
	SDL4Cpp_events.cpp \
	SDL4Cpp_joystick.cpp \
	SDL4Cpp_main.cpp \
	SDL4Cpp_mt.cpp \
	SDL4Cpp_time.cpp \
	SDL4Cpp_rwops.cpp \
	SDL4Cpp_video.cpp \
	SDL4Cpp_wm.cpp \
	SDL4Cpp_mouse.cpp

libSDL4Cppincludedir = $(includedir)/SDL4Cpp

if HAVE_SDLIMAGE
lib_LTLIBRARIES += libSDL4Cpp_image.la
libSDL4Cpp_image_la_SOURCES = image/SDL4Cpp_image.cpp
INCLUDES += -I$(top_srcdir)/include/SDL4Cpp/image
endif

if HAVE_SDLMIXER
lib_LTLIBRARIES += libSDL4Cpp_mixer.la
libSDL4Cpp_mixer_la_SOURCES = mixer/SDL4Cpp_mixer.cpp
INCLUDES += -I$(top_srcdir)/include/SDL4Cpp/mixer
endif

