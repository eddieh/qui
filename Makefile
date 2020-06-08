CC = gcc
LD = $(CC)
AR = ar

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
LIB_OBJS += qui.o
LIB_OBJS += app.o
LIB_OBJS += window.o
LIB_OBJS += view.o

TESTS :=
TESTS += test/list

all:

cflags = -fno-strict-aliasing
cflags += -Wall -Wwrite-strings
cflags += -I.

LIBS := libqui.a
OBJS := $(LIB_OBJS) $(EXTRA_OBJS) $(TESTS:%=%.o)

# Pretty print
V := @
Q := $(V:1=)

all: $(TESTS)

ldflags += $($(@)-ldflags) $(LDFLAGS)
ldlibs += $($(@)-ldlibs)  $(LDLIBS)
$(TESTS): % : %.o $(LIBS)
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
	@echo "  CLEAN"
	@rm -f *.[oa] .*.d test/*.o $(TESTS)
