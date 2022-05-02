OUTPUT=ps5
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c backpack.c command.c container.c game.c item.c parser.c room.c world.c


all: ps5 codeanalysis

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

ps5: main.o backpack.o command.o container.o game.o item.o parser.o room.o world.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@

backpack.o: backpack.c
	echo "Building object file backpack.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
command.o: command.c
	echo "Building object file command.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
container.o: container.c
	echo "Building object file container.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
game.o: game.c
	echo "Building object file game.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
item.o: item.c
	echo "Building object file item.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
parser.o: parser.c
	echo "Building object file parser.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
room.o: room.c
	echo "Building object file room.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
world.o: world.c
	echo "Building object file world.o"
	$(CC) $(CFLAGS) -c -Wconversion $^ $(LDLIBS) -o $@
	
clean:
	rm -rf *o $(OUTPUT) bin/*
