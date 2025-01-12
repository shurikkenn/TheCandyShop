CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =

all: candyshop

candyshop: core/main.o core/libs/lib.o
	$(CC) $(LDFLAGS) -o candyshop core/main.o core/libs/lib.o

core/main.o: core/main.c core/libs/lib.h
	$(CC) $(CFLAGS) -c core/main.c -o core/main.o

core/libs/lib.o: core/libs/lib.c core/libs/lib.h
	$(CC) $(CFLAGS) -c core/libs/lib.c -o core/libs/lib.o

clean:
	rm -f core/*.o candyshop
