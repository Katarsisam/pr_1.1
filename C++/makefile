CC = g++
CFLAGS = -Wall -Wextra -std=c++17
LIBS = -lcheck
all : lib.a test

lib.a:
	$(CC) $(CFLAGS) -c -g lib_SUBD.cpp lib_JSON.cpp utils.cpp
	ar rc lib.a *.o
	ranlib lib.a
	rm -rf *.o

test: lib.a
	$(CC) $(CFLAGS) -g *.cpp lib.a $(LIBS) -o _test
	./_test

clean:
	rm -f *.o *.a 
	rm -rf _test