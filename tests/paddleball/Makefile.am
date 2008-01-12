INCLUDES = -I$(top_srcdir)/include

AM_CXXFLAGS = $(SDL4CPP_CFLAGS)

noinst_PROGRAMS = paddleball

paddleball_SOURCES = ball.cpp paddle.cpp main.cpp score.cpp computer.cpp

paddleball_CXXFLAGS = \
	`sdl-config \
	--cflags`

paddleball_LDFLAGS = $(all_libraries) $(LOCAL_INCLUDE)

paddleball_LDADD = $(top_builddir)/src/libSDL4Cpp.la -lSDL
