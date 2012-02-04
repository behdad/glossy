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
	glossy-sl-metatypes-ctors.hh \
	glossy-sl-metatypes-swizzle.hh \
	$(NULL)

pkginclude_HEADERS = \
	$(PUBLICHEADERS) \
	$(NULL)


BUILT_SOURCES += \
	glossy-sl-metatypes-ctors.hh \
	glossy-sl-metatypes-swizzle.hh \
	$(NULL)
EXTRA_DIST += $(BUILT_SOURCES)
EXTRA_DIST += \
	ctors.py \
	swizzle.py \
	$(NULL)

RUN_PY = \
	$(AM_V_GEN)\
	./"$^" > "$@.tmp" && mv "$@.tmp" "$@" \
	|| ($(RM) "$@.tmp"; false)
glossy-sl-metatypes-ctors.hh: ctors.py
	$(RUN_PY)
glossy-sl-metatypes-swizzle.hh: swizzle.py
	$(RUN_PY)

check_PROGRAMS = test
TESTS = test

test_SOURCES = \
	$(PUBLICHEADERS) \
	test.cc \
	$(NULL)
test_CXXFLAGS = -I"$(srcdir)"

-include $(top_srcdir)/git.mk
