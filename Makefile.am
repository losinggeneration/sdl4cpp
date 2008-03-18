SUBDIRS = src \
	include 
DIST_SUBDIRS = $(SUBDIRS) docs tests

EXTRA_DIST = sdl4cpp.pc

uninstall-local:
	rm -r $(DESTDIR)$(includedir)/SDL4Cpp
	rm -f $(DESTDIR)$(libdir)/pkgconfig/sdl4cpp.pc

install-exec-local:
	mkdir -p $(DESTDIR)$(libdir)/pkgconfig
	cp $(top_srcdir)/sdl4cpp.pc $(DESTDIR)$(libdir)/pkgconfig
