CC = g++
CFLAGS += -g
CFLAGS += -Wall
INSTALL = install
PREFIX := /usr/bin

.PHONY: all parser clean install uninstall

all: parser

address.o:  address.cpp
	$(CC) $(CFLAGS) -c $^

cycle.o:  cycle.cpp
	$(CC) $(CFLAGS) -c $^

output.o:  output.cpp
	$(CC) $(CFLAGS) -c $^

parser.o:  parser.cpp
	$(CC) $(CFLAGS) -c $^

parser:  address.o cycle.o output.o parser.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) parser *.o *~

install: all
	$(INSTALL) -d $(DESTDIR)$(PREFIX)
	$(INSTALL) -m 755 parser $(DESTDIR)$(PREFIX)/parser

uninstall:
	$(RM) $(DESTDIR)$(PREFIX)/parser
