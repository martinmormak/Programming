OUTPUT=ps4
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c bmp.c transformations.c


all: ps4 codeanalysis

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

ps4: main.o bmp.o transformations.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	echo "Building object file bmp.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
transformations.o: transformations.c
	echo "Building object file transformations.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
clean:
	rm -rf *o $(OUTPUT) bin/*
