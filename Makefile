#CC = cc
#LD = $(CC)
#AR = ar

CFLAGS ?= -O2 -g

DESTDIR ?=

# Allow users to override build settings without dirtying their trees
# For debugging, put this in local.mk:
#
#     CFLAGS += -O0 -DDEBUG -g3 -gdwarf-2
#
DFRAME_LOCAL_CONFIG ?= local.mk
-include ${DFRAME_LOCAL_CONFIG}

SRCROOT = .
ABS_SRCROOT := $(shell cd $(SRCROOT) && pwd)
srctree := $(ABS_SRCROOT)

LIB_OBJS :=
LIB_OBJS += src/util.o
LIB_OBJS += src/list.o
LIB_OBJS += src/rect.o
LIB_OBJS += src/color.o
LIB_OBJS += src/qui.o
LIB_OBJS += src/event.o
LIB_OBJS += src/app.o
LIB_OBJS += src/window.o
LIB_OBJS += src/view.o
LIB_OBJS += src/button.o

TESTS :=
TESTS += test/list

EXAMPLES :=
EXAMPLES += example/window
EXAMPLES += example/window-color
EXAMPLES += example/window-frame
EXAMPLES += example/window-resizable
EXAMPLES += example/draw
EXAMPLES += example/text
EXAMPLES += example/button
EXAMPLES += example/subview
EXAMPLES += example/window-event

PROGRAMS :=
PROGRAMS += $(TESTS) $(EXAMPLES)

MODULES :=

PLATFORM_PATH ?=

export srctree

all:

cflags = -fno-strict-aliasing
cflags += -Wall -Wwrite-strings
cflags += -Iinclude

OSNAME := $(shell uname)
ifeq ($(OSNAME),Darwin)
PLATFORM_PATH = platform/mac-cocoa
ldflags += -framework Cocoa
ldflags += -lSystem
ldflags += -L$(PLATFORM_PATH)
LIBS += $(PLATFORM_PATH)/libqui-mac-cocoa.a
MODULES += $(PLATFORM_PATH)
else
$(error Your OS is not supported yet)
endif

LIBS += libqui.a
OBJS := $(LIB_OBJS) $(EXTRA_OBJS) $(PROGRAMS:%=%.o)

# Pretty print
V := @
Q := $(V:1=)

all: submodules $(PROGRAMS)

submodules:
	@for dir in $(MODULES); do ${MAKE} all -C $$dir; exit_status=$$?; \
	if [ $$exit_status -ne 0 ]; then exit $$exit_status; fi; done

ldflags += $($(@)-ldflags) $(LDFLAGS)
ldlibs += $($(@)-ldlibs)  $(LDLIBS)
$(PROGRAMS): % : %.o $(LIBS)
	@echo "  LD      $@"
	$(Q)$(LD) $(ldflags) $^ $(ldlibs) -o $@

libqui.a: $(LIB_OBJS)
	@echo "  AR      $@"
	$(Q)$(AR) rcs $@ $^


cflags += $($(*)-cflags) $(CPPFLAGS) $(CFLAGS)
%.o: %.c
	@echo "  CC      $@"
	$(Q)$(CC) $(cflags) -c -o $@ $<

tags TAGS t: FORCE
	scripts/tags

clean:
	@for dir in $(MODULES); do ${MAKE} clean -C $$dir; exit_status=$$?; \
	if [ $$exit_status -ne 0 ]; then exit $$exit_status; fi; done
	@echo "  CLEAN"
	@rm -f src/*.[oa] $(PROGRAMS)
	@rm -f test/*.[oa] example/*.[oa]

.PHONY: submodules clean FORCE
