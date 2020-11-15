# This Makefile requires GNU make

CC = g++
# Add -msse4.2 to enable SSE instrusctions up to SSE4.2.
# We use optimization level 1 to avoid automatic vectorization with both GCC
# and Clang. GCC versions 4 and 5 will do automatic vectorization only at
# optimization level 3. Clang apparently will do it at level 2 or 3.
CFLAGS =  -O3  -msse4.2 -mavx -march=native
ASFLAGS = -g


DIST_FILES =  \
    main.cpp \
    Makefile

all: main

main: main.cpp
	$(CC) $(CFLAGS) -fprofile-generate=. -o euler $^
	./euler 1500000 > /dev/null
	$(CC) $(CFLAGS) -fprofile-use=. -o euler $^





clean:
	rm -f *.o
