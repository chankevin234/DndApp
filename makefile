# COVID-19ABMGuelphS20
# 28/07/20
# ver 0.03
#
# Makefile for the COVID-19 eABM

SRCDIR = ./src/
BINDIR = ./bin/
INCDIR = ./include/

CC = g++
CFLAGS = -std=c++11 -Wall -I./include -I/opt/local/include -I/boost/boost_1_73_0

OBJECTS = $(BINDIR)main.o

all: $(BINDIR)dndBackend

$(BINDIR)dndBackend: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BINDIR)main.o: $(SRCDIR)main.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)main.cpp -o $@


run:
	$(BINDIR)dndBackend

clean:
	rm $(OBJECTS) $(BINDIR)abmSim