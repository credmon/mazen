CC=gcc
CFLAGS=-Wall
STRIP=strip
STRIP_FLAGS=
INCLUDES=
LIBS=-lcurses
EXES=mazen
OBJS=main.o tty.o signals.o init.o movement.o weapons.o mazes.o ai.o

all: $(EXES)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c
	
mazen: $(OBJS)
	chmod ugo-x *.c
	chmod ugo-x *.h
	$(CC) -o mazen $(OBJS) $(LIBS)
	$(STRIP) $(STRIP_FLAGS) mazen

clean:
	rm -f core a.out $(EXES) *.o *.core
	chmod ugo-x *.c
	chmod ugo-x *.h
