CFLAGS=-c -Wall -O0
LIBS= -lm

all: cs1

cs1: main.o
	$(CC) main.o $(LIBS) -o cs2

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *o cs2

