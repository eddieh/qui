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
LIB_OBJS := platform.o
LIB_OBJS += main.o
LIB_OBJS += QUIApplication.o
LIB_OBJS += QUIContentView.o
LIB_OBJS += app.o
LIB_OBJS += window.o
LIB_OBJS += context.o
LIB_OBJS += font.o
LIB_OBJS += path.o

TESTS :=

all:

cflags = -fno-strict-aliasing
cflags += -Wall -Wwrite-strings
cflags += -I. -I../../include -I../../src

LIBS := libqui-mac-cocoa.a
OBJS := $(LIB_OBJS) $(EXTRA_OBJS) $(TESTS:%=%.o)

# Pretty print
V := @
Q := $(V:1=)

all: $(LIBS) $(TESTS)

ldflags += $($(@)-ldflags) $(LDFLAGS)
ldlibs += $($(@)-ldlibs)  $(LDLIBS)
$(TESTS): % : %.o $(LIBS)
	@echo "  LD      $@"
	$(Q)$(LD) $(ldflags) $^ $(ldlibs) -o $@

libqui-mac-cocoa.a: $(LIB_OBJS)
	@echo "  AR      $@"
	$(Q)$(AR) rcs $@ $^


cflags += $($(*)-cflags) $(CPPFLAGS) $(CFLAGS)
%.o: %.m
	@echo "  CC      $@"
	$(Q)$(CC) $(cflags) -c -o $@ $<

clean:
	@echo "  CLEAN platform/mac-cocoa"
	@rm -f *.[oa] .*.d test/*.o $(TESTS)
