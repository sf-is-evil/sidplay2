# The library.

EXTRA_DIST = hardsid-win.cpp

lib_LTLIBRARIES = libhardsid-builder.la

libhardsid_builder_la_SOURCES = hardsid-unix.cpp hardsid-emu.cpp \
hardsid-stream.cpp hardsid-builder.cpp \
hardsid-builder.h hardsid-stream.h hardsid-emu.h
libhardsid_builder_la_LIBADD  = -lhwsid

# We substitute the libtool-specific library version in configure.in.
libhardsid_builder_la_LDFLAGS = -version-info $(LIBVERSION)
# libhardsid_builder_la_LDFLAGS = -module -avoid-version

# Remove bad default includes
DEFAULT_INCLUDES=
