OUTPUT=ps2
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c k.c hof.c ui.c


all: ps2 codeanalysis

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 k.c hof.c main.c ui.c

$(OUTPUT): main.o k.o hof.o ui.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@

k.o: k.c
	echo "Building object file bmp.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@

hof.o: hof.c
	echo "Building object file playfair.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@

ui.o: ui.c
	echo "Building object file playfair.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@

clean:
	rm -rf *o $(OUTPUT) bin/*
