OUTPUT=mm isolation racer cheesefactory
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=mm.c isolation.c racer.c cheesefactory.c


all: mm isolation racer cheesefactory codeanalysis

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

mm: mm.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

mm.o: mm.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
isolation: isolation.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

isolation.o: isolation.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
racer: racer.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

racer.o: racer.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
cheesefactory: cheesefactory.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

cheesefactory.o: cheesefactory.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
clean:
	rm -rf *o $(OUTPUT) bin/*
