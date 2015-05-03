CC = g++
CFLAGS += -g
CFLAGS += -Wall
INSTALL = install
PREFIX := /usr/bin

.PHONY: all parser parser2 clean install uninstall

all: parser parser2

address.o:  address.cpp
	$(CC) $(CFLAGS) -c $^

binary2.o: binary2.cpp
	$(CC) $(CFLAGS) -c $^

cycle.o:  cycle.cpp
	$(CC) $(CFLAGS) -c $^

output.o:  output.cpp
	$(CC) $(CFLAGS) -c $^

parser.o:  parser.cpp
	$(CC) $(CFLAGS) -c $^

parser2.o:  parser2.cpp
	$(CC) $(CFLAGS) -c $^

reorder.o:  reorder.cpp
	$(CC) $(CFLAGS) -c $^

table.o:  table.cpp
	$(CC) $(CFLAGS) -c $^

parser:  address.o binary2.o cycle.o output.o table.o reorder.o parser.o
	$(CC) $(CFLAGS) -o $@ $^

parser2:  address.o binary2.o cycle.o output.o table.o reorder.o parser2.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) parser *.o *~

install: all
	$(INSTALL) -d $(DESTDIR)$(PREFIX)
	$(INSTALL) -m 755 parser $(DESTDIR)$(PREFIX)/parser

uninstall:
	$(RM) $(DESTDIR)$(PREFIX)/parser
