SRCDIR = ./src/
BINDIR = ./bin/
INCDIR = ./include/

CC = g++
CFLAGS = -std=c++11 -Wall -I./include

OBJECTS = $(BINDIR)main.o $(BINDIR)classInfo.o $(BINDIR)condition.o $(BINDIR)race.o $(BINDIR)weapon.o

all: $(BINDIR)dndBackend

$(BINDIR)dndBackend: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BINDIR)main.o: $(SRCDIR)main.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)main.cpp -o $@

$(BINDIR)classInfo.o: $(SRCDIR)classInfo.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)classInfo.cpp -o $@

$(BINDIR)condition.o: $(SRCDIR)condition.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)condition.cpp -o $@

$(BINDIR)race.o: $(SRCDIR)race.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)race.cpp -o $@

$(BINDIR)weapon.o: $(SRCDIR)weapon.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)weapon.cpp -o $@


run:
	$(BINDIR)dndBackend

clean:
	rm $(OBJECTS) $(BINDIR)dndBackend