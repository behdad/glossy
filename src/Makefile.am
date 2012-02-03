NULL =
EXTRA_DIST =
CLEANFILES =
DISTCLEANFILES =
MAINTAINERCLEANFILES =
BUILT_SOURCES =

PUBLICHEADERS = \
	glossy-common.hh \
	glossy-sl.hh \
	glossy-sl-metatypes.hh \
	glossy-sl-metatypes-swizzle.hh \
	$(NULL)

pkginclude_HEADERS = \
	$(PUBLICHEADERS) \
	$(NULL)


BUILT_SOURCES += glossy-sl-metatypes-swizzle.hh
EXTRA_DIST += \
	glossy-sl-metatypes-swizzle.hh \
	swizzle.py \
	$(NULL)
glossy-sl-metatypes-swizzle.hh: swizzle.py
	$(AM_V_GEN)\
	./"$^" > "$@.tmp" && mv "$@.tmp" "$@" \
	|| ($(RM) "$@.tmp"; false)

check_PROGRAMS = test
TESTS = test

test_SOURCES = \
	$(PUBLICHEADERS) \
	test.cc \
	$(NULL)
test_CXXFLAGS = -I"$(srcdir)"

-include $(top_srcdir)/git.mk
