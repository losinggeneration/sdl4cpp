SUBDIRS = paddleball

INCLUDES = -I$(top_srcdir)/include `sdl-config --cflags`
noinst_PROGRAMS = TestVideo TestEvents TestWM TestMouse TestKeyboard TestJoystick TestCD TestGL 
#Transform (broken)
AM_CXXFLAGS = $(SDL4CPP_CFLAGS)

TestVideo_SOURCES = TestVideo.cpp
TestEvents_SOURCES = TestEvents.cpp
TestWM_SOURCES = TestWM.cpp
TestMouse_SOURCES = TestMouse.cpp
TestKeyboard_SOURCES = TestKeyboard.cpp
TestJoystick_SOURCES = TestJoystick.cpp
TestCD_SOURCES = TestCD.cpp
Transform_SOURCES = Transform.cpp
TestGL_SOURCES = TestGL.cpp

LOCAL_INCLUDE = -I$(top_srcdir)/include

TestVideo_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestEvents_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestWM_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestMouse_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestKeyboard_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestJoystick_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestCD_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
Transform_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)
TestGL_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)

TestVideo_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
TestEvents_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
TestWM_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
TestMouse_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
TestKeyboard_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
TestJoystick_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
TestCD_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
Transform_LDADD =  $(top_builddir)/src/libSDL4Cpp.la -lSDL -lSDL_image
TestGL_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL -lGL -lGLU

