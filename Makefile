all: ttygraph

CC=gcc

LIBS=-lncurses -lm
CFLAGS=``

FLAGS=-O2 -pipe -s
DEBUGFLAGS=-Og -pipe -g

INPUT=tinyexpr.c ttygraph.c
OUTPUT=ttygraph

INSTALLDIR=$(HOME)/.local/bin

RM=`which rm`

ttygraph:
	$(CC) $(INPUT) -o $(OUTPUT) $(LIBS) $(CFLAGS) $(FLAGS)

debug:
	$(CC) $(INPUT) -o $(OUTPUT) $(LIBS) $(CFLAGS) $(DEBUGFLAGS)

install:
	test -d $(INSTALLDIR) || mkdir -p $(INSTALLDIR)
	install -pm 755 $(OUTPUT) $(INSTALLDIR)

clean:
	if [ -e $(OUTPUT) ]; then $(RM) $(OUTPUT); fi
