#Makefile for program hello
#

program := constellation.exe

sources := $(wildcard *.c)
headers := $(wildcard *.h)

objects := $(sources:.c=.o)
deps    := $(sources:.c=.d)

CC      := gcc
SHARED  := -shared
FPIC    := -fPIC
CFLAGS  := 
LDFLAGS := 

RM      := rm -f
TAR     := tar
GZIP    := gzip

me      := Makefile

all:    $(program)

$(program):  $(objects)
		$(CC) -o $@ $(CFLAGS) $(objects) $(LDFLAGS) $(LDLIBS)

dist:
		pkg=`pwd`; tar cvf - $(me) $(sources) $(headers) \
                | $(GZIP) -c > `basename $${pkg}`.tar.gz
clean:
		$(RM) $(objects)
		$(RM) $(deps)
		$(RM) $(program)

.SUFFIXES: .d
.c.d:
		$(CC) $(CPPFLAGS) -MM -MF $@ $<

-include $(deps)
