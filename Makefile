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

LIB_OBJS :=
LIB_OBJS += util.o
LIB_OBJS += list.o
LIB_OBJS += rect.o
LIB_OBJS += color.o
LIB_OBJS += qui.o
LIB_OBJS += app.o
LIB_OBJS += window.o
LIB_OBJS += view.o

TESTS :=
TESTS += test/list

EXAMPLES :=
EXAMPLES += example/basic
EXAMPLES += example/window
EXAMPLES += example/window-color
EXAMPLES += example/window-frame
EXAMPLES += example/window-resizable
EXAMPLES += example/draw
EXAMPLES += example/text
EXAMPLES += example/button

PROGRAMS :=
PROGRAMS += $(TESTS) $(EXAMPLES)

MODULES :=

PLATFORM_PATH ?=

all:

cflags = -fno-strict-aliasing
cflags += -Wall -Wwrite-strings
cflags += -I.

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

clean:
	@for dir in $(MODULES); do ${MAKE} clean -C $$dir; exit_status=$$?; \
	if [ $$exit_status -ne 0 ]; then exit $$exit_status; fi; done
	@echo "  CLEAN"
	@rm -f *.[oa] .*.d $(PROGRAMS)
	@rm -f test/*.[oa] example/*.[oa]

.PHONY: submodules clean
