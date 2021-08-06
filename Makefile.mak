CC     = gcc
WINDRES= windres
RM     = rm -f
OBJS   = main.o \
         AppResource.res

LIBS   =
CFLAGS =

.PHONY: bin/Release/projeto\ biblioteca.exe clean clean-after

all: bin/Release/projeto\ biblioteca.exe

clean:
	$(RM) $(OBJS) bin/Release/projeto\ biblioteca.exe

clean-after:
	$(RM) $(OBJS)

bin/Release/projeto\ biblioteca.exe: $(OBJS)
	$(CC) -Wall -s -O2 -o '$@' $(OBJS) $(LIBS)

main.o: main.c lista.h
	$(CC) -Wall -s -O2 -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

