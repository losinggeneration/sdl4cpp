INCLUDES = -I$(top_srcdir)/include

lib_LTLIBRARIES = libSDL4Cpp.la

AM_CXXFLAGS = $(SDL4CPP_CFLAGS)

libSDL4Cpp_la_SOURCES = SDL4Cpp_audio.cpp \
	SDL4Cpp_cdrom.cpp \
	SDL4Cpp_events.cpp \
	SDL4Cpp_joystick.cpp \
	SDL4Cpp_main.cpp \
	SDL4Cpp_mt.cpp \
	SDL4Cpp_time.cpp \
	SDL4Cpp_video.cpp \
	SDL4Cpp_wm.cpp \
	SDL4Cpp_mouse.cpp	       

libSDL4Cppincludedir = $(includedir)/SDL4Cpp

include_HEADERS = $(top_srcdir)/include/SDL4Cpp_audio.h \
	$(top_srcdir)/include/SDL4Cpp_cdrom.h \
	$(top_srcdir)/include/SDL4Cpp_events.h \
	$(top_srcdir)/include/SDL4Cpp_joystick.h \
	$(top_srcdir)/include/SDL4Cpp_main.h \
	$(top_srcdir)/include/SDL4Cpp_mt.h \
	$(top_srcdir)/include/SDL4Cpp_time.h \
	$(top_srcdir)/include/SDL4Cpp_video.h \
	$(top_srcdir)/include/SDL4Cpp_wm.h \
	$(top_srcdir)/include/SDL4Cpp_mouse.h \
	$(top_builddir)/include/SDL4Cpp-config.h

if HAVE_SDLIMAGE
lib_LTLIBRARIES += libSDL4Cpp_image.la
libSDL4Cpp_image_la_SOURCES = image/SDL4Cpp_image.cpp
INCLUDES += -I$(top_srcdir)/include/image
include_HEADERS += $(top_srcdir)/include/image/SDL4Cpp_image.h
endif

if HAVE_SDLMIXER
lib_LTLIBRARIES += libSDL4Cpp_mixer.la
libSDL4Cpp_mixer_la_SOURCES = mixer/SDL4Cpp_mixer.cpp
INCLUDES += -I$(top_srcdir)/include/mixer
include_HEADERS += $(top_srcdir)/include/mixer/SDL4Cpp_mixer.h
endif


