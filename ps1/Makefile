OUTPUT=ps1
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c bmp.c playfair.c


all: ps1

code analysis: $(SOURCES)
	cppcheck --enable=unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o bmp.o playfair.o
	echo "Running compilation"
	cppcheck --enable=warning,performance,unusedFunction --error-exitcode=1 bmp.c playfair.c main.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	echo "Building object file bmp.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

playfair.o: playfair.c
	echo "Building object file playfair.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

test: bmp.o tests/tests_bmp_encrypt.c tests/tests_bmp_decrypt.c
	$(CC) $(CFLAGS) bmp.o tests/tests_bmp_encrypt.c $(LDLIBS) -o bin/test_encrypt
	$(CC) $(CFLAGS) bmp.o tests/tests_bmp_decrypt.c $(LDLIBS) -o bin/test_decrypt
	./bin/test_encrypt
	./bin/test_decrypt

clean:
	rm -rf *o $(OUTPUT) bin/*

push:
	git commit -a
	git push

