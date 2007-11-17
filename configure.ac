AC_INIT([SDL4Cpp], 1.2.0, [losinggeneration@yahoo.com])
AM_CONFIG_HEADER(include/SDL4Cpp-config.h)

AC_CANONICAL_HOST
AC_CANONICAL_TARGET

#AC_LIBTOOL_WIN32_DLL

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_PROG_CPP
SDL4CPP_CFLAGS=""

AC_ARG_ENABLE(warnings,[  --enable-warnings       Use -Wall and -Werror compile flags (with gcc)], [
		SDL4CPP_CFLAGS="$SDL4CPP_CFLAGS -Wall -Werror"
], [])

AC_ARG_ENABLE(debug,
	AC_HELP_STRING([--enable-debug], [Tune on -Wall, -Werror, -O0, -g3 (for gcc) [default=no]]), [ SDL4CPP_CFLAGS="$SDL4CPP_CFLAGS -Wall -Werror -g3 -O0" ],
	[])

AC_ARG_ENABLE(optimize,
	AC_HELP_STRING([--enable-optimize], [Tune on -Wall, -Werror, -O3, -g0 (for gcc)[default=no]]), [ SDL4CPP_CFLAGS="$SDL4CPP_CFLAGS -Wall -Werror -g0 -O3" ],
	use_optimize="no")

AM_CONDITIONAL(HAVE_SDL, false)
AM_CONDITIONAL(HAVE_SDLIMAGE, false)
AM_CONDITIONAL(HAVE_SDLMIXER, false)

AC_LANG_C
# Check for SDL
SDL_VERSION=1.2.9
AM_PATH_SDL($SDL_VERSION, :,
	AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!]))
LIBSDL_CFLAGS="$SDL_CFLAGS"
LIBSDL_LIBS="$SDL_LIBS"

AM_CONDITIONAL(HAVE_SDL, true)
AC_DEFINE_UNQUOTED(HAVE_LIBSDL, 1, [Defines if your system has the LIBSDL library])

AC_ARG_ENABLE(sdlimage,
	AC_HELP_STRING([--enable-sdlimage],[Enable SDL_image for drawing graphics [default=no]]),,
   	enable_sdlimage=no)

if test x$enable_sdlimage = xyes; then		
	AC_DEFINE_UNQUOTED(HAVE_SDLIMAGE, 1, [Include SDL_image])
	AM_CONDITIONAL(HAVE_SDLIMAGE, true)

	AC_CHECK_LIB(SDL_image, IMG_Load, SDLIMAGE_LIBS="-lSDL_image", AC_MSG_ERROR([Cannot find SDL_image which is needed to compile]), )
fi

AC_ARG_ENABLE(sdlmixer,
 	AC_HELP_STRING([--enable-sdlmixer],[Enable SDL_mixer for sound [default=no]]),,
   	enable_sdlmixer=no)

if test x$enable_sdlmixer = xyes; then			
	AC_DEFINE_UNQUOTED(HAVE_SDLMIXER, 1, [Include SDL_mixer])
	AM_CONDITIONAL(HAVE_SDLMIXER, true)

	AC_CHECK_LIB(SDL_mixer, Mix_Playing, SDLMIXER_LIBS="-lSDL_mixer",  AC_MSG_ERROR([Cannot find SDL_mixer which is needed to compile]), )
fi

SDL4CPP_CFLAGS="$SDL4CPP_CFLAGS $LIBSDL_CFLAGS"
SDL4CPP_LIBS="$LIBSDL_LIBS $SDLMIXER_LIBS $SDLIMAGE_LIBS"

AC_SUBST(SDL4CPP_CFLAGS)
AC_SUBST(SDL4CPP_LIBS)

AC_PROG_LIBTOOL

AC_OUTPUT([	Makefile
		src/Makefile
		tests/Makefile
		tests/paddleball/Makefile
		docs/Makefile
		docs/SDL4Cpp.doxy
		include/Makefile
	])

echo
echo "$PACKAGE version $VERSION"
echo
echo "Is going to be built using the following...."
echo "SDL_image ................ $enable_sdlimage"
echo "SDL_mixer ................ $enable_sdlmixer"
echo
echo "Now either change the variables as needed or make and pray ;-)"

